# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-gabble/Makefile 17271 2013-04-01 15:16:27Z kwm $

PORTNAME=	telepathy-gabble
PORTVERSION=	0.16.6
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Jabber Connection Manager for Telepathy Framework

BUILD_DEPENDS=	telepathy-glib>=0.18.0:${PORTSDIR}/net-im/telepathy-glib \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libnice.so:${PORTSDIR}/net-im/libnice \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

PORTSCOUT=	limitw:1,even

GNU_CONFIGURE=	yes
USES=		alias gmake libtool pathfix pkgconfig python:build
USE_GNOME=	glib20 libxslt:build
USE_SQLITE=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt

PLIST_SUB=	PVERSION=${PORTVERSION}

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -ssl -crypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/lib/ext/wocky/configure

.include <bsd.port.mk>
