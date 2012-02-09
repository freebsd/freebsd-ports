--- content/public/common/common_param_traits.h.orig	2011-06-06 00:08:49.215163238 +0300
+++ content/public/common/common_param_traits.h	2011-06-06 00:09:04.929165157 +0300
@@ -187,7 +187,7 @@
 };
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_FREEBSD)
 template<>
 struct ParamTraits<TransportDIB::Id> {
   typedef TransportDIB::Id param_type;
