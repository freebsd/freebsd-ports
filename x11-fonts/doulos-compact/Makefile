# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DoulosSILCompact
PORTVERSION=	4.110
PORTREVISION=	1
CATEGORIES=	x11-fonts
#unfortunately, the SIL server embeds timestamps in the distfile, so we use a static local copy
.if defined(MAINTAINER_MODE)
MASTER_SITES=	http://scripts.sil.org/ttw/fonts2go.cgi?family=DoulosSIL&pkg=Compact&ver=${PORTVERSION}&filename=/
.else
MASTER_SITES=	LOCAL/bf
.endif
MASTER_SITE_SUBDIR=	#prevent bsd.xorg.mk from setting a default subdirectory

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Doulos SIL TrueType font collection, compact variant

LICENSE=	OFL11

USES=		zip
XORG_CAT=	font

FONTROOTDIR=	${PREFIX}/lib/X11/fonts
INSTALLS_TTF=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}/${PORTNAME}-R.ttf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt feat_set_tuned.xml

SUB_LIST=	DIR="${FONTROOTDIR}/${FONTDIR}"
SUB_FILES=	pkg-message

do-configure:
	@${DO_NADA}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTROOTDIR}/${FONTDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTROOTDIR}/${FONTDIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
