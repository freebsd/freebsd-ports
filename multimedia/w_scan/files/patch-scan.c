--- a/scan.c
+++ b/scan.c
@@ -1640,6 +1640,8 @@ static int set_frontend(int frontend_fd,
 		case 0x0302:
 			verbose("%s: using DVB API 3.2\n", __FUNCTION__);
 			copy_fe_params_new_to_old(&p, &t->param);
+			if (t->type == FE_QPSK)
+				p.frequency = intermediate_freq;
 			if (ioctl(frontend_fd, FE_SET_FRONTEND, &p) == -1) {
 				errorn("Setting frontend parameters failed (API v3.2)\n");
 				return -1;
