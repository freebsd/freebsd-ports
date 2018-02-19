# Created by:  Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	telepathy-gabble
PORTVERSION=	0.18.3
PORTREVISION=	5
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
		libdbus-1.so:devel/dbus \
		libgnutls.so:security/gnutls \
		libuuid.so:misc/e2fsprogs-libuuid \
		libloudmouth-1.so:net-im/loudmouth
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		libnice-gst1>=0:net-im/libnice-gst1

PORTSCOUT=	limitw:1,even

USES=		alias gmake libtool pathfix pkgconfig python:2.7,build \
		shebangfix sqlite ssl
USE_GNOME=	glib20 gtksourceview3 libxslt:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CONFIGURE_ENV=	LIBS="-pthread"
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	plugins/telepathy-gabble-xmpp-console

PLIST_SUB=	PVERSION=${PORTVERSION}
SHEBANG_FILES=	plugins/telepathy-gabble-xmpp-console

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -ssl -crypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/lib/ext/wocky/configure

.include <bsd.port.post.mk>
