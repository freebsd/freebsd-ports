# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	GentiumPlus
PORTVERSION=	1.510
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium Plus TrueType font collection

LICENSE=	OFL11

NO_ARCH=	yes

USES=		zip
XORG_CAT=	font

FONTLIBPATH=	lib/X11/fonts
FONTPATH=	${PREFIX}/${FONTLIBPATH}/${FONTDIR}
INSTALLS_TTF=	yes
MEDIA_ID=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes
USE_TGZ=	yes	#prevent bsd.xorg.mk from setting USE_BZIP

PLIST_FILES=	${FONTPATH:S,^${PREFIX}/,,}/${PORTNAME}-I.ttf \
		${FONTPATH:S,^${PREFIX}/,,}/${PORTNAME}-R.ttf

SUB_LIST=	"FONTPATH=${FONTPATH}"
SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt GENTIUM-FAQ.txt OFL-FAQ.txt OFL.txt README.txt \
		documentation/GentiumPlus-features.pdf
PORTDOCS=	${DOCSLIST:C,^.*/,,}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.SILENT:

do-configure:
	@${DO_NADA}

do-install: install-fonts install-docs

install-fonts:
	${MKDIR} ${STAGEDIR}${FONTPATH}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTPATH}

install-docs:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
