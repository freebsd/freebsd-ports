# $FreeBSD$

PORTNAME=	comfortaa-ttf
PORTVERSION=	2.004
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/comfortaa/38318a69b56162733bf82bc0170b7521/
DISTNAME=	comfortaa

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Stylish, modern and free sans-serif true type font

LICENSE=	OFL11

USES=		zip

FONTDIR=	lib/X11/fonts/Comfortaa
NO_BUILD=	yes
PLIST_SUB=	FONTDIR=${FONTDIR}
WRKSRC=		${WRKDIR}/Comfortaa

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf ${STAGEDIR}${PREFIX}/${FONTDIR}/

.include <bsd.port.mk>
