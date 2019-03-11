# Created by: Florian Limberger <flo@snakeoilproductions.net>
# $FreeBSD$

PORTNAME=	linden-hill
DISTVERSION=	g20110526
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	Digital version of Frederic Goudy's Deepdene

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/Open\ Font\ License.markdown

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	theleagueof
GH_TAGNAME=	a3f7ae6

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	"${FONTSDIR}/Linden Hill Italic.otf" \
		"${FONTSDIR}/Linden Hill.otf"

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} "Linden Hill Italic.otf" \
		"Linden Hill.otf" ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
