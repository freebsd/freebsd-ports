--- include.mk.orig	2015-06-25 09:39:55 UTC
+++ include.mk
@@ -3,7 +3,7 @@ am__v_ERLC_ = $(am__v_ERLC_$(AM_DEFAULT_
 am__v_ERLC_0 = @echo "  ERLC    " $@;
 am__v_ERLC_1 =
 
-ERLC_GENERIC_FLAGS = -Werror  +debug_info $(DEBUG_ERLC_FLAGS)				\
+ERLC_GENERIC_FLAGS =  +debug_info $(DEBUG_ERLC_FLAGS)				\
 		     -pa $(top_srcdir) -pa $(top_builddir) -pa $(top_builddir)/ebin	\
 		     -I $(top_srcdir)/include -I $(srcdir)/../include 			\
 		     -I $(top_builddir)/include -I $(builddir)/../include
