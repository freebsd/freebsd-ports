# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	saga
PORTVERSION=	2.1.0
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]*$//}/SAGA%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	System for Automated Geoscientific Analyses

LICENSE=	GPLv2

LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj \
		libgdal.so:${PORTSDIR}/graphics/gdal \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libiodbc.so:${PORTSDIR}/databases/libiodbc \
		liblas.so:${PORTSDIR}/devel/liblas \
		libopencv_core.so:${PORTSDIR}/graphics/opencv-core

USES=		dos2unix zip compiler:features
DOS2UNIX_GLOB=	dlg_about.cpp
USE_WX=		3.0
WX_UNICODE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf autoheader automake aclocal libtoolize
AUTOMAKE_ARGS=	--add-missing

DESKTOP_ENTRIES=	"SAGA GIS" "${COMMENT}" "${DATADIR}/saga.png" \
			"saga_gui" "Science;Geoscience;Math;" true

OPTIONS_DEFINE=	PYTHON OPENMP HARU VIGRA
OPTIONS_DEFAULT=	OPENMP HARU VIGRA
NO_OPTIONS_SORT=	yes
OPENMP_DESC=	Enable Multiprocessing
HARU_DESC=	Enable Haru Free PDF Library
VIGRA_DESC=	Enable 'Vision with Generic Algorithms' Library

.include <bsd.port.options.mk>

LDFLAGS+=	-L${LOCALBASE}/lib -lopencv_core
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--enable-python
BUILD_DEPENDS+=	swig2.0:${PORTSDIR}/devel/swig20
RUN_DEPENDS+=	swig2.0:${PORTSDIR}/devel/swig20
CONFIGURE_ENV+=	SWIG="${LOCALBASE}/bin/swig2.0"
USE_PYTHON=	2
PLIST_SUB+=	SAGA_PYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	SAGA_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MOPENMP}
LDFLAGS+=		${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--enable-openmp
.else
CONFIGURE_ARGS+=	--disable-openmp
.endif

.if ${PORT_OPTIONS:MHARU}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libhpdf.so:${PORTSDIR}/print/libharu
RUN_DEPENDS+=	${LOCALBASE}/lib/libhpdf.so:${PORTSDIR}/print/libharu
PLIST_SUB+=	HARU=""
.else
CFLAGS+=	-D_SAGA_DONOTUSE_HARU
PLIST_SUB+=	HARU="@comment "
.endif

.if ${PORT_OPTIONS:MVIGRA}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libvigraimpex.so:${PORTSDIR}/graphics/vigra
RUN_DEPENDS+=	${LOCALBASE}/lib/libvigraimpex.so:${PORTSDIR}/graphics/vigra
PLIST_SUB+=	VIGRA=""
.else
PLIST_SUB+=	VIGRA="@comment "
.endif

.include <bsd.port.pre.mk>

# Late define USE_GCC (openmp support)
# and make g++ use libc++ is possible
USE_GCC=	any

.if ${COMPILER_FEATURES:Mlibc++}
LDFLAGS+=	-L${LOCALBASE}/lib/c++
CXXFLAGS+=	-nostdinc++ -isystem ${LOCALBASE}/include/c++/v1
BUILD_DEPENDS+=	${LOCALBASE}/lib/c++/libstdc++.so:${PORTSDIR}/devel/libc++
.else

.endif

post-extract:
	@${REINPLACE_CMD} -e's|wx-config |${WX_CONFIG} |g' \
		${WRKSRC}/configure.in \
		${WRKSRC}/src/saga_core/saga_gui/Makefile.am \
		${WRKSRC}/src/saga_core/saga_api/Makefile.am \
		${WRKSRC}/src/saga_core/saga_cmd/Makefile.am \
		${WRKSRC}/src/saga_core/saga_gdi/Makefile.am \
		${WRKSRC}/src/modules_contrib/garden/garden_webservices/Makefile.am \
		${WRKSRC}/src/modules_contrib/garden/garden_3d_viewer/Makefile.am \
		${WRKSRC}/src/modules_io/shapes/io_shapes/Makefile.am \
		${WRKSRC}/src/modules_io/grid/io_grid_image/Makefile.am \
		${WRKSRC}/src/modules/pointcloud/pointcloud_tools/Makefile.am \
		${WRKSRC}/src/modules/pointcloud/pointcloud_viewer/Makefile.am \
		${WRKSRC}/src/modules/tin/tin_viewer/Makefile.am \
		${WRKSRC}/src/modules_geostatistics/geostatistics/geostatistics_kriging/Makefile.am

post-patch:
	@${REINPLACE_CMD} -e 's|-lcv|-lopencv_core -lopencv_imgproc|g' \
		${WRKSRC}/src/modules_images/modules_opencv/opencv/Makefile.am
	@${REINPLACE_CMD} -e 's|\[cv\]|\[opencv_core\]|' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|\\n"), SAGA_VERSION)| (rev. 1760)\\n"), SAGA_VERSION)|' \
		${WRKSRC}/src/saga_core/saga_gui/dlg_about.cpp
.if ${ARCH} == "i386" || ${ARCH} == "powerpc"
	@${REINPLACE_CMD} -e 's|typedef unsigned long	DWORD;|typedef unsigned int	DWORD;|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga_tip.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.png ${STAGEDIR}${DATADIR}
# library helper files are not needed and cripple some math/qgis extensions
	@${RM} ${STAGEDIR}${PREFIX}/lib/saga/*.la
	@${RM} ${STAGEDIR}${PREFIX}/lib/saga/*.a

.include <bsd.port.post.mk>
