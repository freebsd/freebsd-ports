# $FreeBSD$

PORTNAME=	Andika
PORTVERSION=	1.004
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Andika TrueType fonts

LICENSE=	OFL11

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

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-configure:
	${DO_NADA}

do-install:
	${MKDIR} ${STAGEDIR}${FONTROOTDIR}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTROOTDIR}/${FONTDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
