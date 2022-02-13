PORTNAME=	phonopy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.13.1
CATEGORIES=	science python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for phonon calculations at harmonic and quasi-harmonic levels

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes

PLIST_FILES=	include/phonopy.h \
		lib/libphpy.a \
		lib/libphpy.so \
		lib/libphpy.so.1 \
		lib/libphpy.so.${DISTVERSION}

.include <bsd.port.mk>
