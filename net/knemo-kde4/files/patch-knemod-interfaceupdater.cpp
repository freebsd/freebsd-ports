--- knemod/interfaceupdater.cpp.orig	Fri Aug 20 20:26:41 2004
+++ knemod/interfaceupdater.cpp	Sat Jan 22 13:34:49 2005
@@ -17,6 +17,24 @@
    Boston, MA 02111-1307, USA.
 */
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>
+#include <sys/ioctl.h>
+#include <net/ethernet.h>
+#include <net/if_media.h>
+#include <net/if_types.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <net/if_mib.h>
+#include <netdb.h>
+#include <ifaddrs.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#endif
+
 #include <qmap.h>
 #include <qtimer.h>
 #include <qregexp.h>
@@ -48,6 +66,7 @@
     mTimer->stop();
     delete mTimer;
 
+#ifndef Q_OS_FREEBSD
     if ( mRouteProcess )
     {
         mRouteProcess->kill();
@@ -63,10 +82,12 @@
         mIwconfigProcess->kill();
         delete mIwconfigProcess;
     }
+#endif
 }
 
 void InterfaceUpdater::checkConfig()
 {
+#ifndef Q_OS_FREEBSD    
     if ( !mIfconfigProcess )
     {
         mIfconfigStdout = QString::null;
@@ -108,6 +129,7 @@
         }
     }
 #endif
+#endif // Q_OS_FREEBSD
 
 #ifdef PATH_ROUTE
     if ( !mRouteProcess )
@@ -116,7 +138,11 @@
         mRouteProcess = new KProcess();
         mRouteProcess->setEnvironment( "LANG", "C" );
         mRouteProcess->setEnvironment( "LC_ALL", "C" );
+#ifdef Q_OS_FREEBSD        
+        *mRouteProcess << PATH_ROUTE << "-n" << "get" << "default";
+#else
         *mRouteProcess << PATH_ROUTE << "-n";
+#endif
         connect( mRouteProcess,  SIGNAL( receivedStdout( KProcess*, char*, int ) ),
                  this, SLOT( routeProcessStdout( KProcess*, char*, int ) ) );
         connect( mRouteProcess,  SIGNAL( receivedStderr( KProcess*, char*, int ) ),
@@ -131,6 +157,140 @@
         }
     }
 #endif
+
+#ifdef Q_OS_FREEBSD
+    // Check interfaces and update accordingly
+
+    Interface* interface = 0;
+    InterfaceData* data = 0;
+    
+    struct if_data* ifd;
+    struct ifaddrs *ifap;
+    char buf[NI_MAXHOST];
+
+    // Reset all devices first
+    QDictIterator<Interface> ifIt( mInterfaceDict );
+    for ( ; ifIt.current(); ++ifIt )
+    {
+        interface = ifIt.current();
+        interface->getData().existing = false;
+        interface->getData().available = false;
+        interface->getData().addrData.clear();
+    }
+   
+    // Get IP address and related information
+    if ( getifaddrs(&ifap) == 0 ) {
+        for ( ifaddrs *ifa = ifap; ifa; ifa = ifa->ifa_next ) {
+            switch ( ifa->ifa_addr->sa_family ) {
+                case AF_INET6:
+                case AF_INET:
+                    interface = mInterfaceDict[QString::fromLatin1(ifa->ifa_name)];
+                    if ( interface ) {
+                        data = &interface->getData();
+                     
+                        bzero(buf, NI_MAXHOST);
+                        getnameinfo(ifa->ifa_addr, ifa->ifa_addr->sa_len, buf, sizeof(buf), 0, 0, NI_NUMERICHOST);
+                        AddrData *addrData = new AddrData;
+                        data->addrData.insert( QString::fromLatin1(buf), addrData);
+
+                        if ( ifa->ifa_netmask != NULL ) {
+                            if (ifa->ifa_addr->sa_family == AF_INET6 ) {
+                                bzero(buf, NI_MAXHOST);
+                                getnameinfo(ifa->ifa_netmask, ifa->ifa_netmask->sa_len, buf, sizeof(buf), 0, 0, NI_NUMERICHOST);
+                                addrData->subnetMask = QString::fromLatin1( buf );
+                            } else {
+                                struct sockaddr_in *sin = (struct sockaddr_in *)ifa->ifa_netmask;
+                                addrData->subnetMask = QString::fromLatin1( inet_ntoa(sin->sin_addr) );
+                            }
+                        }
+
+                        if ( ifa->ifa_broadaddr != NULL ) {
+                            bzero(buf, NI_MAXHOST);
+                            getnameinfo(ifa->ifa_broadaddr, ifa->ifa_broadaddr->sa_len, buf, sizeof(buf), 0, 0, NI_NUMERICHOST);
+                            addrData->broadcastAddress = QString::fromLatin1(buf);
+                        }
+                       
+                        if ( ifa->ifa_dstaddr != NULL ) {
+                            bzero(buf, NI_MAXHOST);
+                            getnameinfo(ifa->ifa_dstaddr, ifa->ifa_dstaddr->sa_len, buf, sizeof(buf), 0, 0, NI_NUMERICHOST);
+                            data->ptpAddress = QString::fromLatin1(buf);
+                        }
+                        
+                        data->existing = true;
+                        interface->setType((ifa->ifa_flags & IFF_POINTOPOINT ) ? Interface::PPP : Interface::ETHERNET );
+
+                        // Get media status
+                        int s;
+                        if ((s = socket(ifa->ifa_addr->sa_family, SOCK_DGRAM, 0)) >= 0) {
+                            struct ifmediareq ifmr;
+                            (void) memset(&ifmr, 0, sizeof(ifmr));
+                            (void) strncpy(ifmr.ifm_name, ifa->ifa_name, sizeof(ifmr.ifm_name));
+
+                            if (ioctl(s, SIOCGIFMEDIA, (caddr_t)&ifmr) >= 0) {
+                                if (ifmr.ifm_status & IFM_AVALID)
+                                     /* 
+                                      * The interface is marked available, if the interface is up
+                                      * and if it is has carrier (LAN) or is associated (WLAN)
+                                      */
+                                     data->available = (ifa->ifa_flags & IFF_UP) && (ifmr.ifm_status & IFM_ACTIVE);
+                            }
+                            else
+                                data->available = (ifa->ifa_flags & IFF_UP);
+                            
+                            close(s);
+                        }
+                    }
+                    break;
+                 
+                 case AF_LINK:                
+                    interface = mInterfaceDict[QString::fromLatin1(ifa->ifa_name)];
+                    if ( interface ) {
+                        data = &interface->getData();
+
+                        // get MAC address
+                        struct sockaddr_dl* sdl = (struct sockaddr_dl*)ifa->ifa_addr;
+                        if (sdl->sdl_type == IFT_ETHER && sdl->sdl_alen == ETHER_ADDR_LEN)
+                            data->hwAddress = QString::fromLatin1(ether_ntoa((struct ether_addr*)LLADDR(sdl)));
+                        else
+                            data->hwAddress = "";
+                        
+                        // Get traffic statistics
+                        if (ifa->ifa_data != NULL) {
+                            ifd = (if_data *)ifa->ifa_data;
+                            
+                            data->rxPackets = ifd->ifi_ipackets;
+                            data->txPackets = ifd->ifi_opackets;
+                        
+                            if ( data->prevRxBytes == 0L )
+                                data->prevRxBytes = ifd->ifi_ibytes;
+                            else 
+                                data->prevRxBytes = data->rxBytes;
+                        
+                            data->rxBytes = ifd->ifi_ibytes;
+                            data->incomingBytes = data->rxBytes - data->prevRxBytes;
+                            data->rxString = KIO::convertSize( data->rxBytes );
+                    
+                            if ( data->prevTxBytes == 0L )
+                                data->prevTxBytes = ifd->ifi_obytes;
+                            else 
+                                data->prevTxBytes = data->txBytes;
+                            
+                            data->txBytes = ifd->ifi_obytes;
+                            data->outgoingBytes = data->txBytes - data->prevTxBytes;
+                            data->txString = KIO::convertSize( data->txBytes );
+                        }
+                    }
+                    break;
+            }
+        }
+        freeifaddrs(ifap);
+    }
+
+    // Update the display
+    for ( ifIt.toFirst(); ifIt.current(); ++ifIt )
+        ifIt.current()->activateMonitor();
+
+#endif // Q_OS_FREEBSD
 }
 
 void InterfaceUpdater::routeProcessExited( KProcess* process )
