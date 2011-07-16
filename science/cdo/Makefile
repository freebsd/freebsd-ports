# New ports collection makefile for:	CDO
# Date created:			29 May 2006
# Whom:				Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	cdo
PORTVERSION=	1.5.1
CATEGORIES=	science
MASTER_SITES=	https://code.zmaw.de/attachments/download/1531/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Climate Data Operators

OPTIONS=	HDF5	"HDF5 support"		on \
		JASPER	"Japser support"	off \
		NETCDF	"NetCDF support"	on \
		PROJ	"PROJ support"		on \
		SZIP	"SZIP support"		on

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--enable-cdi-lib --program-transform-name="" --with-zlib=/usr
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

NETCDF_VER?=	4
HDF5_VER?=	18

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NETCDF) && !defined(WITHOUT_HDF5) && ${NETCDF_VER} == 4 && ${HDF5_VER} == 16
IGNORE=		netCDF 4 requires HDF5 1.8
.endif

.if !defined(WITHOUT_NETCDF) && (${NETCDF_VER} == 4)
HDF5_VER=	18
WITH_HDF5=	yes
.endif

.if !defined(WITHOUT_HDF5)
CONFIGURE_ARGS+=--with-hdf5=${LOCALBASE}
WITH_SZIP=	yes
.if (${HDF5_VER} == 18)
LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18
.else
LIB_DEPENDS+=	hdf5.0:${PORTSDIR}/science/hdf5
.endif
.endif

.if defined(WITH_JASPER)
CONFIGURE_ARGS+=--with-jasper=${LOCALBASE}
LIB_DEPENDS+=	jasper:${PORTSDIR}/graphics/jasper
.endif

.if !defined(WITHOUT_NETCDF)
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

.if !defined(WITHOUT_PROJ)
CONFIGURE_ARGS+=--with-proj=${LOCALBASE}
LIB_DEPENDS+=	proj.6:${PORTSDIR}/graphics/proj
.endif

.if !defined(WITHOUT_SZIP)
CONFIGURE_ARGS+=--with-szlib=${LOCALBASE}
LIB_DEPENDS+=	sz.2:${PORTSDIR}/science/szip
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "sparc64"
CFLAGS+=	-DPTHREAD_MUTEXATTR_CONDATTR
.endif

post-patch:
.if !defined(WITHOUT_NETCDF)
	@${REINPLACE_CMD} \
		-e '/bin_PROGRAMS = / s|$$| cdotest|' \
		-e '/noinst_PROGRAMS = / s| cdotest||' \
			${WRKSRC}/src/Makefile.in
.endif

post-build:
.if !defined(WITHOUT_NETCDF)
	@cd ${WRKSRC}/src/ && ${SETENV} CDO_PATH=${WRKSRC}/src/cdo ${WRKSRC}/src/cdotest
.endif

regression-test:
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
