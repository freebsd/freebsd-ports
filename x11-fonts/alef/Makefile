PORTNAME=	alef
DISTVERSION=	1.001
CATEGORIES=	x11-fonts
MASTER_SITES=	https://dev-www.libreoffice.org/src/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Free multi-lingual font designed for screens
WWW=		https://wiki.documentfoundation.org/Fonts

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL-license.txt

USES=		fonts
FONTNAME=	Alef

EXTRACT_AFTER_ARGS=	--strip-components 1 \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${FONTSDIR}/Alef-Bold.ttf \
		${FONTSDIR}/Alef-Regular.ttf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
