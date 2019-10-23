# $FreeBSD$

PORTNAME=	Andika
DISTVERSION=	5.000
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	https://software.sil.org/downloads/r/andika/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Andika TrueType fonts

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/Andika-R.ttf

SUB_FILES=	pkg-message

DOCSLIST=	FONTLOG.txt OFL-FAQ.txt README.txt documentation/Andika-features.odt documentation/Andika-features.pdf documentation/DOCUMENTATION.txt
PORTDOCS=	${DOCSLIST:C,^.*/,,}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSLIST:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
