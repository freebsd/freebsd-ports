# $FreeBSD$

PORTNAME=	gmp-api
PORTVERSION=	38.0
CATEGORIES=	multimedia

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Gecko Media Plugins API from mozilla-central

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla
GH_TAGNAME=	2b8954c

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
