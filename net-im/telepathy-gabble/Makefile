# Created by:  Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-gabble/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	telepathy-gabble
PORTVERSION=	0.18.2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Jabber Connection Manager for Telepathy Framework

BUILD_DEPENDS=	telepathy-glib>=0.22.0:${PORTSDIR}/net-im/telepathy-glib \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libnice.so:${PORTSDIR}/net-im/libnice \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libloudmouth-1.so:${PORTSDIR}/net-im/loudmouth
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss \
		libnice-gst1>=0:${PORTSDIR}/net-im/libnice-gst1

PORTSCOUT=	limitw:1,even

USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 libxslt:build
USE_SQLITE=	3
USE_OPENSSL=	yes
USE_PYTHON_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt
CONFIGURE_ENV=	LIBS="-pthread"

PLIST_SUB=	PVERSION=${PORTVERSION}

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -ssl -crypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/lib/ext/wocky/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/telepathy/gabble-0/plugins/lib*.so 
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/telepathy/gabble-0/lib/lib*.so

.include <bsd.port.mk>
