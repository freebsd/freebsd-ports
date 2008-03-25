# New ports collection makefile for:	wmlmmon
# Date created:				24 September 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	wmlmmon
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.fxp.org/~jedgar/wmlmmon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WM dock app to display info from MB power management controllers

ONLY_FOR_ARCHS=	i386

USE_XORG=	xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm-includes=${X11BASE}/include \
		--with-xpm-libraries=${X11BASE}/lib
MAN8=		wmlmmon.8
MANCOMPRESSED=	yes
PLIST_FILES=	bin/wmlmmon

.include <bsd.port.mk>
