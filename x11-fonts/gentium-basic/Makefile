# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	GentiumBasic
PORTVERSION=	110
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?format=file&media_id=${MEDIA_ID}&filename=/
DISTNAME=	ttf-sil-gentium-basic_1.1.orig

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium Basic and Gentium Book Basic TrueType fonts

LICENSE=	OFL11

USES=		fonts
NO_ARCH=	yes

MEDIA_ID=	${PORTNAME}_${PORTVERSION}_tar
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S,.orig,,:S,_,-,}

PLIST_FILES=	${FONTSDIR}/GenBasB.ttf \
		${FONTSDIR}/GenBasBI.ttf \
		${FONTSDIR}/GenBasI.ttf \
		${FONTSDIR}/GenBasR.ttf \
		${FONTSDIR}/GenBkBasB.ttf \
		${FONTSDIR}/GenBkBasBI.ttf \
		${FONTSDIR}/GenBkBasI.ttf \
		${FONTSDIR}/GenBkBasR.ttf

SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt GENTIUM-FAQ.txt OFL-FAQ.txt
PORTDOCS=	${DOCSLIST:C,^.*/,,}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
