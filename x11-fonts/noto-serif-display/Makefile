PORTNAME=	noto
PORTVERSION=	2.009
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/latin-greek-cyrillic/releases/download/NotoSerifDisplay-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-display
DISTNAME=	NotoSerifDisplay-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Display
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/latin-greek-cyrillic

LICENSE=	OFL11
#LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerifDisplay/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
