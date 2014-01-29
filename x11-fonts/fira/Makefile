# Created by: Horia Racoviceanu <horia@racoviceanu.com>
# $FreeBSD$

PORTNAME=	fira
PORTVERSION=	1.0
CATEGORIES=	x11-fonts

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Sans-serif and monospaced typeface for small screens

LICENSE=	OFL11

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla
GH_PROJECT=	Fira
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	705ffff

USE_XORG=	x11
FONTLIBPATH=	lib/X11/fonts
FONTROOTDIR=	${PREFIX}/${FONTLIBPATH}
FONTDIR=	${FONTROOTDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_LIST=	FONTDIR="${FONTDIR}"
PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/ttf/${GH_PROJECT}*.ttf ${STAGEDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/otf/${GH_PROJECT}*.otf ${STAGEDIR}${FONTDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
