# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	saga
PORTVERSION=	2.3.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]*$//}/SAGA%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

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
		libopencv_ml.so:graphics/opencv2 \
		libopencv_core.so:graphics/opencv2-core \
		libproj.so:graphics/proj \
		libtbb.so:devel/tbb \
		libtiff.so:graphics/tiff
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFIGURE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		--enable-python
CONFIGURE_ENV=	SWIG="${LOCALBASE}/bin/swig3.0"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_CXXSTD=	c++11
USE_WX=		3.0+
USES=		autoreconf libtool localbase compiler:gcc-c++11-lib \
		iconv:wchar_t dos2unix python:2
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

.include <bsd.port.pre.mk>

SUB_FILES=	pkg-message

post-extract:
	@${REINPLACE_CMD} -e 's|wx-config |${WX_CONFIG} |g' \
		${WRKSRC}/configure.ac \
		${WRKSRC}/src/saga_core/saga_api/Makefile.am \
		${WRKSRC}/src/saga_core/saga_cmd/Makefile.am \
		${WRKSRC}/src/saga_core/saga_gdi/Makefile.am \
		${WRKSRC}/src/saga_core/saga_gui/Makefile.am \
		${WRKSRC}/src/modules/garden/garden_3d_viewer/Makefile.am \
		${WRKSRC}/src/modules/garden/garden_webservices/Makefile.am \
		${WRKSRC}/src/modules/io/io_grid_image/Makefile.am \
		${WRKSRC}/src/modules/io/io_shapes/Makefile.am \
		${WRKSRC}/src/modules/io/io_virtual/Makefile.am \
		${WRKSRC}/src/modules/pointcloud/pointcloud_tools/Makefile.am \
		${WRKSRC}/src/modules/pointcloud/pointcloud_viewer/Makefile.am \
		${WRKSRC}/src/modules/tin/tin_viewer/Makefile.am \
		${WRKSRC}/src/modules/statistics/statistics_kriging/Makefile.am
	@${REINPLACE_CMD} -e 's|/usr/include/opencv|${LOCALBASE}/include/opencv ${LOCALBASE}/include|g' \
		${WRKSRC}/src/modules/imagery/imagery_opencv/Makefile.am

post-patch:
.if ${ARCH} == "powerpc"
	@${REINPLACE_CMD} -e 's|typedef unsigned long	DWORD;|typedef unsigned int	DWORD;|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h
.endif
	@${REINPLACE_CMD} -e 's|PORTVERSION|${PORTVERSION:C/\./-/g}|' \
		${WRKSRC}/src/saga_core/saga_gui/dlg_about.cpp

post-configure:
	@${REINPLACE_CMD} -e 's|cd $$(pkgdatadir);|cd ${STAGEDIR}${DATADIR};|g' \
		${WRKSRC}/src/saga_core/saga_gui/Makefile
	@${REINPLACE_CMD} -e 's|^LDFLAGS = .*|& -lopencv_contrib|' \
		${WRKSRC}/src/modules/imagery/imagery_opencv/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga*.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.png ${STAGEDIR}${DATADIR}
	${RM} ${STAGEDIR}${DATADIR}/saga_dic.txt ${STAGEDIR}${DATADIR}/saga_srs.txt
# toolchains dir was moved in r2805 (and followups r2810,r2811,r2820)
	${MKDIR} ${STAGEDIR}${DATADIR}/scripting
	(cd ${WRKSRC}/src/scripting && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/scripting)
	@${RM} -R ${STAGEDIR}${DATADIR}/scripting/toolchains
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsaga_api-${PORTVERSION}.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_saga_api-${PORTVERSION}.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsaga_gdi-${PORTVERSION}.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/saga/*.so
# library helper files are not needed and cripple some math/qgis extensions
	@${RM} ${STAGEDIR}${PREFIX}/lib/saga/*.la

.include <bsd.port.post.mk>
