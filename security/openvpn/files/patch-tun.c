--- tun.c.orig	Sun Jun 23 23:43:57 2002
+++ tun.c	Sun Jun 23 23:45:54 2002
@@ -76,7 +76,7 @@
 		);
       msg (M_INFO, "%s", command_line);
       if (openvpn_system (command_line) != 0)
-	msg (M_ERR, "linux ifconfig failed");
+	msg (M_ERR, "Linux ifconfig failed");
 
 #elif defined(TARGET_SOLARIS)
 
@@ -90,7 +90,7 @@
 		);
       msg (M_INFO, "%s", command_line);
       if (openvpn_system (command_line) != 0)
-	msg (M_ERR, "solaris ifconfig failed");
+	msg (M_ERR, "Solaris ifconfig failed");
 
 #elif defined(TARGET_OPENBSD)
 
@@ -118,7 +118,7 @@
 		);
       msg (M_INFO, "%s", command_line);
       if (openvpn_system (command_line) != 0)
-	msg (M_ERR, "openbsd ifconfig failed");
+	msg (M_ERR, "OpenBSD ifconfig failed");
 
 #elif defined(TARGET_DARWIN)
 
@@ -144,7 +144,22 @@
 		);
       msg (M_INFO, "%s", command_line);
       if (openvpn_system (command_line) != 0)
-	msg (M_ERR, "darwin ifconfig failed");
+	msg (M_ERR, "Darwin ifconfig failed");
+
+#elif defined(TARGET_FREEBSD)
+      /* example: ifconfig tun2 10.2.0.2 10.2.0.1 mtu 1450 netmask 255.255.255.255 up */
+      snprintf (command_line, sizeof (command_line),
+		IFCONFIG_PATH " %s %s %s mtu %d netmask 255.255.255.255 up",
+		dev,
+		ifconfig_local,
+		ifconfig_remote,
+		tun_mtu
+		);
+      msg (M_INFO, "%s", command_line);
+      if (openvpn_system (command_line) != 0)
+	msg (M_ERR, "FreeBSD ifconfig failed");
+
+
 
 #else
       msg (M_FATAL, "Sorry, but I don't know how to do 'ifconfig' commands on this operating system.  You should ifconfig your tun/tap device manually or use an --up script.");
