# New ports collection makefile for:	MgOpen Font Family
# Date created:			16 May 2005
# Whom:				past@ebs.gr
#
# $FreeBSD$
#

PORTNAME=	mgopen
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.ellak.gr/fonts/mgopen/files/
DISTNAME=	MgOpen

MAINTAINER=	past@ebs.gr
COMMENT=	MgOpen greek fonts collection

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_X_PREFIX=	yes
NO_BUILD=	yes

FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTSDIR=${FONTSDIR:S|^${PREFIX}/||}

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${FONTSDIR}

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${X11BASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
