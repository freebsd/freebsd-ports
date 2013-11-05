# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	GentiumPlus
PORTVERSION=	1.510
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium Plus TrueType font collection

LICENSE=	OFL11

USE_ZIP=	yes
XORG_CAT=	font

FONTLIBPATH=	lib/X11/fonts
FONTROOTDIR=	${STAGEDIR}${PREFIX}/${FONTLIBPATH}
INSTALLS_TTF=	yes
MEDIA_ID=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes
USE_TGZ=	yes	#prevent bsd.xorg.mk from setting USE_BZIP

PLIST_FILES=	${FONTLIBPATH}/${FONTDIR}/${PORTNAME}-I.ttf \
		${FONTLIBPATH}/${FONTDIR}/${PORTNAME}-R.ttf

SUB_LIST=	"FONTPATH=${PREFIX}$FONTLIBPATH}/${FONTDIR}"
SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt GENTIUM-FAQ.txt OFL-FAQ.txt OFL.txt README.txt \
		documentation/GentiumPlus-features.pdf
PORTDOCS=	${DOCSLIST:C,^.*/,,}

.include <bsd.port.options.mk>

.SILENT:

do-configure:
	@${DO_NADA}

do-install: install-fonts install-docs

install-fonts:
	${MKDIR} ${FONTROOTDIR}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTROOTDIR}/${FONTDIR}

install-docs:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
