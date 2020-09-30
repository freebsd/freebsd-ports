# $FreeBSD$

PORTNAME=	hash
DISTVERSION=	g20200514
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++14 header-only easy-to-use hash library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Chocobo1
GH_PROJECT=	Hash
GH_TAGNAME=	61c3580ed5cd6d164accc90a84284a12444188da

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/hash
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${STAGEDIR}${PREFIX}/include/hash
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} gsl ${STAGEDIR}${PREFIX}/include/hash

.include <bsd.port.mk>
