# New ports collection makefile for:    urwfonts
# Date created:         Sat Aug 12 15:02:03 CEST 2000
# Whom:                 olgeni@uli.it
#
# $FreeBSD$
#

PORTNAME=	urwfonts
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.gimp.org/
DISTNAME=	urw-fonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Another font package for X

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
