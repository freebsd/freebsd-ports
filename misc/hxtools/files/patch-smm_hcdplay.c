--- smm/hcdplay.c.orig	2020-07-12 09:44:16 UTC
+++ smm/hcdplay.c
@@ -15,16 +15,18 @@
 #include <unistd.h>
 #include <libHX/option.h>
 #include <sys/ioctl.h>
-#include <linux/cdrom.h>
-#define DEFAULT_ROM "/dev/sr0"
+#include <sys/cdio.h>
+#define DEFAULT_ROM "/dev/cd0"
 
 static char *cdev;
 static unsigned int dump_toc, do_start, do_pause, do_resume;
-static unsigned int do_play, do_stop, do_eject;
+static unsigned int do_play, do_stop, do_eject, do_close;
 
 static bool cdp_get_options(int *argc, const char ***argv)
 {
 	static const struct HXoption option_table[] = {
+		{.sh = 'C', .ln = "close",  .type = HXTYPE_NONE, .ptr = &do_close,
+		 .help = "Close the CD-ROM"},
 		{.sh = 'D', .ln = "device", .type = HXTYPE_STRING, .ptr = &cdev,
 		 .help = "CD-ROM device path", .htyp = "FILE"},
 		{.sh = 'E', .ln = "eject",  .type = HXTYPE_NONE, .ptr = &do_eject,
@@ -56,7 +58,7 @@ static bool cdp_get_options(int *argc, const char ***a
 
 int main(int argc, const char **argv)
 {
-	struct cdrom_tochdr toc;
+	struct ioc_toc_header toc;
 	int fd;
 
 	if (!cdp_get_options(&argc, &argv))
@@ -69,38 +71,57 @@ int main(int argc, const char **argv)
 		return EXIT_FAILURE;
 	}
 
-	if (ioctl(fd, CDROMREADTOCHDR, &toc) < 0) {
-		perror("ioctl CDROMREADTOCHDR");
+	/*
+	 * Ejecting and closing the CD-ROM tray does not require reading
+	 * of the TOC header first (at least on FreeBSD).
+	 */
+	if (do_eject) {
+		(void)ioctl(fd, CDIOCALLOW);
+		if (ioctl(fd, CDIOCEJECT) < 0)
+			perror("ioctl CDIOCEJECT");
+		/*
+		 * It is pointless to do anything after CD-ROM had been
+		 * ejected, so exit early.
+		 */
+		goto done;
+	}
+	if (do_close) {
+		(void)ioctl(fd, CDIOCALLOW);
+		if (ioctl(fd, CDIOCCLOSE) < 0)
+			perror("ioctl CDIOCCLOSE");
+	}
+	if (ioctl(fd, CDIOREADTOCHEADER, &toc) < 0) {
+		perror("ioctl CDIOREADTOCHEADER");
 		return EXIT_FAILURE;
 	}
 	if (dump_toc)
-		printf("Tracks: %u-%u\n", toc.cdth_trk0, toc.cdth_trk1);
+		printf("Tracks: %u-%u\n", toc.starting_track, toc.ending_track);
 	if (do_start)
-		if (ioctl(fd, CDROMSTART) < 0)
-			perror("ioctl CDROMSTART");
+		if (ioctl(fd, CDIOCSTART) < 0)
+			perror("ioctl CDIOCSTART");
 	if (do_pause)
-		if (ioctl(fd, CDROMPAUSE) < 0)
-			perror("ioctl CDROMPAUSE");
+		if (ioctl(fd, CDIOCPAUSE) < 0)
+			perror("ioctl CDIOCPAUSE");
 	if (do_resume)
-		if (ioctl(fd, CDROMRESUME) < 0)
-			perror("ioctl CDROMRESUME");
+		if (ioctl(fd, CDIOCRESUME) < 0)
+			perror("ioctl CDIOCRESUME");
 	if (do_play) {
-		struct cdrom_ti t;
-		t.cdti_trk0 = (argc >= 2) ? strtoul(argv[1], NULL, 0) :
-		              toc.cdth_trk0;
-		t.cdti_trk1 = (argc >= 3) ? strtoul(argv[2], NULL, 0) :
-		              toc.cdth_trk1;
-		t.cdti_ind0 = 0;
-		t.cdti_ind1 = 0;
-		if (ioctl(fd, CDROMPLAYTRKIND, &t) < 0)
-			perror("ioctl CDROMPLAYTRKIND");
+		struct ioc_play_track t;
+		t.start_track = (argc >= 2) ? strtoul(argv[1], NULL, 0) :
+		              toc.starting_track;
+		t.end_track = (argc >= 3) ? strtoul(argv[2], NULL, 0) :
+		              toc.ending_track;
+		t.start_index = 1;
+		t.end_index = 1;
+		if (ioctl(fd, CDIOCPLAYTRACKS, &t) < 0)
+			perror("ioctl CDIOCPLAYTRACKS");
 	}
-	if (do_stop)
-		if (ioctl(fd, CDROMSTOP) < 0)
-			perror("ioctl CDROMSTOP");
-	if (do_eject)
-		if (ioctl(fd, CDROMEJECT) < 0)
-			perror("ioctl CDROMEJECT");
+	if (do_stop) {
+		if (ioctl(fd, CDIOCSTOP) < 0)
+			perror("ioctl CDIOCSTOP");
+		(void)ioctl(fd, CDIOCALLOW);
+	}
+ done:
 	close(fd);
 	return EXIT_SUCCESS;
 }
