# Ports collection Makefile for:	libelysium
# Date created:				10 December 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libelysium
PORTVERSION=	0.3.5
CATEGORIES=	misc gnome
# The master_site doesn't hold the 0.3.5 tarballs anymore, but is
# a reference for the person who wants to upgrade this port - edwin 20021227
MASTER_SITES=	http://elysium-project.sourceforge.net/

MAINTAINER=	sobomax@FreeBSD.org

USE_GNOMENG=	yes
USE_GNOME=	glib12
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
