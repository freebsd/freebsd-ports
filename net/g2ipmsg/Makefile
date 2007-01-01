# New ports collection makefile for:	g2ipmsg
# Date created:				2006/12/18
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	g2ipmsg
PORTVERSION=	0.8.2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~nork/distfiles/
MASTER_SITE_SUBDIR=	nork
DIST_SUBDIR=	gnome2

MAINTAINER=	nork@FreeBSD.org
COMMENT=	A popup style message communication tool for GNOME2

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack intltool pkgconfig \
		libgnomeui libbonobo desktopfileutils
USE_GSTREAMER=	vorbis
USE_ICONV=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	g2ipmsg.schemas

post-install:
	@update-desktop-database

.include <bsd.port.mk>
