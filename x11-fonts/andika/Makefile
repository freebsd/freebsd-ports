# $FreeBSD$

PORTNAME=	Andika
PORTVERSION=	1.004
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Andika TrueType fonts

LICENSE=	OFL11

USE_ZIP=	yes
XORG_CAT=	font

FONTLIBPATH=	lib/X11/fonts
FONTROOTDIR=	${PREFIX}/${FONTLIBPATH}
INSTALLS_TTF=	yes
MEDIA_ID=	${PORTNAME}-${PORTVERSION}.zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S,.orig,,:S,_,-,}

PLIST_FILES=	${FONTLIBPATH}/${FONTDIR}/Andika-R.ttf

SUB_LIST=	"FONTPATH=${FONTROOTDIR}/${FONTDIR}"
SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt OFL-FAQ.txt README.txt
PORTDOCS=	${DOCSLIST:C,^.*/,,}

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-configure:
	${DO_NADA}

do-install:
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}
	${MKDIR} ${FONTROOTDIR}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTROOTDIR}/${FONTDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
