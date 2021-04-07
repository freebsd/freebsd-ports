PORTNAME=	noto
PORTVERSION=	2.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website-2.storage.googleapis.com/pkgs/
DISTNAME=	Noto-hinted
PKGNAMESUFFIX=	-extra

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Extra)

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/LICENSE_OFL.txt

USES=		fonts zip

EXTRACT_AFTER_ARGS=	-d ${EXTRACT_WRKDIR} -x '*.otf'
NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

BASIC_FONTS=	NotoMono-Regular.ttf \
		NotoSans-Bold.ttf \
		NotoSans-BoldItalic.ttf \
		NotoSans-Italic.ttf \
		NotoSans-Regular.ttf \
		NotoSansLinearB-Regular.ttf \
		NotoSansSymbols-Regular.ttf \
		NotoSerif-Bold.ttf \
		NotoSerif-BoldItalic.ttf \
		NotoSerif-Italic.ttf \
		NotoSerif-Regular.ttf
EMOJI_FONTS=	NotoColorEmoji.ttf \
		NotoEmoji-Regular.ttf

post-extract:
	@cd ${WRKSRC} && ${RM} ${BASIC_FONTS} ${EMOJI_FONTS}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
