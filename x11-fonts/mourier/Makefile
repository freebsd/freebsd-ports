PORTNAME=	mourier
DISTVERSION=	g20170925
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Alphabet of geometric symbols based on 7x7 units

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	velvetyne
GH_PROJECT=	Mourier
GH_TAGNAME=	344849db8495978f01d28cc9230f82a1628da7fe

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/Mourier.otf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/Mourier.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
