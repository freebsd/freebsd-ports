--- client/dhclient.c.orig	Wed Nov 24 18:39:14 2004
+++ client/dhclient.c	Tue Mar  8 14:06:59 2005
@@ -38,6 +38,13 @@
 #include "dhcpd.h"
 #include "version.h"
 
+#if __FreeBSD_version > 502010
+#include <sys/ioctl.h>
+#include <net/if_media.h>
+#include <net80211/ieee80211_ioctl.h>
+#include <net80211/ieee80211.h>
+#endif
+
 TIME default_lease_time = 43200; /* 12 hours... */
 TIME max_lease_time = 86400; /* 24 hours... */
 
@@ -72,8 +79,11 @@
 struct string_list *client_env=NULL;
 int client_env_count=0;
 int onetry=0;
-int quiet=0;
+int quiet=1;
 int nowait=0;
+#ifdef ENABLE_POLLING_MODE
+int polling_interval = 5;
+#endif
 
 static void usage PROTO ((void));
 
@@ -174,6 +184,9 @@
 		} else if (!strcmp (argv [i], "-q")) {
 			quiet = 1;
 			quiet_interface_discovery = 1;
+		} else if (!strcmp (argv [i], "-v")) {
+			quiet = 0;
+			quiet_interface_discovery = 0;
 		} else if (!strcmp (argv [i], "-s")) {
 			if (++i == argc)
 				usage ();
@@ -187,6 +200,19 @@
 		} else if (!strcmp (argv [i], "-n")) {
 			/* do not start up any interfaces */
 			interfaces_requested = 1;
+#ifdef ENABLE_POLLING_MODE
+		} else if (!strcmp (argv [i], "-i")) {
+			if (++i == argc)
+				usage ();
+			polling_interval = (int)strtol (argv [i],
+			    (char **)NULL, 10);
+			if (polling_interval <= 0) {
+				log_info ("Incorrect polling interval %d",
+				    polling_interval);
+				log_info ("Using a default of 5 seconds");
+				polling_interval = 5;
+			}
+#endif
 		} else if (!strcmp (argv [i], "-w")) {
 			/* do not exit if there are no broadcast interfaces. */
 			persist = 1;
@@ -215,7 +241,16 @@
 		    if (strlen (argv [i]) > sizeof tmp -> name)
 			    log_fatal ("%s: interface name too long (max %ld)",
 				       argv [i], (long)strlen (argv [i]));
- 		    strcpy (tmp -> name, argv [i]);
+ 		    strlcpy (tmp -> name, argv [i], IFNAMSIZ);
+#if __FreeBSD_version > 502010
+		    set_ieee80211 (tmp);
+#endif
+		    /* Init some interface vars, enable polling */
+#ifdef ENABLE_POLLING_MODE
+		    tmp -> forcediscover = 0;
+		    tmp -> linkstate = HAVELINK;
+		    tmp -> polling = 1;
+#endif /* ifdef ENABLE_POLLING_MODE */
 		    if (interfaces) {
 			    interface_reference (&tmp -> next,
 						 interfaces, MDL);
@@ -375,6 +410,16 @@
 					     INTERFACE_AUTOMATIC)) !=
 			     INTERFACE_REQUESTED))
 				continue;
+#if __FreeBSD_version > 502010
+			set_ieee80211 (ip);
+#endif
+#ifdef ENABLE_POLLING_MODE
+			ip -> forcediscover = 0;
+			if (ip -> client -> config -> media != NULL)
+				ip -> havemedia = 1;
+			else
+				ip -> havemedia = 0;
+#endif
 			script_init (ip -> client,
 				     "PREINIT", (struct string_list *)0);
 			if (ip -> client -> alias)
@@ -417,8 +462,13 @@
 				client -> state = S_INIT;
 				/* Set up a timeout to start the initialization
 				   process. */
+#ifdef ENABLE_POLLING_MODE
+				add_timeout (cur_time + random () % 5 + 2,
+					     state_polling, client, 0, 0);
+#else
 				add_timeout (cur_time + random () % 5,
 					     state_reboot, client, 0, 0);
+#endif
 			}
 		}
 	}
@@ -476,9 +526,9 @@
 	log_info (arr);
 	log_info (url);
 
-	log_error ("Usage: dhclient [-1dqr] [-nw] [-p <port>] %s",
-		   "[-s server]");
-	log_error ("                [-cf config-file] [-lf lease-file]%s",
+	log_error ("Usage: dhclient [-1Ddqrv] [-i polling-interval] %s",
+		   "[-nw] [-p <port>] [-s server]");
+	log_error ("                [-cf config-file] [-lf lease-file] %s",
 		   "[-pf pid-file] [-e VAR=val]");
 	log_fatal ("                [-sf script-file] [interface]");
 }
