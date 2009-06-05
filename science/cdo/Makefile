# ex:ts=8
# New ports collection makefile for:	CDO
# Date created:			29 May 2006
# Whom:				Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=		cdo
PORTVERSION=		1.3.1
CATEGORIES=		science
MASTER_SITES=		http://www.mpimet.mpg.de/fileadmin/software/cdo/ \
			http://sunpoet.net/distfiles/

MAINTAINER=		sunpoet@sunpoet.net
COMMENT=		Climate Data Operators

GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--program-transform-name=""
CONFIGURE_ENV=		CC="${CC}" \
			CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
			LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_FILES=		bin/cdo

NETCDF_VER?=		4
HDF5_VER?=		18

OPTIONS=		HDF5	"HDF5 support"		on \
			NETCDF	"NetCDF support"	on \
			PROJ	"PROJ support"		on

.include <bsd.port.pre.mk>

.if (${OSVERSION} > 700000) || (${ARCH} != "sparc64")
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -DPTHREAD_MUTEXATTR_CONDATTR"
.endif

.if (defined(WITH_NETCDF) && defined(WITH_HDF5) && (${NETCDF_VER} == 4) && (${HDF5_VER} == 16))
IGNORE=netCDF 4 requires HDF5 1.8.
.endif

.if defined(WITH_NETCDF)
CONFIGURE_ARGS+=	--with-netcdf=${LOCALBASE}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-src-Makefile.in
.if (${NETCDF_VER} == 4)
HDF5_VER=		18
WITH_HDF5=		yes
LIB_DEPENDS+=		netcdf.5:${PORTSDIR}/science/netcdf4
.else
LIB_DEPENDS+=		netcdf.4:${PORTSDIR}/science/netcdf
.endif
PLIST_FILES+=		bin/cdotest
.endif

.if defined(WITH_HDF5)
CONFIGURE_ARGS+=	--with-hdf5=${LOCALBASE} --with-zlib=/usr
.if (${HDF5_VER} == 18)
LIB_DEPENDS+=		hdf5.6:${PORTSDIR}/science/hdf5-18
.else
LIB_DEPENDS+=		hdf5.0:${PORTSDIR}/science/hdf5
.endif
.endif

.if defined(WITH_PROJ)
CONFIGURE_ARGS+=	--with-proj=${LOCALBASE}
LIB_DEPENDS+=		proj.5:${PORTSDIR}/graphics/proj
.endif

post-build:
.if defined(WITH_NETCDF)
	@cd "${WRKSRC}/src" && ${SETENV} CDO_PATH="${WRKSRC}/src/cdo" "${WRKSRC}/src/cdotest"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

regression-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