@@ -180,6 +340,7 @@
 
 void InterfaceUpdater::parseIfconfigOutput()
 {
+#ifndef Q_OS_FREEBSD    
     /* mIfconfigStdout contains the complete output of 'ifconfig' which we
      * are going to parse here.
      */
@@ -235,10 +396,12 @@
         }
         interface->activateMonitor();
     }
+#endif
 }
 
 void InterfaceUpdater::updateInterfaceData( QString& config, InterfaceData& data, int type )
 {
+#ifndef Q_OS_FREEBSD    
     QRegExp regExp( ".*RX.*:(\\d+).*:\\d+.*:\\d+.*:\\d+" );
     if ( regExp.search( config ) > -1 )
         data.rxPackets = regExp.cap( 1 ).toULong();
@@ -318,10 +481,12 @@
         if ( regExp.search( config ) > -1 )
             data.ptpAddress = regExp.cap( 2 );
     }
+#endif
 }
 
 void InterfaceUpdater::parseIwconfigOutput()
 {
+#ifndef Q_OS_FREEBSD
     /* mIwconfigStdout contains the complete output of 'iwconfig' which we
      * are going to parse here.
      */
@@ -364,10 +529,12 @@
             updateWirelessData( configs[key], interface->getWirelessData() );
         }
     }
+#endif
 }
 
 void InterfaceUpdater::updateWirelessData( QString& config, WirelessData& data )
 {
+#ifndef Q_OS_FREEBSD
     QRegExp regExp( "ESSID:\"?([^\"]*)\"?" );
     if ( regExp.search( config ) > -1 )
         data.essid = regExp.cap( 1 );
@@ -401,6 +568,7 @@
     regExp.setPattern( "Link Quality:([\\d/]*)" );
     if ( regExp.search( config ) > -1 )
         data.linkQuality = regExp.cap( 1 );
+#endif
 }
 
 void InterfaceUpdater::parseRouteOutput()
@@ -409,16 +577,25 @@
      * are going to parse here.
      */
     QMap<QString, QStringList> configs;
-    QStringList routeList = QStringList::split( "\n", mRouteStdout );
+    QStringList gateway, routeList = QStringList::split( "\n", mRouteStdout );
     QStringList::Iterator it;
     for ( it = routeList.begin(); it != routeList.end(); ++it )
     {
         QStringList routeParameter = QStringList::split( " ", *it );
+#ifdef Q_OS_FREEBSD
+        if ( routeParameter.count() != 2 )
+            continue;
+        if ( routeParameter[0] == "gateway:" )
+            gateway = routeParameter;
+        if ( routeParameter[0] == "interface:" )
+            configs[routeParameter[1]] = gateway;
+#else        
         if ( routeParameter.count() < 8 ) // no routing entry
             continue;
         if ( routeParameter[0] != "0.0.0.0" ) // no default route
             continue;
         configs[routeParameter[7]] = routeParameter;
+#endif
     }
 
     /* We loop over the interfaces the user wishs to monitor.
