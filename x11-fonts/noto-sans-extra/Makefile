PORTNAME=	noto
PORTVERSION=	2.013
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/latin-greek-cyrillic/releases/download/NotoSans-v${PORTVERSION}/
PKGNAMESUFFIX=	-sans-extra
DISTNAME=	NotoSans-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans (Extra)
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
	@${RM} ${WRKSRC}/NotoSans/hinted/ttf/NotoSans-Bold.ttf
	@${RM} ${WRKSRC}/NotoSans/hinted/ttf/NotoSans-BoldItalic.ttf
	@${RM} ${WRKSRC}/NotoSans/hinted/ttf/NotoSans-Italic.ttf
	@${RM} ${WRKSRC}/NotoSans/hinted/ttf/NotoSans-Regular.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSans/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
