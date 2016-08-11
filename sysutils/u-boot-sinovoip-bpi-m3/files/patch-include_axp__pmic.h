--- include/axp_pmic.h.orig	2016-04-12 02:22:25 UTC
+++ include/axp_pmic.h
@@ -32,6 +32,7 @@ int axp_set_aldo4(unsigned int mvolt);
 int axp_set_dldo(int dldo_num, unsigned int mvolt);
 int axp_set_eldo(int eldo_num, unsigned int mvolt);
 int axp_set_fldo(int fldo_num, unsigned int mvolt);
+int axp_set_dc1sw(int onoff);
 int axp_init(void);
 int axp_get_sid(unsigned int *sid);
 
