# Created by: Guerkan Senguen <gurkan@phys.ethz.ch>
# $FreeBSD$

PORTNAME=	junicode
PORTVERSION=	0.7.6
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION:S|.|-|g} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|-|g}

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Unicode/MUFI OpenType font for medievalists (Latin, IPA, Runic, Greek)

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USES=		fonts zip

FONTSDIR?=	lib/X11/fonts/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.ttf ${STAGEDIR}${PREFIX}/${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
