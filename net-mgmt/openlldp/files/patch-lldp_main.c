--- src/lldp_main.c	2007/04/01 04:03:26	1.78
+++ src/lldp_main.c	2007/04/18 04:13:33	1.84
@@ -28,8 +28,6 @@
 #ifdef __FREEBSD__
 #include <netinet/in.h>
 #include <net/if_dl.h>
-#include <sys/socket.h>
-#include <net/if.h>
 #include <net/if_arp.h>
 #include <net/if_media.h>
 #include <net/ethernet.h>
@@ -59,169 +57,184 @@
 void cleanupLLDP();
 void handle_segfault();
 
-#define MIN_INTERFACE 1
+#define IF_NAMESIZE    16
+char *iface_list[IF_NAMESIZE];
+int  iface_filter = 0;   /* boolean */
 
 struct lldp_port *lldp_ports = NULL;
 
 void walk_port_list() {
-  struct lldp_port *lldp_port = lldp_ports;
+    struct lldp_port *lldp_port = lldp_ports;
 
-  while(lldp_port != NULL) {
-    debug_printf(DEBUG_INT, "Interface structure @ %X\n", lldp_port);
-    debug_printf(DEBUG_INT, "\tName: %s\n", lldp_port->if_name);
-    debug_printf(DEBUG_INT, "\tIndex: %d\n", lldp_port->if_index);
-    debug_printf(DEBUG_INT, "\tMTU: %d\n", lldp_port->mtu);
-    debug_printf(DEBUG_INT, "\tMAC: %X:%X:%X:%X:%X:%X\n", lldp_port->source_mac[0], lldp_port->source_mac[1], lldp_port->source_mac[2] , lldp_port->source_mac[3] , lldp_port->source_mac[4] , lldp_port->source_mac[5]); 
-    debug_printf(DEBUG_INT, "\tIP: %d.%d.%d.%d\n", lldp_port->source_ipaddr[0], lldp_port->source_ipaddr[1], lldp_port->source_ipaddr[2], lldp_port->source_ipaddr[3]);
-    lldp_port = lldp_port->next;
-  }
+    while(lldp_port != NULL) {
+        debug_printf(DEBUG_INT, "Interface structure @ %X\n", lldp_port);
+        debug_printf(DEBUG_INT, "\tName: %s\n", lldp_port->if_name);
+        debug_printf(DEBUG_INT, "\tIndex: %d\n", lldp_port->if_index);
+        debug_printf(DEBUG_INT, "\tMTU: %d\n", lldp_port->mtu);
+        debug_printf(DEBUG_INT, "\tMAC: %X:%X:%X:%X:%X:%X\n", lldp_port->source_mac[0]
+                                                            , lldp_port->source_mac[1]
+                                                            , lldp_port->source_mac[2]
+                                                            , lldp_port->source_mac[3]
+                                                            , lldp_port->source_mac[4]
+                                                            , lldp_port->source_mac[5]); 
+        debug_printf(DEBUG_INT, "\tIP: %d.%d.%d.%d\n", lldp_port->source_ipaddr[0]
+                                                     , lldp_port->source_ipaddr[1]
+                                                     , lldp_port->source_ipaddr[2]
+                                                     , lldp_port->source_ipaddr[3]);
+        lldp_port = lldp_port->next;
+    }
 }
 
 int main(int argc, char *argv[])
 {
-  uid_t uid;
-  int op = 0;
-  char *theOpts = "c:i:d:f:s";
-  int socket_width = 0;
-  time_t current_time = 0;
-  time_t last_check = 0;
-  struct timeval timeout;
-  int result;
-  struct lldp_port *lldp_port = NULL;
-  
-  /* Needed for select() */
-  fd_set readfds;
-
-  program = argv[0];
-  
-  // get uid of user executing program. 
-  uid = getuid();
-  
-  if (uid != 0) {
-    debug_printf(DEBUG_NORMAL, "You must be running as root to run %s!\n", program);
-    exit(0);
-  }
-
-  // Process any arguments we were passed in.
-  while ((op = getopt(argc, argv, theOpts)) != EOF) {
-    switch (op) {
-    case 'd':
-      // Set the debug level.
-      if ((atoi(optarg) == 0) && (optarg[0] != '0')) {
-	debug_alpha_set_flags(optarg);
-      } else {
-	debug_set_flags(atoi(optarg));
-      }
-      break;
-      
-    default:
-      usage();
-      exit(0);
-      break;
-    };
-  }
-
-  /* Initialize the LLDP subsystem */
-  /* This should happen on a per-interface basis */
-  if(initializeLLDP() != 0) {
-    debug_printf(DEBUG_NORMAL, "[Error] LLDP Subsystem Initialization Falure\n");
-    debug_printf(DEBUG_NORMAL, "[Error] (%d) : %s (%s:%d)\n", errno, strerror(errno), __FUNCTION__, __LINE__);
-  }
-
-  get_sys_desc();
-  get_sys_fqdn();
-
-  while(1) {    
-    /* Set up select() */
-    FD_ZERO(&readfds);
+    uid_t uid;
+    int op = 0;
+    char *theOpts = "c:i:d:f:s:h";
+    int socket_width = 0;
+    time_t current_time = 0;
+    time_t last_check = 0;
+    struct timeval timeout;
+    int result;
+    struct lldp_port *lldp_port = NULL;
+
+    /* Needed for select() */
+    fd_set readfds;
+
+    program = argv[0];
+
+    // get uid of user executing program. 
+    uid = getuid();
+
+    if (uid != 0) {
+        debug_printf(DEBUG_NORMAL, "You must be running as root to run %s!\n", program);
+        exit(0);
+    }
 
-    lldp_port = lldp_ports;
+    // Process any arguments we were passed in.
+    while ((op = getopt(argc, argv, theOpts)) != EOF) {
+        switch (op) {
+            case 'd':
+                // Set the debug level.
+                if ((atoi(optarg) == 0) && (optarg[0] != '0')) {
+                    debug_alpha_set_flags(optarg);
+                } else {
+                    debug_set_flags(atoi(optarg));
+                }
+                break;
+            case 'i':
+                iface_filter = 1;
+                memcpy(iface_list, optarg, strlen(optarg));
+                iface_list[IF_NAMESIZE] = '\0';
+                debug_printf(DEBUG_NORMAL, "Using interface %s\n", iface_list);
+                break;
+            case 'h':
+            default:
+                usage();
+                exit(0);
+                break;
+        };
+    }
 
-    while(lldp_port != NULL) {
-      // This is not the interface you are looking for...
-      if(lldp_port->if_name == NULL)
-	{
-	  debug_printf(DEBUG_NORMAL, "[ERROR] Interface index %d with name is NULL at: %s():%d\n", lldp_port->if_index, __FUNCTION__, __LINE__);
-	  continue;
-	}
-	
-      FD_SET(lldp_port->socket, &readfds);
-
-      if(lldp_port->socket > socket_width)
-	{
-	  socket_width = lldp_port->socket;
-	}
-      
-      lldp_port = lldp_port->next;
-      
+    /* Initialize the LLDP subsystem */
+    /* This should happen on a per-interface basis */
+    if(initializeLLDP() == 0) {
+        debug_printf(DEBUG_NORMAL, "No interface found to listen on\n");
     }
 
-    time(&current_time);
-    
-    // Will be used to tell select how long to wait for...
-    timeout.tv_sec = 1;
-    timeout.tv_usec = 0;
-    
-    // Timeout after 1 second if nothing is ready
-    result = select(socket_width+1, &readfds, NULL, NULL, &timeout);
-    
-    // Everything is cool... process the sockets
-    lldp_port = lldp_ports;
-    
-    while(lldp_port != NULL) {
-      // This is not the interface you are looking for...
-      if(lldp_port->if_name == NULL) {
-	  debug_printf(DEBUG_NORMAL, "[ERROR] Interface index %d with name is NULL at: %s():%d\n", lldp_port->if_index, __FUNCTION__, __LINE__);
-	continue;
-      }
-
-      if(result > 0) {
-	if(FD_ISSET(lldp_port->socket, &readfds)) {
-	  debug_printf(DEBUG_INT, "%s is readable!\n", lldp_port->if_name);
-
-	  // Get the frame back from the OS-specific frame handler.
-	  lldp_read(lldp_port);
-
-	  if(lldp_port->rx.recvsize <= 0) {
-	    if(errno != EAGAIN && errno != ENETDOWN) {
-	      printf("Error: (%d) : %s (%s:%d)\n", errno, strerror(errno), __FUNCTION__, __LINE__);
-	    }
-	  } else {
-	    debug_printf(DEBUG_INT, "Got an LLDP frame %d bytes long on %s!\n", lldp_port->rx.recvsize, lldp_port->if_name);
-	    
-	    //	    debug_hex_dump(DEBUG_INT, lldp_port->rx.frame, lldp_port->rx.recvsize);
-	    
-	    // Mark that we received a frame so the state machine can process it.
-	    lldp_port->rx.rcvFrame = 1;
-	    
-	    rxStatemachineRun(lldp_port);
-	  }
-	}
-      }
-    
-      if((result == 0) || (current_time > last_check)) {
-	lldp_port->tick = 1;
-	
-	txStatemachineRun(lldp_port); 
-	rxStatemachineRun(lldp_port);
-	
-	lldp_port->tick = 0;
-      }
-      
-      if(result < 0) {
-	if(errno != EINTR) {
-	  debug_printf(DEBUG_NORMAL, "[ERROR] %s\n", strerror(errno));
-	}
-      }
-      
-      lldp_port = lldp_port->next;
+    get_sys_desc();
+    get_sys_fqdn();
+
+    while(1) {    
+        /* Set up select() */
+        FD_ZERO(&readfds);
+
+        lldp_port = lldp_ports;
+
+        while(lldp_port != NULL) {
+            // This is not the interface you are looking for...
+            if(lldp_port->if_name == NULL)
+            {
+                debug_printf(DEBUG_NORMAL, "[ERROR] Interface index %d with name is NULL at: %s():%d\n", lldp_port->if_index, __FUNCTION__, __LINE__);
+                continue;
+            }
+
+            FD_SET(lldp_port->socket, &readfds);
+
+            if(lldp_port->socket > socket_width)
+            {
+                socket_width = lldp_port->socket;
+            }
+
+            lldp_port = lldp_port->next;
+
+        }
+
+        time(&current_time);
+
+        // Will be used to tell select how long to wait for...
+        timeout.tv_sec = 1;
+        timeout.tv_usec = 0;
+
+        // Timeout after 1 second if nothing is ready
+        result = select(socket_width+1, &readfds, NULL, NULL, &timeout);
+
+        // Everything is cool... process the sockets
+        lldp_port = lldp_ports;
 
+        while(lldp_port != NULL) {
+            // This is not the interface you are looking for...
+            if(lldp_port->if_name == NULL) {
+                debug_printf(DEBUG_NORMAL, "[ERROR] Interface index %d with name is NULL at: %s():%d\n", lldp_port->if_index, __FUNCTION__, __LINE__);
+                continue;
+            }
+
+            if(result > 0) {
+                if(FD_ISSET(lldp_port->socket, &readfds)) {
+                    debug_printf(DEBUG_INT, "%s is readable!\n", lldp_port->if_name);
+
+                    // Get the frame back from the OS-specific frame handler.
+                    lldp_read(lldp_port);
+
+                    if(lldp_port->rx.recvsize <= 0) {
+                        if(errno != EAGAIN && errno != ENETDOWN) {
+                            printf("Error: (%d) : %s (%s:%d)\n", errno, strerror(errno), __FUNCTION__, __LINE__);
+                        }
+                    } else {
+                        debug_printf(DEBUG_INT, "Got an LLDP frame %d bytes long on %s!\n", lldp_port->rx.recvsize, lldp_port->if_name);
+
+                        //      debug_hex_dump(DEBUG_INT, lldp_port->rx.frame, lldp_port->rx.recvsize);
+
+                        // Mark that we received a frame so the state machine can process it.
+                        lldp_port->rx.rcvFrame = 1;
+
+                        rxStatemachineRun(lldp_port);
+                    }
+                }
+            }
+
+            if((result == 0) || (current_time > last_check)) {
+                lldp_port->tick = 1;
+
+                txStatemachineRun(lldp_port); 
+                rxStatemachineRun(lldp_port);
+
+                lldp_port->tick = 0;
+            }
+
+            if(result < 0) {
+                if(errno != EINTR) {
+                    debug_printf(DEBUG_NORMAL, "[ERROR] %s\n", strerror(errno));
+                }
+            }
+
+            lldp_port = lldp_port->next;
+
+        }
+
+        time(&last_check);     
     }
-      
-  time(&last_check);     
-}
- 
-  return 0;
+
+    return 0;
 }
 
 
@@ -232,124 +245,130 @@
  ***************************************/
 void handle_segfault()
 {
-  fprintf(stderr, "[FATAL] SIGSEGV  (Segmentation Fault)!\n");
+    fprintf(stderr, "[FATAL] SIGSEGV  (Segmentation Fault)!\n");
 
-  fflush(stderr); fflush(stdout);
-  exit(-1);
+    fflush(stderr); fflush(stdout);
+    exit(-1);
 }
 
 int initializeLLDP()
 {
-  int if_index = 0;
-  char if_name[IF_NAMESIZE];
-  struct lldp_port *lldp_port = NULL;
-
-  /* We need to initialize an LLDP port-per interface */
-  /* "lldp_port" will be changed to point at the interface currently being serviced */
-  for (if_index = MIN_INTERFACE; if_index < MAX_INTERFACES; if_index++)
+    int if_index = 0;
+    char if_name[IF_NAMESIZE];
+    struct lldp_port *lldp_port = NULL;
+    int nb_ifaces = 0;
+
+    /* We need to initialize an LLDP port-per interface */
+    /* "lldp_port" will be changed to point at the interface currently being serviced */
+    for (if_index = MIN_INTERFACES; if_index < MAX_INTERFACES; if_index++)
     {
-      if(if_indextoname(if_index, &if_name[0]) != NULL)
-	{ 
-	  if(strncmp(if_name, "wlt", 3) == 0) {
-	    debug_printf(DEBUG_NORMAL, "Skipping WLT interface because it's voodoo\n");
-	    continue;
-	  }
-
-	  /* Create our new interface struct */
-	  lldp_port = malloc(sizeof(struct lldp_port));
-
-	  /* Add it to the global list */
-	  lldp_port->next = lldp_ports;
-
-	  lldp_port->if_index = if_index;
-	  lldp_port->if_name = malloc(IF_NAMESIZE);
-	  memcpy(lldp_port->if_name, if_name, IF_NAMESIZE);
-	  
-	  if(lldp_port->if_name != NULL) {
-	      debug_printf(DEBUG_INT, "%s (index %d) found.\n", lldp_port->if_name, lldp_port->if_index);
-
-	      memcpy(&lldp_port->if_name[0], if_name, IF_NAMESIZE);
-	      
-	      debug_printf(DEBUG_INT, "Initializing interface: '%s'\n", lldp_port->if_name);
-	      
-	      // We want the first state to be LLDP_WAIT_PORT_OPERATIONAL, so we'll blank out everything here.
-	      lldp_port->portEnabled = 1;
-
-	      /* Initialize the socket for this interface */
-	      if(socketInitializeLLDP(lldp_port) != 0) {
-		debug_printf(DEBUG_NORMAL, "[ERROR] Problem initializing socket for %s\n", lldp_port->if_name);
-		free(lldp_port->if_name);
-		lldp_port->if_name = NULL;
-		free(lldp_port);
-		lldp_port = NULL;
-		continue;
-	      } else {
-		debug_printf(DEBUG_EXCESSIVE, "Finished initializing socket for index %d with name %s\n", lldp_port->if_index, lldp_port->if_name);
-	      }
-	      
-	      debug_printf(DEBUG_EXCESSIVE, "Initializing TX SM for index %d with name %s\n", lldp_port->if_index, lldp_port->if_name);
-	      lldp_port->tx.state = TX_LLDP_INITIALIZE;
-	      txInitializeLLDP(lldp_port);
-	      debug_printf(DEBUG_EXCESSIVE, "Initializing RX SM for index %d with name %s\n", lldp_port->if_index, lldp_port->if_name);
-	      lldp_port->rx.state = LLDP_WAIT_PORT_OPERATIONAL;
-	      rxInitializeLLDP(lldp_port);
-	      lldp_port->portEnabled  = 0;
-	      lldp_port->adminStatus  = 3;
-
-	      debug_printf(DEBUG_EXCESSIVE, "Initializing TLV subsystem for index %d with name %s\n", lldp_port->if_index, lldp_port->if_name);
-	      /* Initialize the TLV subsystem for this interface */
-	      tlvInitializeLLDP(lldp_port);
-
-	      debug_printf(DEBUG_EXCESSIVE, "Adding index %d with name %s to global port list\n", lldp_port->if_index, lldp_port->if_name);
-	      /* Reset the global list to point at the top of the list */
-	      /* We only want to get here if initialization succeeded  */
-	      lldp_ports = lldp_port;
-	    } else {
-	      free(lldp_port);
-	      lldp_port = NULL;
-	    }
-	  
-	} 
+        if(if_indextoname(if_index, if_name) == NULL)
+            continue;
+
+        /* keep only the iface specified by -i */
+        if (iface_filter) {
+            if(strncmp(if_name, (const char*)iface_list, IF_NAMESIZE) != 0) {
+                debug_printf(DEBUG_NORMAL, "Skipping interface %s (not %s)\n", if_name, iface_list);
+                continue;
+            }
+        }
+
+        if(strncmp(if_name, "wlt", 3) == 0) {
+            debug_printf(DEBUG_NORMAL, "Skipping WLT interface because it's voodoo\n");
+            continue;
+        }
+
+        /* Create our new interface struct */
+        lldp_port = malloc(sizeof(struct lldp_port));
+
+        /* Add it to the global list */
+        lldp_port->next = lldp_ports;
+
+        lldp_port->if_index = if_index;
+        lldp_port->if_name = malloc(IF_NAMESIZE);
+        if(lldp_port->if_name == NULL) {
+            free(lldp_port);
+            lldp_port = NULL;
+            continue;
+        }
+        
+        nb_ifaces++;
+        memcpy(lldp_port->if_name, if_name, IF_NAMESIZE);
+
+        debug_printf(DEBUG_INT, "%s (index %d) found. Initializing...\n", lldp_port->if_name, lldp_port->if_index);
+
+        // We want the first state to be LLDP_WAIT_PORT_OPERATIONAL, so we'll blank out everything here.
+        lldp_port->portEnabled = 1;
+
+        /* Initialize the socket for this interface */
+        if(socketInitializeLLDP(lldp_port) != 0) {
+            debug_printf(DEBUG_NORMAL, "[ERROR] Problem initializing socket for %s\n", lldp_port->if_name);
+            free(lldp_port->if_name);
+            lldp_port->if_name = NULL;
+            free(lldp_port);
+            lldp_port = NULL;
+            continue;
+        } else {
+            debug_printf(DEBUG_EXCESSIVE, "Finished initializing socket for index %d with name %s\n", lldp_port->if_index, lldp_port->if_name);
+        }
+
+        debug_printf(DEBUG_EXCESSIVE, "Initializing TX SM for index %d with name %s\n", lldp_port->if_index, lldp_port->if_name);
+        lldp_port->tx.state = TX_LLDP_INITIALIZE;
+        txInitializeLLDP(lldp_port);
+        debug_printf(DEBUG_EXCESSIVE, "Initializing RX SM for index %d with name %s\n", lldp_port->if_index, lldp_port->if_name);
+        lldp_port->rx.state = LLDP_WAIT_PORT_OPERATIONAL;
+        rxInitializeLLDP(lldp_port);
+        lldp_port->portEnabled  = 0;
+        lldp_port->adminStatus  = enabledRxTx;
+
+        debug_printf(DEBUG_EXCESSIVE, "Initializing TLV subsystem for index %d with name %s\n", lldp_port->if_index, lldp_port->if_name);
+        /* Initialize the TLV subsystem for this interface */
+        tlvInitializeLLDP(lldp_port);
+
+        debug_printf(DEBUG_EXCESSIVE, "Adding index %d with name %s to global port list\n", lldp_port->if_index, lldp_port->if_name);
+        /* Reset the global list to point at the top of the list */
+        /* We only want to get here if initialization succeeded  */
+        lldp_ports = lldp_port;
     }
-  
-  /* Don't forget to initialize the TLV validators... */
-  initializeTLVFunctionValidators();
-
-  // When we quit, cleanup.
-  signal(SIGTERM, cleanupLLDP);
-  signal(SIGINT, cleanupLLDP);
-  signal(SIGQUIT, cleanupLLDP);
-  signal(SIGSEGV, handle_segfault);
-  //  signal(SIGHUP, );
 
-  return 0;
+    /* Don't forget to initialize the TLV validators... */
+    initializeTLVFunctionValidators();
+
+    // When we quit, cleanup.
+    signal(SIGTERM, cleanupLLDP);
+    signal(SIGINT, cleanupLLDP);
+    signal(SIGQUIT, cleanupLLDP);
+    signal(SIGSEGV, handle_segfault);
+    //  signal(SIGHUP, );
+
+    return nb_ifaces;
 }
 
 void cleanupLLDP(struct lldp_port *lldp_port) {
-  debug_printf(DEBUG_NORMAL, "[AYBABTU] We Get Signal!\n");
+    debug_printf(DEBUG_NORMAL, "[AYBABTU] We Get Signal!\n");
 
-  lldp_port = lldp_ports;
+    lldp_port = lldp_ports;
 
-  while(lldp_port != NULL) {
+    while(lldp_port != NULL) {
 
-    if(lldp_port->if_name != NULL) {
-	debug_printf(DEBUG_NORMAL, "[CLEAN] %s (%d)\n", lldp_port->if_name, lldp_port->if_index);
+        if(lldp_port->if_name != NULL) {
+            debug_printf(DEBUG_NORMAL, "[CLEAN] %s (%d)\n", lldp_port->if_name, lldp_port->if_index);
 
-	tlvCleanupLLDP(lldp_port);
-	  
-	socketCleanupLLDP(lldp_port);	  
-      } else {
-	  debug_printf(DEBUG_NORMAL, "[ERROR] Interface index %d with name is NULL at: %s():%d\n", lldp_port->if_index, __FUNCTION__, __LINE__);
-      }
+            tlvCleanupLLDP(lldp_port);
 
-    lldp_port = lldp_port->next;
+            socketCleanupLLDP(lldp_port);     
+        } else {
+            debug_printf(DEBUG_NORMAL, "[ERROR] Interface index %d with name is NULL at: %s():%d\n", lldp_port->if_index, __FUNCTION__, __LINE__);
+        }
 
-    // Clean the previous node and move up.
-    free(lldp_ports);
-    lldp_ports = lldp_port;
-  }
+        lldp_port = lldp_port->next;
 
-  exit(0);
+        // Clean the previous node and move up.
+        free(lldp_ports);
+        lldp_ports = lldp_port;
+    }
+
+    exit(0);
 }
 
 /****************************************
@@ -359,40 +378,39 @@
  ****************************************/
 void usage()
 {
-  debug_printf(DEBUG_EXCESSIVE, "Entering %s():%d\n", __FUNCTION__, __LINE__);
+    debug_printf(DEBUG_EXCESSIVE, "Entering %s():%d\n", __FUNCTION__, __LINE__);
 
-  debug_printf(DEBUG_NORMAL, "\n\nlldpd %s\n", VERSION);
-  debug_printf(DEBUG_NORMAL, "(c) Copyright 2002 - 2006 The OpenLLDP Group\n");
-  debug_printf(DEBUG_NORMAL, "Dual licensed under the GPL and Other/Proprietary licenses."
-               "\n\n");
-  debug_printf(DEBUG_NORMAL, "This product borrows some code from the Open1X project"
-               ". (http://www.open1x.org)\n\n");
-  debug_printf(DEBUG_NORMAL, "Usage: %s "
-               "[-c config file] "
-               "[-i device] "
-               "[-d debug_level] "
-               "[-f] "
-               "[-s] "
-               "\n", program);
-
-  debug_printf(DEBUG_NORMAL, "\n\n");
-  debug_printf(DEBUG_NORMAL, "-c <path> : Use the config file <path> instead "
-               "of the default.\n");
-  debug_printf(DEBUG_NORMAL, "-i <interface> : Use <interface> for LLDP transactions"
-               "\n");
-  debug_printf(DEBUG_NORMAL, "-d <debug_level/flags> : Set debug verbosity."
-               "\n");
-  debug_printf(DEBUG_NORMAL, "-f : Run in forground mode.\n");
-  debug_printf(DEBUG_NORMAL, "-s : Remove the existing control socket if found.  (Should only be used in system init scripts!)\\
-n");
-  debug_printf(DEBUG_NORMAL, "\n\n");
-
-  debug_printf(DEBUG_NORMAL, " <debug_level> can be any of : \n");
-  debug_printf(DEBUG_NORMAL, "\tA : Enable ALL debug flags.\n");
-  debug_printf(DEBUG_NORMAL, "\tc : Enable CONFIG debug flag.\n");
-  debug_printf(DEBUG_NORMAL, "\ts : Enable STATE debug flag.\n");
-  debug_printf(DEBUG_NORMAL, "\tt : Enable TLV debug flag.\n");
-  debug_printf(DEBUG_NORMAL, "\ti : Enable INT debug flag.\n");
-  debug_printf(DEBUG_NORMAL, "\tn : Enable SNMP debug flag.\n");
-  debug_printf(DEBUG_NORMAL, "\tx : Enable EXCESSIVE debug flag.\n");
+    debug_printf(DEBUG_NORMAL, "\nlldpd %s\n", VERSION);
+    debug_printf(DEBUG_NORMAL, "(c) Copyright 2002 - 2006 The OpenLLDP Group\n");
+    debug_printf(DEBUG_NORMAL, "Dual licensed under the GPL and Other/Proprietary licenses."
+            "\n\n");
+    debug_printf(DEBUG_NORMAL, "This product borrows some code from the Open1X project"
+            ". (http://www.open1x.org)\n\n");
+    debug_printf(DEBUG_NORMAL, "Usage: %s "
+            "[-c config file] "
+            "[-i device] "
+            "[-d debug_level] "
+            "[-f] "
+            "[-s] "
+            "\n", program);
+
+    debug_printf(DEBUG_NORMAL, "\n\n");
+    debug_printf(DEBUG_NORMAL, "-c <path> : Use the config file <path> instead "
+            "of the default.\n");
+    debug_printf(DEBUG_NORMAL, "-i <interface> : Use <interface> for LLDP transactions"
+            "\n");
+    debug_printf(DEBUG_NORMAL, "-d <debug_level/flags> : Set debug verbosity."
+            "\n");
+    debug_printf(DEBUG_NORMAL, "-f : Run in forground mode.\n");
+    debug_printf(DEBUG_NORMAL, "-s : Remove the existing control socket if found.  (Should only be used in system init scripts!)\n");
+    debug_printf(DEBUG_NORMAL, "\n\n");
+
+    debug_printf(DEBUG_NORMAL, " <debug_level> can be any of : \n");
+    debug_printf(DEBUG_NORMAL, "\tA : Enable ALL debug flags.\n");
+    debug_printf(DEBUG_NORMAL, "\tc : Enable CONFIG debug flag.\n");
+    debug_printf(DEBUG_NORMAL, "\ts : Enable STATE debug flag.\n");
+    debug_printf(DEBUG_NORMAL, "\tt : Enable TLV debug flag.\n");
+    debug_printf(DEBUG_NORMAL, "\ti : Enable INT debug flag.\n");
+    debug_printf(DEBUG_NORMAL, "\tn : Enable SNMP debug flag.\n");
+    debug_printf(DEBUG_NORMAL, "\tx : Enable EXCESSIVE debug flag.\n");
 }
