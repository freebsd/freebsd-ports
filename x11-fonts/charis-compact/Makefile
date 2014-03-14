# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CharisSILCompact
PORTVERSION=	4.114
CATEGORIES=	x11-fonts
#unfortunately, the SIL server embeds timestamps in the distfile, so we use a static local copy
.if defined(MAINTAINER_MODE)
MASTER_SITES=	http://scripts.sil.org/ttw/fonts2go.cgi?family=CharisSIL&pkg=Compact&ver=${PORTVERSION}&filename=/
.else
MASTER_SITES=	LOCAL/bf
.endif
MASTER_SITE_SUBDIR=	#prevent bsd.xorg.mk from setting a default subdirectory

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Charis SIL TrueType font collection, compact variant

LICENSE=	OFL11

USES=		zip
XORG_CAT=	font

FONTROOTDIR=	${PREFIX}/lib/X11/fonts
INSTALLS_TTF=	yes
NO_BUILD=	yes
USE_TGZ=	yes	#prevent bsd.xorg.mk from setting USE_BZIP

.for type in B BI I R
PLIST_FILES+=	${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}/${PORTNAME}-${type}.ttf
.endfor

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt feat_set_tuned.xml

SUB_LIST=	DIR="${FONTROOTDIR}/${FONTDIR}"
SUB_FILES=	pkg-message

do-configure:
	@${DO_NADA}

do-install:
	${MKDIR} ${STAGEDIR}${FONTROOTDIR}/${FONTDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTROOTDIR}/${FONTDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
