# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libepc
PORTVERSION=	0.4.6
CATEGORIES=	www
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	The Easy Publish and Consume library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
		libfribidi.so:converters/fribidi \
		libsoup-2.4.so:devel/libsoup \
		libgnutls.so:security/gnutls \
		libavahi-common.so:net/avahi-app \
		libavahi-ui-gtk3.so:net/avahi-gtk3

USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix cairo gdkpixbuf2 gtk30 intltool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
.if exists(/usr/lib/libstdc++.so)
	${REINPLACE_CMD} -e '/#pragma GCC diagnostic/d' \
		${WRKSRC}/examples/simple-publisher.c
.endif

.include <bsd.port.mk>