@@ -881,6 +931,15 @@
 	/* Write out the new lease. */
 	write_client_lease (client, client -> new, 0, 0);
 
+	/*
+	 * It's now possible that state_reboot can be called
+	 * after a interface link went down and is up again.
+	 * To prevent tons of equal leases saved on disk, we rewrite
+	 * them.
+	 */
+	read_client_leases ();
+	rewrite_client_leases ();
+ 
 	/* Replace the old active lease with the new one. */
 	if (client -> active)
 		destroy_client_lease (client -> active);
@@ -895,6 +954,12 @@
 	      piaddr (client -> active -> address),
 	      (long)(client -> active -> renewal - cur_time));
 	client -> state = S_BOUND;
+#ifdef ENABLE_POLLING_MODE
+	/* Init some interface vars, enable polling */
+	client -> interface -> linkstate = HAVELINK;
+	client -> interface -> forcediscover = 0;
+	client -> interface -> polling = 1;
+#endif /* ifdef ENABLE_POLLING_MODE */
 	reinitialize_interfaces ();
 	go_daemon ();
 	if (client -> config -> do_forward_update) {
@@ -1359,6 +1424,11 @@
 	int interval;
 	int increase = 1;
 
+#ifdef ENABLE_POLLING_MODE
+	/* Disable polling for this interface */
+	client -> interface -> polling = 0;
+#endif
+
 	/* Figure out how long it's been since we started transmitting. */
 	interval = cur_time - client -> first_sending;
 
@@ -1464,6 +1534,9 @@
 	struct client_lease *loop;
 	struct client_lease *lp;
 
+	if (client -> interface -> linkstate == NOLINK)
+		return;
+
 	loop = lp = client -> active;
 
 	log_info ("No DHCPOFFERS received.");
@@ -1496,6 +1569,10 @@
 				log_info ("bound: renewal in %ld %s.",
 					  (long)(client -> active -> renewal -
 						 cur_time), "seconds");
+#ifdef ENABLE_POLLING_MODE
+				/* Enable polling for this interface */
+				client -> interface -> polling = 1;
+#endif
 				add_timeout (client -> active -> renewal,
 					     state_bound, client, 0, 0);
 			    } else {
@@ -1503,6 +1580,11 @@
 				log_info ("bound: immediate renewal.");
 				state_bound (client);
 			    }
+			    /*
+			     * Set the link status back to nolink, even
+			     * if we have media settings.
+			     */
+                            client -> interface -> linkstate = NOLINK;
 			    reinitialize_interfaces ();
 			    go_daemon ();
 			    return;
@@ -1548,6 +1630,12 @@
 	}
 
 	log_info ("No working leases in persistent database - sleeping.");
+
+#ifdef ENABLE_POLLING_MODE
+	/* Enable polling for this interface */
+	client -> interface -> polling = 1;
+#endif
+
 	script_init (client, "FAIL", (struct string_list *)0);
 	if (client -> alias)
 		script_write_params (client, "alias_", client -> alias);
@@ -1689,6 +1777,18 @@
 			client -> packet.secs = htons (65535);
 	}
 
+	/*
+	 * Only try the first ten seconds to renew a lease from a
+	 * given dhcp-server adress. After that, fall back to use
+	 * state_reboot with INADDR_BROADCAST.
+	 */
+	if (destination.sin_addr.s_addr != INADDR_BROADCAST &&
+	   (client -> state == S_RENEWING || client -> state == S_REBINDING)) {
+		if (client -> active && client -> active -> expiry > cur_time &&
+			interval >= 10)
+			goto cancel;
+	}
+
 	log_info ("DHCPREQUEST on %s to %s port %d",
 	      client -> name ? client -> name : client -> interface -> name,
 	      inet_ntoa (destination.sin_addr),
@@ -1710,6 +1810,16 @@
 				      from, &destination,
 				      (struct hardware *)0);
 
+	/*
+	 * If sendto() for a direct request fails, fall back to use
+	 * state_reboot with INADDR_BROADCAST.
+	 */
+	if (result == -1 && destination.sin_addr.s_addr != INADDR_BROADCAST &&
+	   (client -> state == S_RENEWING || client -> state == S_REBINDING)) {
+		if (client -> active && client -> active -> expiry > cur_time)
+			goto cancel;
+	}
+
 	add_timeout (cur_time + client -> interval,
 		     send_request, client, 0, 0);
 }
