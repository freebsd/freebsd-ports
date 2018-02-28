# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	GentiumPlus
PORTVERSION=	5.000
CATEGORIES=	x11-fonts
MASTER_SITES=	http://software.sil.org/downloads/gentium/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Gentium Plus TrueType font collection

LICENSE=	OFL11

NO_ARCH=	yes
NO_BUILD=	yes

USES=		fonts zip

PLIST_FILES=	${FONTSDIR}/${PORTNAME}-I.ttf \
		${FONTSDIR}/${PORTNAME}-R.ttf

SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt GENTIUM-FAQ.txt OFL-FAQ.txt OFL.txt \
		README.txt documentation/GentiumPlus-features.pdf
PORTDOCS=	${DOCSLIST:C,^.*/,,}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
