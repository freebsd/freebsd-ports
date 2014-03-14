# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CharisSIL
PORTVERSION=	4.114
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?&format=file&media_id=${MEDIA_ID}&filename=/ \
		LOCAL/bf
MASTER_SITE_SUBDIR=	#prevent bsd.xorg.mk from setting a default subdirectory

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Charis SIL TrueType font collection

LICENSE=	OFL11

USES=		zip
XORG_CAT=	font

FONTROOTDIR=	${PREFIX}/lib/X11/fonts
INSTALLS_TTF=	yes
MEDIA_ID=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes
USE_TGZ=	yes	#prevent bsd.xorg.mk from setting USE_BZIP

.for type in B BI I R
PLIST_FILES+=	${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}/${PORTNAME}-${type}.ttf
.endfor

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt

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
