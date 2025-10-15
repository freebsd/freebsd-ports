PORTNAME=	healpix
DISTVERSION=	3.50
DISTVERSIONSUFFIX=	_2018Dec10
PORTREVISION=	6
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

LDFLAGS+=	-lomp

WRKSRC=			${WRKDIR}/Healpix_${DISTVERSION}
AUTORECONF_WRKSRC=	${WRKSRC}/src/${FLAVOR:S/^c$/C/}/autotools
CONFIGURE_WRKSRC=	${AUTORECONF_WRKSRC}
BUILD_WRKSRC=		${AUTORECONF_WRKSRC}
INSTALL_WRKSRC=		${AUTORECONF_WRKSRC}

.include <bsd.port.mk>
