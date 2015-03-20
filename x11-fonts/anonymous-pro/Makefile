# Created by: Norberto Lopes <nlopes.ml@gmail.com>
# $FreeBSD$

PORTNAME=	anonymous-pro
PORTVERSION=	1.002
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.marksimonson.com/assets/content/fonts/
DISTNAME=	AnonymousPro-${PORTVERSION}

MAINTAINER=	nlopes.ml@gmail.com
COMMENT=	Fixed width sans designed especially for coders

LICENSE=	OFL11

USES=		fonts zip
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
SUB_LIST=	FONTSDIR=${FONTSDIR}
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${DISTNAME}.001

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
