# Ports collection Makefile for:	libelysium
# Date created:				10 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libelysium
PORTVERSION=	0.3.5
CATEGORIES=	misc gnome
MASTER_SITES=	http://elysium.zoned.net/${PORTNAME}/

MAINTAINER=	sobomax@FreeBSD.org

USE_GNOMENG=	yes
USE_GNOME=	glib12
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
