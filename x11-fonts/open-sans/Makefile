PORTNAME=	open-sans
PORTVERSION=	20180831
CATEGORIES=	x11-fonts
MASTER_SITES=	https://www.opensans.com/download/
DISTFILES=	${PORTNAME}.zip \
		${PORTNAME}-condensed.zip
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	Clean and modern sans-serif typeface

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/Apache\ License.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
