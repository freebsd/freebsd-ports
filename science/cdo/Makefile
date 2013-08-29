# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	cdo
PORTVERSION=	1.6.1
CATEGORIES=	science
MASTER_SITES=	https://code.zmaw.de/attachments/download/5824/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Climate Data Operators

OPTIONS_DEFINE=	HDF5 JASPER NETCDF PROJ SZIP
OPTIONS_DEFAULT=HDF5 NETCDF PROJ SZIP

CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-cdi-lib --program-transform-name="" --with-zlib=/usr
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -pthread
USE_LDCONFIG=	yes
USES=		gmake pathfix

HDF5_VER?=	18
NETCDF_VER?=	4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNETCDF} && ${PORT_OPTIONS:MHDF5} && ${NETCDF_VER} == 4 && ${HDF5_VER} == 16
IGNORE=		netCDF 4 requires HDF5 1.8
.endif

.if ${PORT_OPTIONS:MNETCDF} && (${NETCDF_VER} == 4)
HDF5_VER=	18
WITH_HDF5=	yes
.endif

.if ${PORT_OPTIONS:MHDF5}
CONFIGURE_ARGS+=--with-hdf5=${LOCALBASE}
WITH_SZIP=	yes
.if (${HDF5_VER} == 18)
LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18
.else
LIB_DEPENDS+=	hdf5.0:${PORTSDIR}/science/hdf5
.endif
.endif

.if ${PORT_OPTIONS:MJASPER}
CONFIGURE_ARGS+=--with-jasper=${LOCALBASE}
LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
.endif

.if ${PORT_OPTIONS:MNETCDF}
CONFIGURE_ARGS+=--with-netcdf=${LOCALBASE}
.if (${NETCDF_VER} == 4)
LIB_DEPENDS+=	netcdf.7:${PORTSDIR}/science/netcdf4
.else
LIB_DEPENDS+=	netcdf.4:${PORTSDIR}/science/netcdf
.endif
PLIST_SUB=	NETCDF=""
.else
PLIST_SUB=	NETCDF="@comment "
.endif

.if ${PORT_OPTIONS:MPROJ}
CONFIGURE_ARGS+=--with-proj=${LOCALBASE}
LIB_DEPENDS+=	proj:${PORTSDIR}/graphics/proj
.endif

.if ${PORT_OPTIONS:MSZIP}
CONFIGURE_ARGS+=--with-szlib=${LOCALBASE}
LIB_DEPENDS+=	sz:${PORTSDIR}/science/szip
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

regression-test test: build
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
