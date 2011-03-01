# ex:ts=8
# New ports collection makefile for:	CDO
# Date created:			29 May 2006
# Whom:				Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=		cdo
PORTVERSION=		1.4.7
CATEGORIES=		science
MASTER_SITES=		https://code.zmaw.de/attachments/download/704/ \
			LOCAL/sunpoet

MAINTAINER=		sunpoet@FreeBSD.org
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
			JASPER	"Japser support"	off \
			NETCDF	"NetCDF support"	on \
			PROJ	"PROJ support"		on \
			SZIP	"SZIP support"		on

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 700000) || (${ARCH} != "sparc64")
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -DPTHREAD_MUTEXATTR_CONDATTR"
.endif

.if (!defined(WITHOUT_NETCDF) && !defined(WITHOUT_HDF5) && (${NETCDF_VER} == 4) && (${HDF5_VER} == 16))
IGNORE=netCDF 4 requires HDF5 1.8.
.endif

.if !defined(WITHOUT_NETCDF) && (${NETCDF_VER} == 4)
HDF5_VER=		18
WITH_HDF5=		yes
.endif

.if !defined(WITHOUT_HDF5)
CONFIGURE_ARGS+=	--with-hdf5=${LOCALBASE} --with-zlib=/usr
WITH_SZIP=		yes
.if (${HDF5_VER} == 18)
LIB_DEPENDS+=		hdf5.6:${PORTSDIR}/science/hdf5-18
.else
LIB_DEPENDS+=		hdf5.0:${PORTSDIR}/science/hdf5
.endif
.endif

.if defined(WITH_JASPER)
CONFIGURE_ARGS+=	--with-jasper=${LOCALBASE}
LIB_DEPENDS+=		jasper:${PORTSDIR}/graphics/jasper
PLIST_SUB+=		JPEG2000=""
.else
.endif

.if !defined(WITHOUT_NETCDF)
CONFIGURE_ARGS+=	--with-netcdf=${LOCALBASE}
.if (${NETCDF_VER} == 4)
LIB_DEPENDS+=		netcdf.6:${PORTSDIR}/science/netcdf4
.else
LIB_DEPENDS+=		netcdf.4:${PORTSDIR}/science/netcdf
.endif
PLIST_FILES+=		bin/cdotest
.endif

.if !defined(WITHOUT_PROJ)
CONFIGURE_ARGS+=	--with-proj=${LOCALBASE}
LIB_DEPENDS+=		proj.6:${PORTSDIR}/graphics/proj
.endif

.if !defined(WITHOUT_SZIP)
CONFIGURE_ARGS+=	--with-szlib=${LOCALBASE}
LIB_DEPENDS+=		sz.2:${PORTSDIR}/science/szip
.endif

post-patch:
.if !defined(WITHOUT_NETCDF)
	${REINPLACE_CMD} \
		-e '/bin_PROGRAMS = / s|$$| cdotest$$(EXEEXT)|' \
		-e '/noinst_PROGRAMS = / s| cdotest$$(EXEEXT)||' \
			${WRKSRC}/src/Makefile.in
.endif

post-build:
.if !defined(WITHOUT_NETCDF) && (${OSVERSION} >= 700000)
	@cd "${WRKSRC}/src" && ${SETENV} CDO_PATH="${WRKSRC}/src/cdo" "${WRKSRC}/src/cdotest"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

regression-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
