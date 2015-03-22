# $FreeBSD$

PORTNAME=	symbola
PORTVERSION=	7.19
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://users.teilar.gr/~g1951d/
DISTNAME=	Symbola

MAINTAINER=	elizabeth@interlinked.me
COMMENT=	Basic Latin, Greek, Cyrillic and many Symbol blocks of Unicode

LICENSE=	Public_domain
LICENSE_GROUPS=	COPYFREE FONTS
LICENSE_NAME=	Disclaimer of rights
LICENSE_FILE=	${FILESDIR}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		fonts zip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.docx ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
