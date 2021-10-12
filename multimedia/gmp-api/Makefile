PORTNAME=	gmp-api
DISTVERSIONPREFIX=	Firefox
DISTVERSION=	92
CATEGORIES=	multimedia

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Gecko Media Plugins API extracted from Firefox

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
