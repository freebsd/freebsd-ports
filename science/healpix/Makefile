PORTNAME=	healpix
DISTVERSION=	3.83
DISTVERSIONSUFFIX=	_2024Nov13
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/Healpix_${DISTVERSION}/
DISTNAME=	Healpix_${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for pixelization, visualization, etc of data on the sphere
WWW=		https://healpix.sourceforge.io/
		#https://healpix.jpl.nasa.gov/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libcurl.so:ftp/curl

FLAVORS=	cxx c
FLAVOR?=	${FLAVORS:[1]}
c_PKGNAMESUFFIX=	-c
cxx_PLIST=	${.CURDIR}/pkg-plist-cxx
c_PLIST=	${.CURDIR}/pkg-plist-c

USES=		autoreconf compiler:c++11-lang gmake libtool pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

.if exists(/usr/include/omp.h)
LDFLAGS+=	-lomp
.endif

WRKSRC=			${WRKDIR}/Healpix_${DISTVERSION}

.if ${FLAVOR} == cxx
AUTORECONF_WRKSRC=	${WRKSRC}/src/cxx
CONFIGURE_WRKSRC=	${WRKSRC}/src/cxx
BUILD_WRKSRC=		${WRKSRC}/src/cxx
INSTALL_WRKSRC=		${WRKSRC}/src/cxx
.else
AUTORECONF_WRKSRC=	${WRKSRC}/src/C/autotools
CONFIGURE_WRKSRC=	${WRKSRC}/src/C/autotools
BUILD_WRKSRC=		${WRKSRC}/src/C/autotools
INSTALL_WRKSRC=		${WRKSRC}/src/C/autotools
.endif

pre-configure:
.if ${FLAVOR} == cxx
	@${MKDIR} ${WRKSRC}/_libsharp_inst
	@cd ${WRKSRC}/src/common_libraries/libsharp && \
		${MAKE_ENV} ./configure --disable-shared --prefix=${WRKSRC}/_libsharp_inst \
		--disable-dependency-tracking CFLAGS="-fPIC ${CFLAGS}" && \
		${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} && \
		${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} install
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${WRKSRC}/_libsharp_inst/lib/pkgconfig
.endif

.include <bsd.port.mk>
