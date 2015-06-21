# $FreeBSD$

PORTNAME=	gmp-api
DISTVERSIONPREFIX=	Firefox
DISTVERSION=	38 # tracking www/firefox
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Gecko Media Plugins API from mozilla-release

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
