# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	stixfonts
PORTVERSION=	1.1.1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/${PORTNAME}/Current%20Release/
DISTNAME=	STIXv${PORTVERSION}-webfonts

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	OpenType Unicode fonts for Scientific, Technical, and Math texts

LICENSE=	OFL11

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_WRKSUBDIR=	yes

USES=		zip
USE_XORG=	x11

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"	\
		FCCACHE='${FCCACHE}'

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	stix
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir
FCCACHE=	${LOCALBASE}/bin/fc-cache -f -v

.if !defined(NOPORTDOCS)
PORTDOCS=	"STIX Font ${PORTVERSION}-webfonts Release Documentation.pdf"
.endif

do-build:
	${MKDIR} ${WRKDIR}/build
.for group in stix-web STIX-MathJax/woff
	${CP} ${WRKSRC}/${group}/*.woff ${WRKDIR}/build/
.endfor
	cd ${WRKDIR}/build && ${MKFONTSCL_CMD}
	${REINPLACE_CMD} -e 's|-misc-|-stix-|' ${WRKDIR}/build/fonts.scale
	cd ${WRKDIR}/build && ${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	cd ${WRKDIR}/build && ${INSTALL_DATA} fonts.dir fonts.scale *.woff ${STAGEDIR}${FONTDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
