# $FreeBSD$

PORTNAME=	symbola
PORTVERSION=	7.19
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
USES=		zip

FONTDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.docx ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
