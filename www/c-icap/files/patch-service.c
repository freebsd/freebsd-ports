--- service.c.orig	2014-11-21 23:12:01.548529197 +0100
+++ service.c	2014-11-21 23:15:36.951514636 +0100
@@ -368,7 +368,7 @@
      xdata = &service_extra_data_list[services_num];
      init_extra_data(xdata, service->mod_name);
      if (service->mod_init_service) {
-          ret = service->mod_init_service(xdata, &CONF);
+          ret = service->mod_init_service(xdata, &CI_CONF);
           if (ret != CI_OK)
                xdata->status = CI_SERVICE_ERROR;
           else
@@ -449,7 +449,7 @@
                xdata = &service_extra_data_list[i];
                if ( xdata->status == CI_SERVICE_OK) {
                     ret = service_list[i]->
-                        mod_post_init_service(xdata, &CONF);
+                        mod_post_init_service(xdata, &CI_CONF);
                     if (ret != CI_OK)
                         xdata->status = CI_SERVICE_ERROR;
                }
@@ -608,7 +608,7 @@
      ci_service_module_t *service = NULL;
      CI_DLIB_HANDLE service_handle;
 
-     service_handle = ci_module_load(service_file, CONF.SERVICES_DIR);
+     service_handle = ci_module_load(service_file, CI_CONF.SERVICES_DIR);
      if (!service_handle)
           return NULL;
      service = ci_module_sym(service_handle, "service");
