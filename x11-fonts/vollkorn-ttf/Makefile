# $FreeBSD$

PORTNAME=	vollkorn-ttf
PORTVERSION=	3.005
CATEGORIES=	x11-fonts
MASTER_SITES=	http://vollkorn-typeface.com/download/
DISTNAME=	vollkorn-${PORTVERSION:S|.|-|}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Free and healthy typeface for bread and butter use

LICENSE=	OFL11

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		zip

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} TTF/Vollkorn-*.ttf ${STAGEDIR}${FONTDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} Fontlog.txt OFL-FAQ.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
