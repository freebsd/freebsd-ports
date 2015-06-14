# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	cdo
PORTVERSION=	1.6.9
CATEGORIES=	science
MASTER_SITES=	https://code.zmaw.de/attachments/download/10198/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Climate Data Operators

LICENSE=	GPLv2

OPTIONS_DEFINE=	CGRIBEX HDF5 JASPER NETCDF PROJ SZIP UDUNITS
OPTIONS_DEFAULT=CGRIBEX HDF5 JASPER NETCDF PROJ SZIP UDUNITS
OPTIONS_SUB=	yes

PORTSCOUT=	site:https://code.zmaw.de/projects/cdo/files

CONFIGURE_ARGS=	--disable-cgribex \
		--disable-data \
		--disable-extra \
		--disable-grib \
		--disable-ieg \
		--disable-service \
		--enable-cdi-lib \
		--program-transform-name="" \
		--with-zlib=/usr
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix

CGRIBEX_CONFIGURE_OFF=	--without-cgribex
CGRIBEX_CONFIGURE_ON=	--with-cgribex=${LOCALBASE}
CGRIBEX_LIB_DEPENDS=	libcgribex.so:${PORTSDIR}/science/cgribex
HDF5_CONFIGURE_OFF=	--without-hdf5
HDF5_CONFIGURE_ON=	--with-hdf5=${LOCALBASE}
HDF5_LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5
JASPER_CONFIGURE_OFF=	--without-jasper
JASPER_CONFIGURE_ON=	--with-jasper=${LOCALBASE}
JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
NETCDF_CONFIGURE_OFF=	--without-netcdf
NETCDF_CONFIGURE_ON=	--with-netcdf=${LOCALBASE}
NETCDF_LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf
PROJ_CONFIGURE_OFF=	--without-proj
PROJ_CONFIGURE_ON=	--with-proj=${LOCALBASE}
PROJ_LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj
SZIP_CONFIGURE_OFF=	--without-szlib
SZIP_CONFIGURE_ON=	--with-szlib=${LOCALBASE}
SZIP_LIB_DEPENDS=	libsz.so:${PORTSDIR}/science/szip
UDUNITS_CONFIGURE_OFF=	--without-udunits2
UDUNITS_CONFIGURE_ON=	--with-udunits2=${LOCALBASE}
UDUNITS_LIB_DEPENDS=	libudunits2.so:${PORTSDIR}/science/udunits

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHDF5} && !${PORT_OPTIONS:MSZIP}
IGNORE=		HDF5 option requires SZIP option
.endif

.if ${PORT_OPTIONS:MNETCDF} && !${PORT_OPTIONS:MHDF5}
IGNORE=		NETCDF option requires HDF5 option
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64"
CFLAGS+=	-DPTHREAD_MUTEXATTR_CONDATTR
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/\($$$$pkgconfigfile\)|${PREFIX}/libdata/\1|' ${WRKSRC}/libcdi/src/Makefile.in
	@${REINPLACE_CMD} -e 's|unsigned32 |uint32_t |' ${WRKSRC}/libcdi/src/cdilib.c ${WRKSRC}/libcdi/src/util.c

regression-test test: build
.if ${PORT_OPTIONS:MNETCDF}
	@cd ${WRKSRC}/ && ${SETENV} CDO_PATH=src/cdo src/cdotest
.endif
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.post.mk>
