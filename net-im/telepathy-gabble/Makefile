# Created by:  Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	telepathy-gabble
PORTVERSION=	0.18.3
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Jabber Connection Manager for Telepathy Framework

BUILD_DEPENDS=	telepathy-glib>=0.22.0:net-im/telepathy-glib \
		ca_root_nss>=0:security/ca_root_nss
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libnice.so:net-im/libnice \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libdbus-glib-1.so:devel/dbus-glib \
		libuuid.so:misc/e2fsprogs-libuuid \
		libloudmouth-1.so:net-im/loudmouth
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		libnice-gst1>=0:net-im/libnice-gst1

PORTSCOUT=	limitw:1,even

USES=		alias gmake libtool pathfix pkgconfig python:build sqlite
USE_GNOME=	glib20 gtksourceview3 libxslt:build
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CONFIGURE_ENV=	LIBS="-pthread"
INSTALL_TARGET=	install-strip

PLIST_SUB=	PVERSION=${PORTVERSION}

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -ssl -crypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/lib/ext/wocky/configure

.include <bsd.port.mk>
