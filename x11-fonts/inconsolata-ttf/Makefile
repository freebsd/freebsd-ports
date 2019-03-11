# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	inconsolata-ttf
PORTVERSION=	2.001
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fonts

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Monospaced truetype font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

NO_ARCH=	yes
USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	fonts
GH_TAGNAME=	efcbdc5
FONTNAME=	inconsolata
USE_XORG=	x11
PLIST_FILES=	${FONTSDIR}/Inconsolata-Bold.ttf \
		${FONTSDIR}/Inconsolata-Regular.ttf
NO_BUILD=	yes

WRKSRC_SUBDIR=	ofl/${FONTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/Inconsolata-Bold.ttf \
			${WRKSRC}/Inconsolata-Regular.ttf \
			${STAGEDIR}/${FONTSDIR}

.include <bsd.port.mk>
