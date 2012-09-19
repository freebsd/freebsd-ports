# New ports collection makefile for:	SourceSansPro-ttf
# Date created:		11 Aug 2012
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	sourcesanspro-ttf
PORTVERSION=	1.034
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/sourcesans.adobe
DISTNAME=	SourceSansPro_FontsOnly-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	A set of fonts by Adobe designed for user interfaces

LICENSE=	OFL
LICENSE_NAME=	SIL OPEN FONT LICENSE Version 1.1
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USE_ZIP=	yes
USE_XORG=	x11

PLIST_SUB=	FONTDIR="${FONTDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	SourceSansPro
FONTDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
INSTDAT=		fonts.dir fonts.scale

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

do-build:
	cd ${WRKSRC}/ && ${MKFONTSCL_CMD}
	cd ${WRKSRC}/ && ${MKFONTDIR_CMD}

do-install:
	${MKDIR} ${FONTDIR}
	cd ${WRKSRC}/ &&	\
	${INSTALL_DATA} ${INSTDAT} *.ttf ${FONTDIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
