===================================================================
RCS file: /cvsroot/mjpeg/mjpeg_play/lavtools/lav_io.c,v
retrieving revision 1.74
retrieving revision 1.78
diff -u -r1.74 -r1.78
--- lavtools/lav_io.c	2005/10/24 03:17:56	1.74
+++ lavtools/lav_io.c	2005/12/04 19:59:47	1.78
@@ -1395,8 +1395,8 @@
          break;
 #ifdef HAVE_LIBQUICKTIME
       case 'q':
-         res = fileno(((quicktime_t *)lav_file->qt_fd)->stream);
-         break;
+	res = lqt_fileno((quicktime_t *)lav_file->qt_fd);
+	break;
 #endif
       default:
          res = -1;
