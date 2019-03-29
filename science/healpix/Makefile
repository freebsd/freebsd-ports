# $FreeBSD$

PORTNAME=	healpix
DISTVERSION=	3.50
DISTVERSIONSUFFIX=	_2018Dec10
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/Healpix_${DISTVERSION}/
DISTNAME=	Healpix_${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for pixelization, visualization, etc of data on the sphere

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	fails to configure: could not find the cfitsio library

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libcurl.so:ftp/curl

FLAVORS=	cxx c
FLAVOR?=	${FLAVORS:[1]}
c_PKGNAMESUFFIX=	-c
cxx_PLIST=	${.CURDIR}/pkg-plist-cxx
c_PLIST=	${.CURDIR}/pkg-plist-c

USES=		autoreconf compiler:c++11-lang gmake libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

WRKSRC=			${WRKDIR}/Healpix_${DISTVERSION}
AUTORECONF_WRKSRC=	${WRKSRC}/src/${FLAVOR:S/^c$/C/}/autotools
CONFIGURE_WRKSRC=	${AUTORECONF_WRKSRC}
BUILD_WRKSRC=		${AUTORECONF_WRKSRC}
INSTALL_WRKSRC=		${AUTORECONF_WRKSRC}

.include <bsd.port.mk>
