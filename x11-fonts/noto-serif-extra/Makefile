PORTNAME=	noto
PORTVERSION=	2.013
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/latin-greek-cyrillic/releases/download/NotoSerif-v${PORTVERSION}/
PKGNAMESUFFIX=	-serif-extra
DISTNAME=	NotoSerif-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Serif (Extra)
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/latin-greek-cyrillic

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

post-patch:
	@${RM} ${WRKSRC}/NotoSerif/hinted/ttf/NotoSerif-Bold.ttf
	@${RM} ${WRKSRC}/NotoSerif/hinted/ttf/NotoSerif-BoldItalic.ttf
	@${RM} ${WRKSRC}/NotoSerif/hinted/ttf/NotoSerif-Italic.ttf
	@${RM} ${WRKSRC}/NotoSerif/hinted/ttf/NotoSerif-Regular.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSerif/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