@@ -2607,6 +2717,13 @@
 			wstatus = 0;
 		}
 	} else {
+		if ((i = open(_PATH_DEVNULL, O_RDWR)) != -1) {
+			dup2(i, STDIN_FILENO);
+			dup2(i, STDOUT_FILENO);
+			dup2(i, STDERR_FILENO);
+			if (i > STDERR_FILENO)
+				close(i);
+		}
 		execve (scriptName, argv, envp);
 		log_error ("execve (%s, ...): %m", scriptName);
 		exit (0);
@@ -2793,8 +2910,10 @@
 			      case S_STOPPED:
 				break;
 			}
+#ifndef ENABLE_POLLING_MODE
 			client -> state = S_INIT;
 			state_reboot (client);
+#endif
 		}
 	}
 }
@@ -3022,7 +3141,9 @@
 		    break;
 
 		  case server_awaken:
+#ifndef ENABLE_POLLING_MODE
 		    state_reboot (client);
+#endif
 		    break;
 		}
 	    }
@@ -3160,3 +3281,265 @@
 	data_string_forget (&ddns_dhcid, MDL);
 	return rcode;
 }
+ 
+/* Check to see if there's a wire plugged in */
+int
+interface_active(struct interface_info *ip) {
+#if __FreeBSD_version > 502010
+	struct ifmediareq ifmr;
+	int *media_list, i;
+	char *ifname;
+	int sock;
+ 
+	ifname = ip -> name;
+ 
+	if ((sock = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
+		log_fatal ("Can't create interface_active socket");
+ 
+	(void) memset (&ifmr, 0, sizeof (ifmr));
+	(void) strncpy (ifmr.ifm_name, ifname, sizeof (ifmr.ifm_name));
+ 
+	if (ioctl (sock, SIOCGIFMEDIA, (caddr_t)&ifmr) < 0) {
+		/*
+		 * Interface doesn't support SIOCGIFMEDIA, presume okay
+		 */
+		close (sock);
+		return (HAVELINK);
+	}
+	close (sock);
+ 
+	if (ifmr.ifm_count == 0) {
+		/*
+		 * Assume that this means interface
+		 * does not support SIOCGIFMEDIA
+		 */
+		log_fatal ("%s: no media types?", ifname);
+		return (HAVELINK);
+	}
+ 
+	if (ifmr.ifm_status & IFM_AVALID) {
+		if (ip -> ieee80211) {
+			/*
+			 * Wavelan devices need to be checked if they are
+			 * associated.
+			 */
+			if ((IFM_TYPE(ifmr.ifm_active) == IFM_IEEE80211) &&
+			     (ifmr.ifm_status & IFM_ACTIVE)) {
+				return (HAVELINK);
+			}
+		} else {
+			if (ifmr.ifm_status & IFM_ACTIVE) {
+				return (HAVELINK);
+			}
+		}
+		/*
+		 * We really have no link.
+		 */
+		return (NOLINK);
+	}
+	/*
+	 * IFM_AVALID is not set. We cannot check
+	 * the link state. Assume HAVELINK.
+	 */
+ 
+#endif /* Other OSs */
+	/*
+	 * Always return a successful link if the OS
+	 * is not supported.
+	 */
+	return (HAVELINK);
+}
+ 
+#if __FreeBSD_version > 502010
+void
+set_ieee80211 (struct interface_info *ip) {
+ 
+	struct ieee80211req     ireq;
+	u_int8_t                data[32];
+	int                     associated = 0;
+	int *media_list, i;
+	char *ifname;
+	int sock;
+ 
+	ifname = ip -> name;
+ 
+	if ((sock = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
+		log_fatal ("Can't create interface_active socket");
+ 
+	(void) memset (&ireq, 0, sizeof (ireq));
+	(void) strncpy (ireq.i_name, ifname, sizeof (ireq.i_name));
+	ireq.i_data = &data;
+	ireq.i_type = IEEE80211_IOC_SSID;
+	ireq.i_val = -1;
+	/*
+	 * If we can't get the SSID,
+	 * this isn't an 802.11 device.
+	 */
+	if (ioctl (sock, SIOCG80211, &ireq) < 0)
+		ip -> ieee80211 = 0;
+	else {
+#ifdef DEBUG
+		printf ("Device %s has 802.11\n", ifname);
+#endif
+		ip -> ieee80211 = 1;
+	}
+	close (sock);
+ }
+#endif /* __FreeBSD_version */
+ 
+#ifdef ENABLE_POLLING_MODE
+/* Go to background after some time */
+void state_background (cpp)
+	void *cpp;
+{
+	go_daemon ();
+}
+
+/* Check the state of the NICs if we have link */
+void state_polling (cpp)
+	 void *cpp;
+{
+	static int doinitcheck = 0;
+	struct interface_info *ip;
+	struct client_state *client;
+	int result;
+ 
+	for (ip = interfaces; ip; ip = ip -> next) {
+		if (! ip -> polling)
+			continue;
+#ifdef DEBUG
+		printf ("%s: Polling interface state\n", ip -> name);
+		for (client = ip -> client;
+		     client; client = client -> next) {
+			printf ("%s: client state of %d\n", ip -> name, ip -> client -> state);
+			printf ("%s: link = %d\n", ip -> name, ip -> linkstate);
+		}
+#endif
+ 
+		result = interface_active (ip);
+		/*
+		 * If dhclient.conf contains media settings, we cannot
+		 * abort if the interface is not set to active mode.
+		 */
+		if (ip -> havemedia && ip -> client -> state != S_BOUND) {
+			if (result == HAVELINK)
+				ip -> forcediscover = 1;
+			result = HAVELINK;
+		}
+ 
+		/*
+		 * The last status of the interface tells us
+		 * the we've got no link ...
+		 */
+		if (ip -> linkstate == NOLINK || ! doinitcheck) {
+			/*
+			 * ... but we have now link. Let's send
+			 * requests.
+			 */
+			if (result == HAVELINK) {
+#ifdef DEBUG
+				if (ip -> havemedia)
+					printf ("%s: Trying media settings on interface\n",
+						ip -> name);
+				else
+					printf ("%s: Found Link on interface\n", ip -> name);
+#endif
+				/*
+				 * Set the interface to state_bound. We assume that we have
+				 * a working link. If we cannot reach the server directly,
+				 * INADDR_BROADCAST is used.
+				 */
+				for (client = ip -> client;
+				     client; client = client -> next) {
+					cancel_timeout (state_init, client);
+					cancel_timeout (state_reboot, client);
+					cancel_timeout (state_selecting, client);
+					if (client -> active) {
+						add_timeout (cur_time + random () % 5,
+						   state_bound, client, 0, 0);
+					} else {
+						add_timeout (cur_time + random () % 5,
+						   state_reboot, client, 0, 0);
+					}
+				}
+				ip -> linkstate = HAVELINK;
+			} else {
+#ifdef DEBUG
+				printf ("%s: No link on interface\n", ip -> name);
+#endif
+				for (client = ip -> client;
+				     client; client = client -> next) {
+					/*
+					 * Without this add_timout(), dhclient does
+					 * not poll on a interface if there
+					 * is no cable plugged in at startup
+					 * time. Because we add one additional second
+					 * to the time of a normal timeout, we always
+					 * skip and block a running one. This prevents
+					 * that polling is done twice at the same time.
+					 */
+					if (client -> state == S_INIT) {
+						add_timeout (cur_time + (polling_interval + 1),
+							     state_polling, client, 0, 0);
+					}
+				}
+				ip -> linkstate = NOLINK;
+				/*
+				 * Automatically go into the background after
+				 * some time. Do this only if there are no
+				 * media options available for a interface.
+				 */
+				if (! ip -> havemedia && ! doinitcheck) {
+					add_timeout (cur_time + (polling_interval * 2),
+						    state_background, client, 0, 0);
+				}
+			}
+		}
+ 
+		/*
+		 * The last status of the interface tells us
+		 * the we previously had link.
+		 */
+		if (ip -> linkstate == HAVELINK && doinitcheck) {
+			if (result == NOLINK) {
+				/*
+				 * We lost link on the interface, or it isn't
+				 * associated anymore.
+				 */
+#ifdef DEBUG
+				printf ("%s: Lost Link on interface\n", ip -> name);
+#endif
+				/*
+				 * After we lost link, cycle again through the
+				 * different media settings if available. Else
+				 * set NOLINK.
+				 */
+				if (ip -> havemedia)
+					ip -> forcediscover = 1;
+				else
+					ip -> linkstate = NOLINK;
+			}
+			/*
+			 * If we happen to have a real link, but no
+			 * active lease, force the interface into
+			 * state_reboot. Do the same if media settings
+			 * are available.
+			 */
+			if (ip -> forcediscover) {
+				for (client = ip -> client;
+				     client; client = client -> next) {
+					if (client -> state != S_REBOOTING &&
+					    client -> state != S_SELECTING) {
+						add_timeout (cur_time + random () % 5,
+							    state_reboot, client, 0, 0);
+					}
+				}
+				ip -> forcediscover = 0;
+				ip -> linkstate = HAVELINK;
+			}
+			/* We still have link, do nothing. */
+		}
+	}
+	doinitcheck = 1;
+}
+#endif /* ifdef ENABLE_POLLING_MODE */
