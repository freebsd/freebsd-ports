PORTNAME=	phonopy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.21.0
CATEGORIES=	science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for phonon calculations at harmonic and quasi-harmonic levels
WWW=		https://phonopy.github.io/phonopy/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes

CMAKE_ON=	PHONOPY BUILD_SHARED_LIBRARIES

PLIST_FILES=	include/phonopy.h \
		lib/libphpy.a \
		lib/libphpy.so \
		lib/libphpy.so.1 \
		lib/libphpy.so.${DISTVERSION}

.include <bsd.port.mk>
