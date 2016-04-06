# $FreeBSD$

PORTNAME=	noto
PORTVERSION=	1.0.4
CATEGORIES=	x11-fonts
MASTER_SITES=	https://noto-website.storage.googleapis.com/pkgs/ \
		https://github.com/googlei18n/noto-emoji/raw/master/:emoji
PKGNAMESUFFIX=	-lite
DISTNAME=	${PORTNAME:S|n|N|}-hinted
DISTFILES=	${DISTNAME}.zip NotoEmoji-Regular.ttf:emoji
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Google font family - lite version

LICENSE=	APACHE20 OFL11
LICENSE_COMB=	multi

USES=		fonts zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

CONFLICTS_INSTALL=	noto*

LIST= NotoEmoji-Regular.ttf NotoSans-Bold.ttf NotoSans-BoldItalic.ttf NotoSans-Italic.ttf NotoSans-Regular.ttf NotoSansLinearB-Regular.ttf NotoSansSymbols-Regular.ttf NotoSerif-Bold.ttf NotoSerif-BoldItalic.ttf NotoSerif-Italic.ttf NotoSerif-Regular.ttf

.for f in ${LIST}
PLIST_FILES+=   ${FONTSDIR}/${f}
.endfor

post-extract:
	${CP} ${DISTDIR}/NotoEmoji-Regular.ttf ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for f in ${LIST}
	cd ${WRKSRC} && ${INSTALL_DATA} ${f} ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
