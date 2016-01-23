# $FreeBSD$

PORTNAME=	comfortaa-ttf
PORTVERSION=	2.004
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	https://fontlibrary.org/assets/downloads/comfortaa/38318a69b56162733bf82bc0170b7521/
DISTNAME=	comfortaa

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Stylish, modern and free sans-serif true type font

LICENSE=	OFL11

USES=		fonts zip

FONTNAME=	Comfortaa
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Comfortaa

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
