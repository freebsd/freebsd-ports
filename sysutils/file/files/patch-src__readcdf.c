--- ./src/readcdf.c.orig	2010-01-14 16:30:22.699632246 -0500
+++ ./src/readcdf.c	2010-01-14 16:30:27.240264949 -0500
@@ -100,6 +100,8 @@
 						str = "vnd.ms-excel";
 					else if (strstr(s, "Powerpoint"))
 						str = "vnd.ms-powerpoint";
+					else if (strstr(s, "Crystal Reports"))
+						str = "x-rpt";
 				}
 			}
 			break;
