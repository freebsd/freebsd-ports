# New ports collection makefile for:	STIX fonts
# Date created:		28 February 2009
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	STIX-fonts
PORTVERSION=	0.20071031
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.mozilla.org/projects/mathml/fonts/stix/
DISTNAME=	STIXBeta

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A comprehensive set of fonts for scientific and engineering purposes

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
USE_XORG=	x11

NO_WRKSUBDIR=	yes

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"	\
		FCCACHE='${FCCACHE}'

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	stix
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
INSTDAT=	License.txt Readme.txt fonts.dir fonts.scale

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir
FCCACHE=	${LOCALBASE}/bin/fc-cache -f -v

do-build:
	cd ${WRKSRC} &&	\
	${MKFONTSCL_CMD}
	${REINPLACE_CMD} -e 's|-misc-|-stix-|' ${WRKSRC}/fonts.scale
	cd ${WRKSRC} &&	\
	${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC} &&	\
	${INSTALL_DATA} ${INSTDAT} *.otf ${FONTDIR}

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${FCCACHE} ${FONTDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
