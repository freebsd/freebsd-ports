PORTNAME=	annoy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.1
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
		include/annoy/mman.h

NO_ARCH=	yes

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} annoy ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
