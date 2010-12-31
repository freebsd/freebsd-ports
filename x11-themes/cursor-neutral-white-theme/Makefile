# New ports collection makefile for:	cursor-neutral-white-theme
# Date created:			28 Nov 2010
# Whom:				Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	cursor-neutral-white-theme
DISTVERSION=	1.1
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	108143-Neutral++_White-${DISTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	White cursor theme based on neutral

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Neutral++_White

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/Neutral++_White/cursors
	cd ${WRKSRC}/cursors \
		&& ${INSTALL_DATA} * ${PREFIX}/lib/X11/icons/Neutral++_White/cursors

.include <bsd.port.mk>
