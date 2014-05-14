# $FreeBSD$

PORTNAME=	consolamono-ttf
PORTVERSION=	20130127
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/consolamono/61cc2afcc4eca96efe7c6ebf178d39df/
DISTNAME=	consolamono

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Monospace font created for programming, text editors and terminal-use

LICENSE=	OFL11

USES=		zip

FONTDIR=	lib/X11/fonts/ConsolaMono
NO_BUILD=	yes
PLIST_SUB=	FONTDIR=${FONTDIR}
WRKSRC=		${WRKDIR}/Consola\ Mono

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf ${STAGEDIR}${PREFIX}/${FONTDIR}/

.include <bsd.port.mk>
