# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	cdo
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://code.zmaw.de/attachments/download/5824/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Climate Data Operators

LICENSE=	GPLv2

OPTIONS_DEFINE=	HDF5 JASPER NETCDF PROJ SZIP
OPTIONS_DEFAULT=HDF5 NETCDF PROJ SZIP
OPTIONS_SUB=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-cdi-lib --program-transform-name="" --with-zlib=/usr
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -pthread
USE_LDCONFIG=	yes
USES=		gmake pathfix

HDF5_CONFIGURE_ARGS=	--with-hdf5=${LOCALBASE}
HDF5_LIB_DEPENDS=	libhdf5.so:${PORTSDIR}/science/hdf5-18
JASPER_CONFIGURE_ARGS=	--with-jasper=${LOCALBASE}
JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
NETCDF_CONFIGURE_ARGS=	--with-netcdf=${LOCALBASE}
NETCDF_LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf4
PROJ_CONFIGURE_ARGS=	--with-proj=${LOCALBASE}
PROJ_LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj
SZIP_CONFIGURE_ARGS=	--with-szlib=${LOCALBASE}
SZIP_LIB_DEPENDS=	libsz.so:${PORTSDIR}/science/szip

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
.if ${PORT_OPTIONS:MNETCDF}
	@${REINPLACE_CMD} \
		-e '/bin_PROGRAMS = / s|$$| cdotest|' \
		-e '/noinst_PROGRAMS = / s| cdotest||' \
			${WRKSRC}/src/Makefile.in
.endif

post-build:
.if ${PORT_OPTIONS:MNETCDF}
	@cd ${WRKSRC}/src/ && ${SETENV} CDO_PATH=${WRKSRC}/src/cdo ${WRKSRC}/src/cdotest
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcdi.so.0

regression-test test: build
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.post.mk>
