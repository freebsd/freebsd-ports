# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plplot
PORTVERSION=	5.11.1
PORTREVISION=	5
CATEGORIES=	math science
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20Source

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Scientific plotting package

LICENSE=	LGPL21+

BUILD_DEPENDS=	bash:shells/bash \
		${FREEFONT_DIR}/FreeMono.ttf:x11-fonts/freefont-ttf
LIB_DEPENDS=	libLASi.so:devel/lasi \
		libltdl.so:devel/libltdl \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	bash:shells/bash \
		${FREEFONT_DIR}/FreeMono.ttf:x11-fonts/freefont-ttf

USE_GNOME=	pango
USE_PERL5=	build
USES=		cmake ghostscript gmake localbase perl5 pathfix pkgconfig
CMAKE_ARGS=	-DENABLE_java:BOOL=OFF \
		-DENABLE_octave:BOOL=OFF \
		-DENABLE_pdl:BOOL=OFF \
		-DENABLE_ada:BOOL=OFF \
		-DENABLE_d:BOOL=OFF \
		-DENABLE_ocaml:BOOL=OFF \
		-DENABLE_pyqt4:BOOL=OFF \
		-DPL_FREETYPE_FONT_PATH:PATH="${FREEFONT_DIR}" \
		-DCMAKE_INSTALL_PKG_CONFIG_DIR:PATH="${PREFIX}/libdata/pkgconfig" \
		-DPLD_plmeta:BOOL=OFF
CFLAGS+=	-D_IS_BUILDING_PLPLOT_PORT_
USE_LDCONFIG=	yes

FREEFONT_DIR=	${LOCALBASE}/share/fonts/freefont-ttf

OPTIONS_DEFINE=	FORTRAN GD LUA PYTHON QT4 TCLTK THREADS WXGTK X11 DOCS
OPTIONS_RADIO=	QHULL
OPTIONS_RADIO_QHULL=	QHULL2012 QHULL2003
OPTIONS_DEFAULT=	QHULL2012 THREADS X11
OPTIONS_SUB=	yes

FORTRAN_USES=		fortran
FORTRAN_CONFIGURE_ENV=	CMAKE_Fortran_COMPILER="${FC}"
FORTRAN_CMAKE_ON=	-DENABLE_f95:BOOL=ON
FORTRAN_CMAKE_OFF=	-DENABLE_f95:BOOL=OFF

GD_LIB_DEPENDS=		libgd.so:graphics/gd
GD_CMAKE_ON=		-DPLD_png:BOOL=ON

LUA_USES=		lua:51
LUA_CMAKE_ON=		-DLUA_EXECUTABLE:FILEPATH="${LUA_CMD}"
LUA_CMAKE_OFF=		-DENABLE_lua:BOOL=OFF

PYTHON_USES=		python
PYTHON_BUILD_DEPENDS=	swig:devel/swig13 \
			${PYNUMPY}
PYTHON_RUN_DEPENDS=	${PYNUMPY}
PYTHON_CONFIGURE_ENV=	PYTHON_VERSION="${PYTHON_VERSION}"
PYTHON_CMAKE_OFF=	-DENABLE_python:BOOL=OFF

QHULL2003_DESC=		Legacy Qhull support
QHULL2012_DESC=		Latest Qhull support
QHULL2012_LIB_DEPENDS=	libqhull.so.6:math/qhull
QHULL2003_LIB_DEPENDS=	libqhull.so.5:math/qhull5
QHULL2012_CMAKE_ON=	-DQHULL_INCLUDE_DIRS="${LOCALBASE}/include/libqhull"
QHULL2012_2FIX=		lib/nn/delaunay.c src/plgridd.c

TCLTK_LIB_DEPENDS=	libitk.so:x11-toolkits/itk
TCLTK_RUN_DEPENDS=	iwidgets>0:x11-toolkits/iwidgets
TCLTK_USES=		tk
ITCL_VER=		3.4
ITK_VER=		3.3
IWIDGETS_VER=		4.0.1
TCLTK_CMAKE_ON=		-DPLPLOT_TK_VERSION="${TK_VER}" \
			-DPLPLOT_ITCL_VERSION="${ITCL_VER}" \
			-DPLPLOT_ITK_VERSION="${ITK_VER}" \
			-DIWIDGETS_VERSIONS_LIST:STRING="${IWIDGETS_VER};${ITK_VER};${ITCL_VER}" \
			-DTCL_TCLSH:FILEPATH="${TCLSH}" \
			-DTCL_INCLUDE_PATH:PATH="${TCL_INCLUDEDIR}" \
			-DITCL_INCLUDE_PATH:PATH="${LOCALBASE}/include/itcl${ITCL_VER}" \
			-DITCL_LIBRARY:FILEPATH="${LOCALBASE}/lib/libitcl.so" \
			-DTK_INCLUDE_PATH:PATH="${TK_INCLUDEDIR}" \
			-DITK_INCLUDE_PATH:PATH="${LOCALBASE}/include/itk${ITK_VER}" \
			-DITK_LIBRARY:FILEPATH="${LOCALBASE}/lib/libitk.so"
TCLTK_CMAKE_OFF=	-DENABLE_tcl:BOOL=OFF

THREADS_CMAKE_OFF=	-DTHREADS_HAVE_PTHREAD_ARG:BOOL=OFF

QT4_USE=		QT4=corelib,gui,svg,xml,moc_build,qmake_build,rcc_build,uic_build
QT4_CMAKE_OFF=		-DENABLE_qt:BOOL=OFF -DDEFAULT_NO_QT_DEVICES:BOOL=ON

WXGTK_LIB_DEPENDS=	libagg.so:graphics/agg
WXGTK_USE=		WX=2.6+
WXGTK_CMAKE_ON=		-DwxWidgets_CONFIG_EXECUTABLE:FILEPATH="${WX_CONFIG}"
WXGTK_CMAKE_OFF=	-DENABLE_wxwidgets:BOOL=OFF

X11_USE=		XORG=ice,sm,x11,xext
X11_CMAKE_OFF=		-DPLD_xcairo:BOOL=OFF -DPLD_xwin:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTCLTK} && empty(PORT_OPTIONS:MX11)
IGNORE=		option TCLTK needs X11 support
.endif

pre-configure:
	${REINPLACE_CMD} -e \
		's|dl dlopen|c dlopen|' \
		${WRKSRC}/cmake/modules/FindLTDL.cmake
	${GREP} -lR "/usr/local" ${WRKSRC}/cmake/modules | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g'
.if ${PORT_OPTIONS:MQHULL2012}
. for src in ${QHULL2012_2FIX}
	${REINPLACE_CMD} -e 's|qhull/qhull_a|libqhull/qhull_a|'	\
		${WRKSRC}/${src}
. endfor
.endif

.include <bsd.port.mk>
