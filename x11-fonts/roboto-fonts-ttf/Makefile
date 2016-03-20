# Created by: Winston Weinert <winstonw@lavabit.com>
# $FreeBSD$

PORTNAME=	roboto-fonts-ttf
PORTVERSION=	2.131
DISTVERSIONPREFIX=v
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	winston@ml1.net
COMMENT=	Roboto typeface family

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes
USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	roboto

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/hinted/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
