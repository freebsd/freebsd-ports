# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-mount/Makefile,v 1.28 2011/03/08 19:25:20 kwm Exp $

PORTNAME=	gnome-mount
PORTVERSION=	0.8
PORTREVISION=	12
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://hal.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Front-end to mount, umount, and eject using HAL

LIB_DEPENDS=	libhal.so:sysutils/hal \
		libnotify.so:devel/libnotify \
		libgnome-keyring.so:security/libgnome-keyring
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/polkit-gnome.pc:sysutils/policykit-gnome

USE_GNOME=	gnomeprefix intlhack gconf2 gtk20
USES=		alias gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nautilus-extension
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	gnome-mount.schemas

.include <bsd.port.mk>
