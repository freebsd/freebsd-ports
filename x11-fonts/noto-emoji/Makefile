# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	noto
PORTVERSION=	2.034
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/googlefonts/noto-emoji/raw/v${PORTVERSION}/fonts/
PKGNAMESUFFIX=	-emoji
DISTFILES=	NotoColorEmoji.ttf \
		NotoEmoji-Regular.ttf
DIST_SUBDIR=	Noto
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Fonts family (Emoji)

LICENSE=	APACHE20

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/NotoColorEmoji.ttf ${DISTDIR}/${DIST_SUBDIR}/NotoEmoji-Regular.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
