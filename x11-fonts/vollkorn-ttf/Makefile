# $FreeBSD$

PORTNAME=	vollkorn-ttf
PORTVERSION=	2.1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://friedrichalthausen.de/
DISTNAME=	Vollkorn-${PORTVERSION}

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	Free and healthy typeface for bread and butter use

LICENSE=	OFL11

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		zip

FONTDIR=	${STAGEDIR}${PREFIX}/lib/X11/fonts/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} Vollkorn-*.ttf ${FONTDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} Fontlog.txt OFL-FAQ.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
