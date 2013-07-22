# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	GentiumPlus
PORTVERSION=	1.510
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium Plus TrueType font collection

LICENSE=	OFL
LICENSE_NAME=	SIL Open Font License (OFL)
LICENSE_FILE=	${WRKSRC}/OFL.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_ZIP=	yes
XORG_CAT=	font

FONTLIBPATH=	lib/X11/fonts
FONTROOTDIR=	${PREFIX}/${FONTLIBPATH}
INSTALLS_TTF=	yes
MEDIA_ID=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes
USE_TGZ=	yes	#prevent bsd.xorg.mk from setting USE_BZIP

PLIST_FILES=	${FONTLIBPATH}/${FONTDIR}/${PORTNAME}-I.ttf \
		${FONTLIBPATH}/${FONTDIR}/${PORTNAME}-R.ttf

SUB_LIST=	"FONTPATH=${FONTROOTDIR}/${FONTDIR}"
SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt GENTIUM-FAQ.txt OFL-FAQ.txt OFL.txt README.txt \
		documentation/GentiumPlus-features.pdf
PORTDOCS=	${DOCSLIST:C,^.*/,,}


.include <bsd.port.options.mk>

.SILENT:

do-configure:
	@${DO_NADA}

do-install: install-fonts install-docs
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

install-fonts:
	${MKDIR} ${FONTROOTDIR}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTROOTDIR}/${FONTDIR}

install-docs:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
