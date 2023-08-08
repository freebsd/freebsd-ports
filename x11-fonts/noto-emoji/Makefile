PORTNAME=	noto
PORTVERSION=	2.038
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-emoji/raw/v${PORTVERSION}/fonts/
PKGNAMESUFFIX=	-emoji
DISTFILES=	NotoColorEmoji.ttf
DIST_SUBDIR=	Noto
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Emoji)
WWW=		https://fonts.google.com/noto \
		https://github.com/googlefonts/noto-emoji

LICENSE=	APACHE20

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/NotoColorEmoji.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/NotoColorEmoji.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
