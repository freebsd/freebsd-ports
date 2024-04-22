PORTNAME=	noto
PORTVERSION=	2.002
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/thai/releases/download/NotoSerifThai-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-thai
DISTNAME=	NotoSerifThai-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Thai
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/thai

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerifThai/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
