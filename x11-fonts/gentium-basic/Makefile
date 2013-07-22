# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	GentiumBasic
PORTVERSION=	110
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/
DISTNAME=	ttf-sil-gentium-basic_1.1.orig

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium Basic and Gentium Book Basic TrueType fonts

LICENSE=	OFL
LICENSE_NAME=	SIL Open Font License (OFL)
LICENSE_FILE=	${WRKSRC}/OFL.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_TGZ=	yes
XORG_CAT=	font

FONTLIBPATH=	lib/X11/fonts
FONTROOTDIR=	${PREFIX}/${FONTLIBPATH}
INSTALLS_TTF=	yes
MEDIA_ID=	${PORTNAME}_${PORTVERSION}_tar
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S,.orig,,:S,_,-,}

PLIST_FILES=	${FONTLIBPATH}/${FONTDIR}/GenBasB.ttf \
		${FONTLIBPATH}/${FONTDIR}/GenBasBI.ttf \
		${FONTLIBPATH}/${FONTDIR}/GenBasI.ttf \
		${FONTLIBPATH}/${FONTDIR}/GenBasR.ttf \
		${FONTLIBPATH}/${FONTDIR}/GenBkBasB.ttf \
		${FONTLIBPATH}/${FONTDIR}/GenBkBasBI.ttf \
		${FONTLIBPATH}/${FONTDIR}/GenBkBasI.ttf \
		${FONTLIBPATH}/${FONTDIR}/GenBkBasR.ttf

SUB_LIST=	"FONTPATH=${FONTROOTDIR}/${FONTDIR}"
SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt GENTIUM-FAQ.txt OFL-FAQ.txt
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
