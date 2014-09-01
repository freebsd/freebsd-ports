# Created by: anholt@FreeBSD.org
# $FreeBSD$

PORTNAME=	paraview
PORTVERSION=	4.1.0
PORTREVISION=	4
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v${VERMAJORMINOR}/
DISTNAME=	ParaView-v${PORTVERSION}-source

MAINTAINER=	devel@stasyan.com
COMMENT=	Powerful scientific data visualization application

LICENSE=	ParaView_License_1.2
LICENSE_NAME=	ParaView_License
LICENSE_FILE=	${PATCH_WRKSRC}/License_v1.2.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/matplotlib/pyplot.py:${PORTSDIR}/math/py-matplotlib
LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5 \
		libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		liborc-0.4.so:${PORTSDIR}/devel/orc \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libffi.so:${PORTSDIR}/devel/libffi \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash	\
		${PYTHON_SITELIBDIR}/matplotlib/pyplot.py:${PORTSDIR}/math/py-matplotlib

USE_QT4=	qmake_build moc_build rcc_build uic_build \
		linguist_build assistant_run qt3support \
		dbus designer gui help-tools network script \
		sql svg xml webkit assistantclient clucene \
		xmlpatterns xmlpatterns-tool help
USE_GL=		yes
USE_XORG=	x11 xt xext ice xdmcp xau xcb xfixes xdamage xxf86vm xrender sm
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GSTREAMER=	yes
USES=		cmake:outsource gmake execinfo shebangfix

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS="ON" \
		-DVTK_USE_SYSTEM_PNG="ON" \
		-DVTK_USE_SYSTEM_JPEG="ON" \
		-DVTK_USE_SYSTEM_TIFF="ON" \
		-DVTK_USE_SYSTEM_ZLIB="ON" \
		-DVTK_USE_SYSTEM_FREETYPE="ON" \
		-DVTK_USE_SYSTEM_EXPAT="ON" \
		-DVTK_USE_X="ON" \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T=1 \
		-DPARAVIEW_ENABLE_PYTHON:BOOL="ON" \
		-DPARAVIEW_ENABLE_FFMPEG:BOOL="OFF" \
		-DBUILD_TESTING:BOOL="OFF" \
		-DExternalData_OBJECT_STORES="${WRKDIR}/VTK/ExternalData/MD5"
MAKE_ENV=	XDG_CONFIG_HOME=${WRKDIR}

SHEBANG_FILES=	Catalyst/catalyze.py VTK/Examples/SearchScript.sh \
		VTK/Utilities/Maintenance/*.sh	\
		Web/Applications/Parallel/server/launcher.sh \
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/bench/basicbench.cxxlist	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/bench/*.sh	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/bench/bench_unrolling	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/bench/benchmark_suite	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/blas/testing/*	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/scripts/*	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/test/eigen2/*	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/test/*.sh	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/test/testsuite.cmake	\
		Plugins/SciberQuestToolKit/eigen-3.0.3/eigen-eigen-3.0.3/bench/btl/data/*

OPTIONS_DEFINE=	OSMESA GL2PS DOCS
OSMESA_DESC=	Use Mesa for off-screen rendering
GL2PS_DESC=	Install support conversion OpenGL to PostScript
#		VTKMPEG2	"Install patented MPEG2 encoder module" Off \

VERMAJORMINOR=	${PORTVERSION:R}
WRKSRC=		${WRKDIR}/ParaView-v${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOSMESA}
LIB_DEPENDS+=	libOSMesa32.so:${PORTSDIR}/graphics/libosmesa
CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
		-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa32.so
.endif

.if ${PORT_OPTIONS:MGL2PS}
LIB_DEPENDS+=	libgl2ps.so:${PORTSDIR}/print/gl2ps
CMAKE_ARGS+=	-DVTK_USE_GL2PS:BOOL=ON
PLIST_SUB+=	GL2PS=""
.else
PLIST_SUB+=	GL2PS="@comment "
.endif

PLIST_SUB+=	VERMAJORMINOR=${VERMAJORMINOR}
CMAKE2INST=	ParaViewConfig.cmake \
		cmake_install.cmake
LIB_INSTDIR=	${PREFIX}/lib/${PORTNAME}-${VERMAJORMINOR}

pre-configure:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${PATCH_WRKSRC}/VTK/IO/Image/vtkPNGReader.cxx
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|'	\
		${PATCH_WRKSRC}/VTK/Testing/Core/vtk_site_history.py

post-install:
.for c2f in ${CMAKE2INST}
	${SED} -e 's|${BUILD_WRKSRC}|${LIB_INSTDIR}|g' \
		-e 's|${PATCH_WRKSRC}|${LIB_INSTDIR}|g' \
		${BUILD_WRKSRC}/${c2f} > ${STAGEDIR}${LIB_INSTDIR}/`${BASENAME} ${c2f}`
.endfor
	${INSTALL_DATA} ${PATCH_WRKSRC}/CMake/UseParaView.cmake \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}-${VERMAJORMINOR}

.include <bsd.port.mk>
