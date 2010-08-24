# New ports collection makefile for:	STIX fonts
# Date created:		28 February 2009
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	stixfonts
PORTVERSION=	1.0.0
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/${PORTNAME}/CurrentRelease/
# http://freefr.dl.sourceforge.net/project/stixfonts/CurrentRelease/STIXv1.0.0.zip
DISTNAME=	STIXv${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A comprehensive set of fonts for scientific and engineering purposes

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
USE_XORG=	x11

LICENSE=	OFL
LICENSE_NAME=	Open Font License
LICENSE_FILE=	${WRKSRC}/License/STIX\ Font\ License\ 2010.pdf
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

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

do-build:
	cd ${WRKSRC}/Fonts && ${MKFONTSCL_CMD}
	${REINPLACE_CMD} -e 's|-misc-|-stix-|' ${WRKSRC}/Fonts/fonts.scale
	cd ${WRKSRC}/Fonts && ${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC}/Fonts && ${INSTALL_DATA} fonts.dir fonts.scale *.otf ${FONTDIR}

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${FCCACHE} ${FONTDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
