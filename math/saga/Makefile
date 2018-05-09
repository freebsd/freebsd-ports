# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	saga
PORTVERSION=	6.1.0
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]\.[[:digit:]]*$//}/SAGA%20-%20${PORTVERSION}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	System for Automated Geoscientific Analyses

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libgdal.so:graphics/gdal \
		libhpdf.so:print/libharu \
		libjasper.so:graphics/jasper \
		liblas.so:devel/liblas12 \
		libodbc.so:databases/unixODBC \
		libopencv_core.so:graphics/opencv-core \
		libopencv_ml.so:graphics/opencv \
		libproj.so:graphics/proj \
		libsvm.so:science/libsvm \
		libtbb.so:devel/tbb \
		libtiff.so:graphics/tiff
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		autoreconf compiler:gcc-c++11-lib desktop-file-utils dos2unix \
		iconv:wchar_t libtool localbase pkgconfig python:2.7
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
USE_WX=		3.0+
CONFIGURE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		--enable-python --with-system-svm
CONFIGURE_ENV=	SWIG="${LOCALBASE}/bin/swig3.0"
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

INSTALLS_ICONS=	yes
DOS2UNIX_GLOB=	*.cpp *.h
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	PGSQL OPENMP VIGRA
OPTIONS_DEFAULT=	PGSQL OPENMP VIGRA
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=	yes
OPENMP_DESC=	Enable Multiprocessing
VIGRA_DESC=	Enable 'Vision with Generic Algorithms' Library

OPENMP_CONFIGURE_ENABLE=	openmp
OPENMP_LDFLAGS=		-pthread
PGSQL_CONFIGURE_OFF=	--with-postgresql=no
PGSQL_CONFIGURE_ON=	--with-postgresql=${LOCALBASE}/bin/pg_config
PGSQL_USES=		pgsql
VIGRA_BUILD_DEPENDS=	${LOCALBASE}/lib/libvigraimpex.so:graphics/vigra
VIGRA_RUN_DEPENDS=	${LOCALBASE}/lib/libvigraimpex.so:graphics/vigra

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message

post-extract:
	@${REINPLACE_CMD} -e 's|wx-config |${WX_CONFIG} |g' \
		${WRKSRC}/configure.ac \
		${WRKSRC}/src/saga_core/saga_api/Makefile.am \
		${WRKSRC}/src/saga_core/saga_cmd/Makefile.am \
		${WRKSRC}/src/saga_core/saga_gdi/Makefile.am \
		${WRKSRC}/src/saga_core/saga_gui/Makefile.am \
		${WRKSRC}/src/tools/garden/garden_3d_viewer/Makefile.am \
		${WRKSRC}/src/tools/garden/garden_webservices/Makefile.am \
		${WRKSRC}/src/tools/io/io_grid_image/Makefile.am \
		${WRKSRC}/src/tools/io/io_shapes/Makefile.am \
		${WRKSRC}/src/tools/io/io_virtual/Makefile.am \
		${WRKSRC}/src/tools/pointcloud/pointcloud_tools/Makefile.am \
		${WRKSRC}/src/tools/pointcloud/pointcloud_viewer/Makefile.am \
		${WRKSRC}/src/tools/statistics/statistics_kriging/Makefile.am \
		${WRKSRC}/src/tools/tin/tin_viewer/Makefile.am
	@${REINPLACE_CMD} -e 's|/usr/include/opencv|${LOCALBASE}/include/opencv ${LOCALBASE}/include|g' \
		${WRKSRC}/src/tools/imagery/imagery_opencv/Makefile.am

post-patch:
.if ${ARCH} == "powerpc"
	@${REINPLACE_CMD} -e 's|typedef unsigned long	DWORD;|typedef unsigned int	DWORD;|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h
.endif
	@${REINPLACE_CMD} -e 's|PORTVERSION|${PORTVERSION}|' \
		${WRKSRC}/src/saga_core/saga_gui/dlg_about.cpp

post-configure:
	@${REINPLACE_CMD} -e 's|cd $$(pkgdatadir);|cd ${STAGEDIR}${DATADIR};|g' \
		${WRKSRC}/src/saga_core/saga_gui/Makefile
	@${REINPLACE_CMD} -e 's|^LDFLAGS = .*|& -lopencv_contrib|' \
		${WRKSRC}/src/tools/imagery/imagery_opencv/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga*.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.png ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/saga_dic.txt ${STAGEDIR}${DATADIR}/saga_srs.txt
# toolchains dir was moved in r2805 (and followups r2810,r2811,r2820)
	${MKDIR} ${STAGEDIR}${DATADIR}/accessories
	(cd ${WRKSRC}/src/accessories && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/accessories)
	${RM} -R ${STAGEDIR}${DATADIR}/accessories/toolchains
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
# library helper files are not needed and cripple some math/qgis extensions
	@${RM} ${STAGEDIR}${PREFIX}/lib/saga/*.la

.include <bsd.port.post.mk>
