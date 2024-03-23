PORTNAME=	noto
PORTVERSION=	2.003
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/lao/releases/download/NotoSerifLao-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-lao
DISTNAME=	NotoSerifLao-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif Lao
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/lao

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerifLao/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
