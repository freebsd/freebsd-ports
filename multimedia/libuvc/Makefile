PORTNAME=	libuvc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.6-32
DISTVERSIONSUFFIX=	-gc612d45
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c765bb30b5f5.patch:-p1 # https://github.com/libuvc/libuvc/pull/163

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform library for USB video devices

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake jpeg pkgconfig
USE_GITHUB=	yes

.include <bsd.port.mk>
