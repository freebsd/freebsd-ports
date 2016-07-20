--- etc/afpd/volume.c.orig	2016-07-20 13:19:58 UTC
+++ etc/afpd/volume.c
@@ -380,7 +380,11 @@ static int getvolparams(const AFPObj *ob
                         ashort |= VOLPBIT_ATTR_UNIXPRIV;
                     if (vol->v_flags & AFPVOL_TM)
                         ashort |= VOLPBIT_ATTR_TM;
+#ifdef HAVE_LDAP
                     if (!ldap_config_valid || vol->v_flags & AFPVOL_NONETIDS)
+#else
+                    if (vol->v_flags & AFPVOL_NONETIDS)
+#endif
                         ashort |= VOLPBIT_ATTR_NONETIDS;
                     if (obj->afp_version >= 32) {
                         if (vol->v_vfs_ea)
