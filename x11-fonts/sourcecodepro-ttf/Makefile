# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	sourcecodepro-ttf
PORTVERSION=	1.017
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/sourcecodepro.adobe
DISTNAME=	SourceCodePro_FontsOnly-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of fonts by Adobe designed for coders

LICENSE=	OFL11

NO_BUILD=	yes
USE_XORG=	x11
USES=		fonts zip

FONTNAME=	SourceCodePro
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	cd ${WRKSRC}/TTF/ && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
