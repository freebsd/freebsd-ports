# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	GentiumBasic
PORTVERSION=	110
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/
DISTNAME=	ttf-sil-gentium-basic_1.1.orig

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium Basic and Gentium Book Basic TrueType fonts

LICENSE=	OFL11

NO_ARCH=	yes

USE_TGZ=	yes
XORG_CAT=	font

FONTLIBPATH=	lib/X11/fonts
FONTPATH=	${PREFIX}/${FONTLIBPATH}/${FONTDIR}
INSTALLS_TTF=	yes
MEDIA_ID=	${PORTNAME}_${PORTVERSION}_tar
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S,.orig,,:S,_,-,}

PLIST_FILES=	${FONTPATH:S,^${PREFIX}/,,}/GenBasB.ttf \
		${FONTPATH:S,^${PREFIX}/,,}/GenBasBI.ttf \
		${FONTPATH:S,^${PREFIX}/,,}/GenBasI.ttf \
		${FONTPATH:S,^${PREFIX}/,,}/GenBasR.ttf \
		${FONTPATH:S,^${PREFIX}/,,}/GenBkBasB.ttf \
		${FONTPATH:S,^${PREFIX}/,,}/GenBkBasBI.ttf \
		${FONTPATH:S,^${PREFIX}/,,}/GenBkBasI.ttf \
		${FONTPATH:S,^${PREFIX}/,,}/GenBkBasR.ttf

SUB_LIST=	"FONTPATH=${FONTPATH}"
SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt GENTIUM-FAQ.txt OFL-FAQ.txt
PORTDOCS=	${DOCSLIST:C,^.*/,,}

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
