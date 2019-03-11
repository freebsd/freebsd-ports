# $FreeBSD$

PORTNAME=	Andika
PORTVERSION=	5.000
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Andika TrueType fonts

LICENSE=	OFL11

USES=		fonts

MEDIA_ID=	${PORTNAME}-${PORTVERSION}.zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S,.orig,,:S,_,-,}

PLIST_FILES=	${FONTSDIR}/Andika-R.ttf

SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt OFL-FAQ.txt README.txt
PORTDOCS=	${DOCSLIST:C,^.*/,,}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
