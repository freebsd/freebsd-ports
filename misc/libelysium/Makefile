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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library of utility functions used by several Elysium projects

DEPRECATED=	"ancient version of this software\; not used by any other port"
EXPIRATION_DATE=	"May 13 2004"

USE_GNOME=	glib12
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
