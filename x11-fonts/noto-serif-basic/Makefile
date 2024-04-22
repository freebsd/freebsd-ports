PORTNAME=	noto
PORTVERSION=	2.013
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/latin-greek-cyrillic/releases/download/NotoSerif-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-basic
DISTNAME=	NotoSerif-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif (Basic)
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/latin-greek-cyrillic

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerif/hinted/ttf/NotoSerif-Bold.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerif/hinted/ttf/NotoSerif-BoldItalic.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerif/hinted/ttf/NotoSerif-Italic.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerif/hinted/ttf/NotoSerif-Regular.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
