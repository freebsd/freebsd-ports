# $FreeBSD$

PORTNAME=	urwfonts
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/fonts/
DISTNAME=	urw-fonts

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Another font package for X

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-extract:
	@${CHMOD} ${SHAREMODE} ${WRKDIR}/URW/*

post-install:
	@command fc-cache -v ${PREFIX}/lib/X11/fonts/URW || true
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
