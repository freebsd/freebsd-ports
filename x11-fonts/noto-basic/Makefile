# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0.5
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website.storage.googleapis.com/pkgs/ \
		https://github.com/googlei18n/noto-emoji/raw/master/fonts/:emoji
PKGNAMESUFFIX=	-basic
DISTFILES=	Noto-hinted${EXTRACT_SUFX} \
		NotoColorEmoji.ttf:emoji \
		NotoEmoji-Regular.ttf:emoji
EXTRACT_ONLY=	Noto-hinted${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Basic and Emoji)

LICENSE=	APACHE20 OFL11
LICENSE_COMB=	multi
LICENSE_FILE_OFL11=	${WRKSRC}/LICENSE_OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

BASIC_FONTS=	NotoColorEmoji.ttf \
		NotoEmoji-Regular.ttf \
		NotoMono-Regular.ttf \
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

post-extract:
	@${CP} ${DISTDIR}/NotoColorEmoji.ttf ${DISTDIR}/NotoEmoji-Regular.ttf ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${BASIC_FONTS} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
