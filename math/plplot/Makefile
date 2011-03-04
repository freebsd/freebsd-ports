# New ports collection makefile for:    plplot
# Date created:         03 Oct 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plplot
PORTVERSION=	5.9.7
CATEGORIES=	math science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A scientific plotting package

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/FreeMono.ttf:${PORTSDIR}/x11-fonts/freefont-ttf
LIB_DEPENDS=	unicode.0:${PORTSDIR}/devel/libunicode \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gd.4:${PORTSDIR}/graphics/gd \
		qhull.5:${PORTSDIR}/math/qhull
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		${LOCALBASE}/lib/X11/fonts/freefont-ttf/FreeMono.ttf:${PORTSDIR}/x11-fonts/freefont-ttf

USE_AUTOTOOLS=	libltdl
USE_CMAKE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	pango
USE_GHOSTSCRIPT=yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"	\
		LDFLAGS="-L${LOCALBASE}/lib"		\
		WITH_FREETYPE=ON
CMAKE_ARGS+=	-DENABLE_java:BOOL=OFF -DENABLE_octave:BOOL=OFF	\
		-DENABLE_ada:BOOL=OFF -DENABLE_d:BOOL=OFF	\
		-DPLD_plmeta=ON

USE_LDCONFIG=	yes

MAN1=		plm2gif.1 plpr.1 pltek.1 plrender.1

.if !defined(WITHOUT_PTHREAD)
CMAKE_ARGS+=	-DTHREADS_HAVE_PTHREAD_ARG:BOOL=OFF
.endif

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
PLIST_SUB+=	X11="@comment "
.else
USE_XORG=	x11
LIB_DEPENDS+=	LASi.0:${PORTSDIR}/devel/lasi
PLIST_SUB+=	X11=""
.endif

.if defined(WITH_FORTRAN)
PKGNAMESUFFIX=	-fortran
USE_FORTRAN=	yes
CONFIGURE_ENV+=	CMAKE_Fortran_COMPILER=${FC}
PLIST_SUB+=	FORTRAN=""
.else
CMAKE_ARGS+=	-DENABLE_f95:BOOL=OFF -DENABLE_f77:BOOL=OFF
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if defined(WITH_PYTHON)
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13	\
		f2py:${PORTSDIR}/math/py-numpy
RUN_DEPENDS+=	f2py:${PORTSDIR}/math/py-numpy
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
CONFIGURE_ENV+=	PYTHON_VERSION="${PYTHON_VERSION}"
.else
CMAKE_ARGS+=	-DENABLE_python:BOOL=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

.if defined(WITH_TCLTK)
.undef WITHOUT_X11
PKGNAMESUFFIX=	-tcltk
LIB_DEPENDS+=	itk.3:${PORTSDIR}/x11-toolkits/itk
USE_TK=		84
ITCL_VER=	3.3
CONFIGURE_ENV+=	ENABLE_tcl=TRUE ENABLE_tk=TRUE		\
		ENABLE_itcl=TRUE ENABLE_itk=TRUE
MAN1+=		plserver.1 pltcl.1
PLIST_SUB+=	TCLTK=""
.else
CMAKE_ARGS+=	-DENABLE_tk:BOOL=OFF
PLIST_SUB+=	TCLTK="@comment "
.endif

.if defined(WITH_QT)
.undef WITHOUT_X11
PKGNAMESUFFIX=	-qt
USE_QT_VER=	4
QT_COMPONENTS=	assistant assistantclient clucene corelib dbus	\
		designer doc gui help help-tools linguist moc	\
		network opengl phonon qmake qt3support qtestlib	\
		rcc script scripttools sql svg uic uic3 webkit	\
		xml xmlpatterns
PLIST_SUB+=	QT=""
.else
CMAKE_ARGS+=	-DENABLE_qt:BOOL=OFF -DDEFAULT_NO_QT_DEVICES:BOOL=ON
PLIST_SUB+=	QT="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "PLplot has the following tunable options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITHOUT_PTHREAD=yes	Turns off pthread support"
	@${ECHO_MSG} "	WITHOUT_X11=yes		Turns off X11 support"
	@${ECHO_MSG} "	WITH_FORTRAN=yes	Turns on Fortran support"
	@${ECHO_MSG} "	WITH_PYTHON=yes		Turns on Python support"
	@${ECHO_MSG} "	WITH_QT=yes		Turns on Qt4 support"
	@${ECHO_MSG} "	WITH_TCLTK=yes		Turns on Tcl/Tk support"
	@${ECHO_MSG} ""

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share/fonts/truetype/freefont|${LOCALBASE}/lib/X11/fonts/freefont-ttf|'\
		${WRKSRC}/cmake/modules/freetype.cmake
.if defined(WITHOUT_X11)
	${REINPLACE_CMD} -e 's|^find_package(X11)|SET(X11_FOUND "FALSE")|' \
		${WRKSRC}/cmake/modules/plplot.cmake
.endif
.if defined(WITH_TCLTK)
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|; \
		s|/usr/include|${LOCALBASE}/include|'		\
		${WRKSRC}/cmake/modules/FindTCL.cmake
	${REINPLACE_CMD} -e 's|%%ITCL_VER%%|${ITCL_VER}|'	\
		${WRKSRC}/cmake/modules/tcl-related.cmake
# To be removed when x11-toolkits/itk will be compatible with tk-8.5
. for fc in TCL Tclsh
	${REINPLACE_CMD} -e 's|8.5||g;s|85||g'	\
		${WRKSRC}/cmake/modules/Find${fc}.cmake
. endfor
.endif

.include <bsd.port.post.mk>
