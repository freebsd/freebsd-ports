--- popper/main.c.orig	Thu Jan  2 00:38:40 2003
+++ popper/main.c	Tue Dec 14 11:32:49 2004
@@ -343,6 +343,24 @@
                         trace_name, fileno(trace_file) );
                 break;
 
+            case 'y': /* log facility */
+                {
+                    POP config;
+                    POP *p = &config;
+                    if ( set_option ( p, "log-facility", optarg ) == POP_SUCCESS ) {
+                        closelog();
+#ifdef SYSLOG42
+                        openlog ( pname, 0 );
+#else
+                        openlog ( pname, POP_LOGOPTS, p->log_facility );
+#endif
+                    } else {
+                        fprintf ( stderr, "Error setting '-y' to %s\n", optarg );
+                        return 1;
+                    }
+                }
+                break;
+
             default:
                 break;
         }
