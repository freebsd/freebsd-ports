# New ports collection makefile for:	wmpal
# Date created:				20 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmpal
PORTVERSION=	0.5
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://www.asleep.net/wmpal/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A one of the most useless dockapps in the world

LIB_DEPENDS=	dockapp.1:${PORTSDIR}/x11-wm/libdockapp

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

.include <bsd.port.mk>
