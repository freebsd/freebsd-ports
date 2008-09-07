# New ports collection makefile for:	TibetanMachineUni
# Date created:		19 May 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tmu
DISTVERSION=	1.901b
CATEGORIES=	x11-fonts
MASTER_SITES=	CENKES
# http://www.thdl.org/tools/fonts/index.html

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Tibetan Machine Uni font

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir	\
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir
FCCACHE_CMD=	${LOCALBASE}/bin/fc-cache -f -v

post-extract:
	@cd ${WRKSRC}/&&${MV} TibMachUni-${DISTVERSION}.ttf tmu.ttf

do-build:
	@cd ${WRKSRC}/ && ${MKFONTSCL_CMD} && ${MKFONTDIR_CMD}

do-install:
	@${INSTALL} -d ${FONTSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/[ft]* ${FONTSDIR}/
	@${ECHO_MSG} "===> Running fc-cache"
	-${FCCACHE_CMD} ${FONTSDIR}

.include <bsd.port.mk>
