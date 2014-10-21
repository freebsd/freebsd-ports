# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	saga
PORTVERSION=	2.1.2
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	SF/saga-gis/SAGA%20-%20${PORTVERSION:C/\.[[:digit:]]*$//}/SAGA%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	System for Automated Geoscientific Analyses

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20
LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj \
		libgdal.so:${PORTSDIR}/graphics/gdal \
		libhpdf.so:${PORTSDIR}/print/libharu \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libodbc.so:${PORTSDIR}/databases/unixODBC \
		liblas.so:${PORTSDIR}/devel/liblas \
		libopencv_ml.so:${PORTSDIR}/graphics/opencv
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFIGURE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		--enable-python
CONFIGURE_ENV=	SWIG="${LOCALBASE}/bin/swig2.0"
CFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lopencv_contrib
# Python no option any more, because it can't be turned off completely
USE_LDCONFIG=	yes
USE_WX=		3.0+
USES=		compiler:gcc-c++11-lib iconv:wchar_t dos2unix libtool python:2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WX_UNICODE=	yes

DESKTOP_ENTRIES=	"SAGA GIS" "${COMMENT}" "${DATADIR}/saga.png" \
			"saga_gui" "Science;Geoscience;Math;" true
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
PGSQL_LIB_DEPENDS=	libpq.so:${PORTSDIR}/databases/postgresql93-client
VIGRA_BUILD_DEPENDS=	${LOCALBASE}/lib/libvigraimpex.so:${PORTSDIR}/graphics/vigra
VIGRA_RUN_DEPENDS=	${LOCALBASE}/lib/libvigraimpex.so:${PORTSDIR}/graphics/vigra

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e's|wx-config |${WX_CONFIG} |g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/saga_core/saga_gui/Makefile.in \
		${WRKSRC}/src/saga_core/saga_api/Makefile.in \
		${WRKSRC}/src/saga_core/saga_cmd/Makefile.in \
		${WRKSRC}/src/saga_core/saga_gdi/Makefile.in \
		${WRKSRC}/src/modules/garden/garden_webservices/Makefile.in \
		${WRKSRC}/src/modules/garden/garden_3d_viewer/Makefile.in \
		${WRKSRC}/src/modules/io/io_shapes/Makefile.in \
		${WRKSRC}/src/modules/io/io_grid_image/Makefile.in \
		${WRKSRC}/src/modules/pointcloud/pointcloud_tools/Makefile.in \
		${WRKSRC}/src/modules/pointcloud/pointcloud_viewer/Makefile.in \
		${WRKSRC}/src/modules/tin/tin_viewer/Makefile.in \
		${WRKSRC}/src/modules/statistics/statistics_kriging/Makefile.in
	@${REINPLACE_CMD} -e 's|-lcv|-lopencv_core -lopencv_imgproc|g' \
		${WRKSRC}/src/modules/imagery/imagery_opencv/Makefile.in
	@${REINPLACE_CMD} -e 's|lib_cv|lib_opencv_core|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lcv |-lopencv_core |' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\\n"), SAGA_VERSION)| (rev. 2121)\\n"), SAGA_VERSION)|' \
		${WRKSRC}/src/saga_core/saga_gui/dlg_about.cpp
.if ${ARCH} == "powerpc"
	@${REINPLACE_CMD} -e 's|typedef unsigned long	DWORD;|typedef unsigned int	DWORD;|' \
		${WRKSRC}/src/saga_core/saga_api/api_core.h
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|cd $$(pkgdatadir);|cd ${STAGEDIR}${DATADIR};|g' \
		${WRKSRC}/src/saga_core/saga_gui/Makefile
	@${REINPLACE_CMD} -e 's|mv saga_srs.txt saga_prj.srs|mv \
		${STAGEDIR}${DATADIR}/saga_srs.txt \
		${STAGEDIR}${DATADIR}/saga_prj.srs|g' \
		${WRKSRC}/src/saga_core/saga_gui/Makefile
	@${REINPLACE_CMD} -e 's|mv saga_dic.txt saga_prj.dic|mv \
		${STAGEDIR}${DATADIR}/saga_dic.txt \
		${STAGEDIR}${DATADIR}/saga_prj.dic|g' \
		${WRKSRC}/src/saga_core/saga_gui/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga_tip.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.lng.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.ger.txt ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.png ${STAGEDIR}${DATADIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsaga_api-${PORTVERSION}.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_saga_api-${PORTVERSION}.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsaga_gdi-${PORTVERSION}.so
	${INSTALL_DATA} ${WRKSRC}/src/saga_core/saga_gui/res/saga.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/saga/*.so
# library helper files are not needed and cripple some math/qgis extensions
	@${RM} ${STAGEDIR}${PREFIX}/lib/saga/*.la

.include <bsd.port.post.mk>
