# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/libepc/Makefile 19822 2014-08-20 08:57:46Z gusi $

PORTNAME=	libepc
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Easy Publish and Consume library

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libsoup-2.4.so:devel/libsoup \
		libgnutls.so:security/gnutls \
		libavahi-ui-gtk3.so:net/avahi-gtk3

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
