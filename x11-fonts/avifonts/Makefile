# New ports collection makefile for:	AviSoft Font Family
# Date created:			5 Dec 2005
# Whom:				past@ebs.gr
#
# $FreeBSD$
#

PORTNAME=	avifonts
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://graphis.hellug.gr/packages/
DISTNAME=	avifonts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AviFonts greek fonts collection

BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_BZIP2=	yes
NO_BUILD=	yes

FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
PLIST_SUB=	FONTSDIR=${FONTSDIR:S|^${PREFIX}/||}

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/avifonts-2005/avifonts/* ${FONTSDIR}

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
