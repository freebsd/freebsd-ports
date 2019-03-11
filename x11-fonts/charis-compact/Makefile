# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CharisSILCompact
PORTVERSION=	4.114
PORTREVISION=	2
CATEGORIES=	x11-fonts
#unfortunately, the SIL server embeds timestamps in the distfile, so we use a static local copy
.if defined(MAINTAINER_MODE)
MASTER_SITES=	http://scripts.sil.org/ttw/fonts2go.cgi?family=CharisSIL&pkg=Compact&ver=${PORTVERSION}&filename=/
.else
MASTER_SITES=	LOCAL/bf
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Charis SIL TrueType font collection, compact variant

LICENSE=	OFL11

USES=		fonts zip

NO_BUILD=	yes

.for type in B BI I R
PLIST_FILES+=	${FONTSDIR}/${PORTNAME}-${type}.ttf
.endfor

OPTIONS_DEFINE=	DOCS

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt feat_set_tuned.xml

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
