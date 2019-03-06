# Created by: Guerkan Senguen <gurkan@phys.ethz.ch>
# $FreeBSD$

PORTNAME=	junicode
DISTVERSION=	1.002
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DISTVERSION} \
		http://anthesphoria.net/FreeBSD/ports/distfiles/

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	Unicode/MUFI OpenType font for medievalists (Latin, IPA, Runic, Greek)

LICENCE=	OFL11

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USES=		fonts zip

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
