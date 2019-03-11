# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	pingwi
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.pingwinsoft.ru/system/uploads/16/original/ \
		http://fbsd.zlonet.ru/distfiles/
PKGNAMEPREFIX=	font-
DISTNAME=	fonts_test

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PingWi Typography fonts

USES=		fonts zip
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
