# $FreeBSD$

PORTNAME=	symbola
PORTVERSION=	7.19
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://users.teilar.gr/~g1951d/
DISTNAME=	Symbola

MAINTAINER=	elizabeth@interlinked.me
COMMENT=	Basic Latin, Greek, Cyrillic and many Symbol blocks of Unicode

LICENSE=	PD
LICENSE_FILE=	${FILESDIR}/COPYING

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		fonts zip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.docx ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
