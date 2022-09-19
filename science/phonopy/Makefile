PORTNAME=	phonopy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.16.1
CATEGORIES=	science python

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	b2e7b1d6f7280b2d4d99fb74737b2bffbc86fd08.patch:-p1 # backport fix for https://github.com/phonopy/phonopy/issues/234

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
