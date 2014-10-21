# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plplot
PORTVERSION=	5.10.0
PORTREVISION=	3
CATEGORIES=	math science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scientific plotting package

LICENSE=	LGPL21 # (or later)

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${FREEFONT_DIR}/FreeMono.ttf:${PORTSDIR}/x11-fonts/freefont-ttf
LIB_DEPENDS=	libLASi.so:${PORTSDIR}/devel/lasi \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libqhull.so:${PORTSDIR}/math/qhull5 \
		libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${FREEFONT_DIR}/FreeMono.ttf:${PORTSDIR}/x11-fonts/freefont-ttf

OPTIONS_DEFINE=	FORTRAN GD LUA PYTHON QT4 TCLTK THREADS WXGTK X11 DOCS
OPTIONS_DEFAULT=THREADS X11

USE_GNOME=	pango
USE_PERL5=	build
USE_GHOSTSCRIPT=yes
USES=		cmake gmake perl5 pkgconfig
CMAKE_ARGS=	-DENABLE_java:BOOL=OFF -DENABLE_octave:BOOL=OFF \
		-DENABLE_pdl:BOOL=OFF -DENABLE_ada:BOOL=OFF \
		-DENABLE_d:BOOL=OFF -DENABLE_ocaml:BOOL=OFF \
		-DENABLE_pyqt4:BOOL=OFF \
		-DPL_FREETYPE_FONT_PATH:PATH="${FREEFONT_DIR}" \
		-DPLD_plmeta:BOOL=OFF
CFLAGS+=	-D_IS_BUILDING_PLPLOT_PORT_
USE_LDCONFIG=	yes

FREEFONT_DIR=	${LOCALBASE}/lib/X11/fonts/freefont-ttf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFORTRAN}
USES+=		fortran
CONFIGURE_ENV+=	CMAKE_Fortran_COMPILER="${FC}"
CMAKE_ARGS+=	-DENABLE_f95:BOOL=ON -DENABLE_f77:BOOL=ON
PLIST_SUB+=	FORTRAN=""
.else
CMAKE_ARGS+=	-DENABLE_f95:BOOL=OFF -DENABLE_f77:BOOL=OFF
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if ${PORT_OPTIONS:MGD}
LIB_DEPENDS+=	libgd.so:${PORTSDIR}/graphics/gd
CMAKE_ARGS+=	-DPLD_png:BOOL=ON
PLIST_SUB+=	GD=""
.else
PLIST_SUB+=	GD="@comment "
.endif

.if ${PORT_OPTIONS:MLUA}
USES+=		lua:51
CMAKE_ARGS+=	-DLUA_EXECUTABLE:FILEPATH="${LUA_CMD}"
PLIST_SUB+=	LUA="" LUA_MODLIBDIR="${LUA_MODLIBDIR:S,${LUA_PREFIX}/,,}"
.else
CMAKE_ARGS+=	-DENABLE_lua:BOOL=OFF
PLIST_SUB+=	LUA="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
BUILD_DEPENDS+=	swig:${PORTSDIR}/devel/swig13 \
		${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
USES+=		python
PLIST_SUB+=	PYTHON=""
CONFIGURE_ENV+=	PYTHON_VERSION="${PYTHON_VERSION}"
.else
CMAKE_ARGS+=	-DENABLE_python:BOOL=OFF
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MTCLTK}
.if empty(PORT_OPTIONS:MX11)
IGNORE=		TCLTK needs X11 support
.endif
LIB_DEPENDS+=	libitk.so:${PORTSDIR}/x11-toolkits/itk
USES+=		tk
CMAKE_ARGS+=	-DTCL_TCLSH:FILEPATH="${TCLSH}" \
		-DTCL_INCLUDE_PATH:PATH="${TCL_INCLUDEDIR}" \
		-DITCL_INCLUDE_PATH:PATH="${LOCALBASE}/include/itcl3.4" \
		-DITCL_LIBRARY:FILEPATH="${LOCALBASE}/lib/libitcl.so" \
		-DTK_INCLUDE_PATH:PATH="${TK_INCLUDEDIR}" \
		-DITK_INCLUDE_PATH:PATH="${LOCALBASE}/include/itk3.3" \
		-DITK_LIBRARY:FILEPATH="${LOCALBASE}/lib/libitk.so"
PLIST_SUB+=	TCLTK=""
.else
CMAKE_ARGS+=	-DENABLE_tcl:BOOL=OFF
PLIST_SUB+=	TCLTK="@comment "
.endif

.if empty(PORT_OPTIONS:MTHREADS)
CMAKE_ARGS+=	-DTHREADS_HAVE_PTHREAD_ARG:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	corelib gui svg xml \
		moc_build qmake_build rcc_build uic_build
PLIST_SUB+=	QT4=""
.else
CMAKE_ARGS+=	-DENABLE_qt:BOOL=OFF -DDEFAULT_NO_QT_DEVICES:BOOL=ON
PLIST_SUB+=	QT4="@comment "
.endif

.if ${PORT_OPTIONS:MWXGTK}
LIB_DEPENDS+=	libagg.so:${PORTSDIR}/graphics/agg
USE_WX=		2.6+
CMAKE_ARGS+=	-DPLD_wxpng:BOOL=ON \
		-DwxWidgets_CONFIG_EXECUTABLE:FILEPATH="${WX_CONFIG}"
PLIST_SUB+=	WXGTK=""
.else
CMAKE_ARGS+=	-DENABLE_wxwidgets:BOOL=OFF
PLIST_SUB+=	WXGTK="@comment "
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	ice sm x11 xext
PLIST_SUB+=	X11=""
.else
CMAKE_ARGS+=	-DPLD_xcairo:BOOL=OFF -DPLD_xwin:BOOL=OFF
PLIST_SUB+=	X11="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e \
		's|dl dlopen|c dlopen|' \
		${WRKSRC}/cmake/modules/FindLTDL.cmake
	${GREP} -lR "/usr/local" ${WRKSRC}/cmake/modules | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g'

.include <bsd.port.mk>
