PORTNAME=	opensans
DISTVERSION=	3.003
CATEGORIES=	x11-fonts
PKGNAMESUFFIX=	-ttf

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Clean and modern sans-serif typeface
WWW=		https://github.com/googlefonts/opensans/

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts

USE_GITHUB=	yes
GH_ACCOUNT=	googlefonts
GH_TAGNAME=	bd7e376 # v3.003

EXTRACT_AFTER_ARGS=	--include ${WRKSRC:T}/OFL.txt \
			--include ${WRKSRC:T}/fonts/ttf/*.ttf \
			--no-same-owner --no-same-permissions
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
