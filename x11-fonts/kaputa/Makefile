# New ports collection makefile for:	kaputa
# Date created:		20 May 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kaputa
PORTVERSION=	1.000
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.kaputa.com/slword/
DISTNAME=	${PORTNAME}unicode
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free unicode font for Sinhala script

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir	\
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir
FCCACHE_CMD=	${LOCALBASE}/bin/fc-cache -f -v

post-extract:
	@${MKDIR} ${WRKSRC}/
	@${MV} ${WRKDIR}/kaputaunicode.ttf ${WRKSRC}/kaputa.ttf

do-build:
	@cd ${WRKSRC}/ && ${MKFONTSCL_CMD} && ${MKFONTDIR_CMD}

do-install:
	@${INSTALL} -d ${FONTSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/* ${FONTSDIR}/
	@${ECHO_MSG} "===> Running fc-cache"
	-${FCCACHE_CMD} ${FONTSDIR}

.include <bsd.port.mk>
