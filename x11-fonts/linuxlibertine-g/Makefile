# $FreeBSD$

PORTNAME=	linuxlibertine-g
PORTVERSION=	20120116
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.numbertext.org/linux/
DISTNAME=	e7a384790b13c29113e22e596ade9687-LinLibertineG-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Linux Libertine G and Linux Biolinum G fonts

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USES=		zip

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

FONTNAME=	LinLibertineG
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
INSTDAT=	fonts.dir fonts.scale

WRKSRC=	${WRKDIR}/${FONTNAME}

do-build:
	cd ${WRKSRC} && ${MKFONTSCL_CMD}
	cd ${WRKSRC} && ${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${STAGEDIR}${FONTDIR}
	cd ${WRKSRC} &&	\
		${INSTALL_DATA} ${INSTDAT} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTDIR}

.include <bsd.port.mk>
