--- VTK/ThirdParty/exodusII/vtkexodusII/src/ex_put_prop.c.orig	2024-12-29 23:38:49 UTC
+++ VTK/ThirdParty/exodusII/vtkexodusII/src/ex_put_prop.c
@@ -243,7 +243,7 @@ int ex_put_prop(int exoid, ex_entity_type obj_type, ex
     vals[0] = 0; /* fill value */
     /*   create attribute to cause variable to fill with zeros per routine spec
      */
-    if ((status = nc_put_att_longlong(exoid, propid, _FillValue, int_type, 1, vals)) != NC_NOERR) {
+    if ((status = nc_put_att_longlong(exoid, propid, NC_FillValue, int_type, 1, vals)) != NC_NOERR) {
       snprintf(errmsg, MAX_ERR_LENGTH,
                "ERROR: failed to create property name fill attribute in file id %d", exoid);
       ex_err_fn(exoid, __func__, errmsg, status);
