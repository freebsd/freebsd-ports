PORTNAME=	phonopy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.42.0
CATEGORIES=	science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for phonon calculations at harmonic and quasi-harmonic levels
WWW=		https://phonopy.github.io/phonopy/ \
		https://github.com/phonopy/phonopy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes

CMAKE_ON=	PHONOPY PHONOPY_LIBS BUILD_SHARED_LIBS

PLIST_FILES=	include/phonopy.h \
		lib/libphonopy_libs.so \
		lib/libphonopy_libs.so.1 \
		lib/libphonopy_libs.so.${DISTVERSION}

.include <bsd.port.mk>
