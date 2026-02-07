PORTNAME=	perlinnoise
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	math devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Header-only Perlin noise library for modern C++
WWW=		https://github.com/Reputeless/PerlinNoise

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Reputeless
GH_PROJECT=	PerlinNoise

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/PerlinNoise.hpp

do-install:
	${INSTALL_DATA} ${WRKSRC}/PerlinNoise.hpp ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
