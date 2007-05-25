# New ports collection makefile for:	Liberation fonts
# Date created:		17 May 2007
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	liberation-fonts-ttf
PORTVERSION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://www.redhat.com/f/fonts/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Liberation fonts from Red Hat to replace MS TTF fonts

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	Liberation
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
INSTDAT=	License.txt fonts.dir fonts.scale

MKFONTSCL_CMD=	${X11BASE}/bin/mkfontscale
MKFONTDIR_CMD=	${X11BASE}/bin/mkfontdir

do-build:
	cd ${WRKSRC} &&	\
	${MKFONTSCL_CMD}
	${REINPLACE_CMD} -e 's|-misc-|-redhat-|' ${WRKSRC}/fonts.scale
	cd ${WRKSRC} &&	\
	${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC} &&	\
	${INSTALL_DATA} ${INSTDAT} *.ttf ${FONTDIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
