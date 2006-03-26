# New ports collection makefile for:    urwfonts
# Date created:         Sat Aug 12 15:02:03 CEST 2000
# Whom:                 olgeni@uli.it
#
# $FreeBSD$
#

PORTNAME=	urwfonts
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/
DISTNAME=	urw-fonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Another font package for X

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes

post-extract:
	@${CHMOD} ${SHAREMODE} ${WRKDIR}/URW/*

post-install:
	@command fc-cache -v ${PREFIX}/lib/X11/fonts/URW || true
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
