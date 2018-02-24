# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	freefont-ttf
PORTVERSION=	20120503
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	GNU/freefont

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free UCS Outline Fonts

LICENSE=	GPLv3

USES=		fonts zip

WRKSRC=		${WRKDIR}/freefont-${PORTVERSION}
PORTDOCS=	AUTHORS ChangeLog CREDITS README
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && \
	${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
