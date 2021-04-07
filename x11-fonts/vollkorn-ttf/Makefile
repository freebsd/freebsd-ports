PORTNAME=	vollkorn-ttf
PORTVERSION=	4.105
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://vollkorn-typeface.com/download/
DISTNAME=	vollkorn-${PORTVERSION:S|.|-|}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Free and healthy typeface for bread and butter use

LICENSE=	OFL11

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		fonts zip

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} TTF/Vollkorn-*.ttf ${STAGEDIR}${FONTSDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} Fontlog.txt OFL-FAQ.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
