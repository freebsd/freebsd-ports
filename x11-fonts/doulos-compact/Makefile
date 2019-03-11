# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DoulosSILCompact
PORTVERSION=	4.110
PORTREVISION=	3
CATEGORIES=	x11-fonts
#unfortunately, the SIL server embeds timestamps in the distfile, so we use a static local copy
.if defined(MAINTAINER_MODE)
MASTER_SITES=	http://scripts.sil.org/ttw/fonts2go.cgi?family=DoulosSIL&pkg=Compact&ver=${PORTVERSION}&filename=/
.else
MASTER_SITES=	LOCAL/bf
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Doulos SIL TrueType font collection, compact variant

LICENSE=	OFL11

USES=		fonts zip

NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/${PORTNAME}-R.ttf

OPTIONS_DEFINE=	DOCS

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt feat_set_tuned.xml

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
