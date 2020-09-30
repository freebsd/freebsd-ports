# $FreeBSD$

PORTNAME=	hash
DISTVERSION=	g20200929
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++14 header-only easy-to-use hash library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Chocobo1
GH_PROJECT=	Hash
GH_TAGNAME=	3c8d607b3d470d8a41ac3262ee310e850fab61cd

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/hash
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include/hash
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} gsl ${STAGEDIR}${PREFIX}/include/hash

.include <bsd.port.mk>
