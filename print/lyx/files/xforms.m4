dnl some macros to test for xforms-related functionality  -*- sh -*-

dnl Usage LYX_PATH_XFORMS: Checks for xforms library and flags
dnl   If it is found, the variable XFORMS_LIB is set to the relevant -l flags,
dnl and FORMS_H_LOCATION / FLIMAGE_H_LOCATION is also set
AC_DEFUN(LYX_PATH_XFORMS,[
AC_REQUIRE([LYX_PATH_XPM])

AC_CHECK_LIB(forms, fl_initialize, XFORMS_LIB="-lforms",
  [AC_CHECK_LIB(xforms, fl_initialize, XFORMS_LIB="-lxforms",
    [LYX_LIB_ERROR(libforms or libxforms,xforms)], $XPM_LIB)], $XPM_LIB)
AC_SUBST(XFORMS_LIB)

### Check for xforms headers
lyx_cv_forms_h_location="<forms.h>"
AC_CHECK_HEADER(X11/forms.h,[
  ac_cv_header_forms_h=yes
  lyx_cv_forms_h_location="<X11/forms.h>"],[
AC_CHECK_HEADER(forms.h,[],[
LYX_LIB_ERROR(forms.h,forms)])])
AC_DEFINE_UNQUOTED(FORMS_H_LOCATION,$lyx_cv_forms_h_location,
   [define this to the location of forms.h to be used with #include, e.g. <forms.h>])

if test $ac_cv_header_forms_h = yes; then
  AC_CACHE_CHECK([xforms header version],lyx_cv_xfversion,
  [ cat > conftest.$ac_ext <<EOF
#line __oline__ "configure"
#include "confdefs.h"

#include FORMS_H_LOCATION
#if ! defined(FL_INCLUDE_VERSION)
"%%%"(unknown)"%%%"
#else
"%%%"FL_VERSION.FL_REVISION.FL_FIXLEVEL"%%%"
#endif
EOF
lyx_cv_xfversion=`(eval "$ac_cpp conftest.$ac_ext") 2>&5 | \
  grep '^"%%%"'  2>/dev/null | \
  sed -e 's/^"%%%"\(.*\)"%%%"/\1/' -e 's/ //g'`
rm -f conftest*])

XFORMS_VERSION=$lyx_cv_xfversion
case "$lyx_cv_xfversion" in
  "(unknown)"|0.8[1-7]*)
	 LYX_ERROR(dnl
Version $lyx_cv_xfversion of xforms is not compatible with LyX.
   This version of LyX works best with versions 0.88 (recommended) and later.) ;;
    0.88*) ;;
    0.89[01234]) LYX_WARNING(dnl
LyX should work ok with version $lyx_cv_xfversion of xforms[,] but
it is an unproven version and might still have some bugs. You should
probably use version 0.89.6 (or 0.88) instead) ;;
    0.89*) ;;
    0.9999*) ;;
    1.0*) ;;
       *) LYX_WARNING(dnl
Version $lyx_cv_xfversion of xforms might not be compatible with LyX[,]
 since it is newer than 0.89. You might have slight problems with it.);;
esac
fi
])



dnl Check whether the xforms library has a viable image loader
AC_DEFUN(LYX_USE_XFORMS_IMAGE_LOADER,
[AC_REQUIRE([LYX_PATH_XFORMS])
save_LIBS=$LIBS
LIBS="$XFORMS_LIB $XPM_LIB $LIBS"
lyx_use_xforms_image_loader=no
AC_LANG_SAVE
AC_LANG_C

AC_CHECK_LIB(jpeg, jpeg_read_header,
  [XFORMS_IMAGE_LIB=-ljpeg
   LIBS="$LIBS -ljpeg"])
AC_SEARCH_LIBS(flimage_dup, flimage,
  [lyx_use_xforms_image_loader=yes
   if test "$ac_cv_search_flimage_dup" != "none required" ; then
     XFORMS_IMAGE_LIB="-lflimage $XFORMS_IMAGE_LIB"
     LIBS="$XFORMS_IMAGE_LIB $LIBS"
  fi])
AC_SUBST(XFORMS_IMAGE_LIB)

if test $lyx_use_xforms_image_loader = yes ; then
  lyx_flags="$lyx_flags xforms-image-loader"
  AC_DEFINE(USE_XFORMS_IMAGE_LOADER, 1,
	    [Define if you want to use xforms built-in image loader])
  AC_CHECK_FUNCS(flimage_enable_ps flimage_enable_jpeg)
  AC_CHECK_HEADERS(flimage.h X11/flimage.h, break)
fi

### If the gui cannot load images itself, then we default to the
### very simple one in graphics/GraphicsImageXPM.[Ch]
AM_CONDITIONAL(USE_BASIC_IMAGE_LOADER,
	       test $lyx_use_xforms_image_loader = no)
AC_LANG_RESTORE
LIBS=$save_LIBS])
