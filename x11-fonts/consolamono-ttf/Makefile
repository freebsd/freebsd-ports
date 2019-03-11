# $FreeBSD$

PORTNAME=	consolamono-ttf
PORTVERSION=	20130127
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://fontlibrary.org/assets/downloads/consolamono/61cc2afcc4eca96efe7c6ebf178d39df/
DISTNAME=	consolamono

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Monospace font created for programming, text editors and terminal-use

LICENSE=	OFL11

USES=		fonts zip

FONTNAME=	ConsolaMono
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Consola\ Mono

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
