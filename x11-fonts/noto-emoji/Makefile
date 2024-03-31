PORTNAME=	noto
PORTVERSION=	2.042
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-emoji/raw/v${PORTVERSION}/fonts/
PKGNAMESUFFIX=	-emoji
DISTFILES=	Noto-COLRv1.ttf \
		NotoColorEmoji.ttf
DIST_SUBDIR=	Noto
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Emoji)
WWW=		https://fonts.google.com/noto \
		https://github.com/googlefonts/noto-emoji

LICENSE=	OFL11

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/NotoColorEmoji.ttf

OPTIONS_DEFINE=	COLR
COLR_DESC=	Install COLRv1 font

COLR_PLIST_FILES=	${FONTSDIR}/Noto-COLRv1.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/NotoColorEmoji.ttf ${STAGEDIR}${FONTSDIR}

do-install-COLR-on:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Noto-COLRv1.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
