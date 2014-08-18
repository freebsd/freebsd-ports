# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/libgnome-keyring/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libgnome-keyring
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

USE_GNOME=	glib20 gnomehier gnomeprefix intlhack \
		introspection:build
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-vala
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
