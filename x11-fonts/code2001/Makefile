# New ports collection makefile for:	Code2001
# Date created:		10 May 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	code2001
PORTVERSION=	0.919
CATEGORIES=	x11-fonts
MASTER_SITES=	http://code2000.net/ CENKES/myports/${DIST_SUBDIR}
DISTFILES=	${PORTNAME:U}${EXTRACT_SUFX:U}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Plane 1 Unicode-based Font

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
	@${MV} ${WRKDIR}/CODE2001.TTF ${WRKSRC}/${FONTNAME}.ttf

do-build:
	@cd ${WRKSRC}/ && ${MKFONTSCL_CMD} && ${MKFONTDIR_CMD}

do-install:
	@${INSTALL} -d ${FONTSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/* ${FONTSDIR}/
	@${ECHO_MSG} "===> Running fc-cache"
	-${FCCACHE_CMD} ${FONTSDIR}

.include <bsd.port.mk>
