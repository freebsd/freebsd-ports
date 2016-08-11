# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CharisSIL
PORTVERSION=	4.114
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?&format=file&media_id=${MEDIA_ID}&filename=/ \
		LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Charis SIL TrueType font collection

LICENSE=	OFL11

USES=		fonts zip

MEDIA_ID=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes

.for type in B BI I R
PLIST_FILES+=	${FONTSDIR}/${PORTNAME}-${type}.ttf
.endfor

OPTIONS_DEFINE=	DOCS

PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${STAGEDIR}${FONTSDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
