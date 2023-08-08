PORTNAME=	annoy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.3
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Approximate Nearest Neighbors in C++
WWW=		https://github.com/spotify/annoy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	spotify

PLIST_FILES=	include/annoy/annoylib.h \
		include/annoy/kissrandom.h \
		include/annoy/mman.h \
		lib/cmake/annoy/AnnoyConfig.cmake

NO_ARCH=	yes

.include <bsd.port.mk>
