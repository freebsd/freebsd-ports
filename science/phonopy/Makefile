PORTNAME=	phonopy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.16.2.20220930
CATEGORIES=	science python

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	ce8db957a0cb58a6f953b192056d03107eeecdaf.patch:-p1 # fixes armv7 build

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for phonon calculations at harmonic and quasi-harmonic levels
WWW=		https://phonopy.github.io/phonopy/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TAGNAME=	${DISTVERSIONFULL:R}

CMAKE_ON=	PHONOPY BUILD_SHARED_LIBRARIES

PLIST_FILES=	include/phonopy.h \
		lib/libphpy.a \
		lib/libphpy.so \
		lib/libphpy.so.1 \
		lib/libphpy.so.${DISTVERSION:R}

.include <bsd.port.mk>
