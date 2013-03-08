# $FreeBSD$
#    $MCom: ports/net-im/telepathy-gabble/Makefile,v 1.22 2012/08/08 16:56:40 kwm Exp $

PORTNAME=	telepathy-gabble
PORTVERSION=	0.16.1
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Jabber Connection Manager for Telepathy Framework

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		telepathy-glib>=0.18.0:${PORTSDIR}/net-im/telepathy-glib \
		${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	soup-2.4:${PORTSDIR}/devel/libsoup \
		nice:${PORTSDIR}/net-im/libnice \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid \
		loudmouth-1:${PORTSDIR}/net-im/loudmouth
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

GNU_CONFIGURE=	yes
LDFLAGS+=	${PTHREAD_LIBS}
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_SQLITE=	yes
USE_OPENSSL=	yes
USE_PYTHON_BUILD=	yes
CONFIGURE_ARGS=	--with-ca-certificates=${LOCALBASE}/share/certs/ca-root-nss.crt

MAN8=		telepathy-gabble.8

PLIST_SUB=	PVERSION=${PORTVERSION}

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -ssl -crypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' \
		${WRKSRC}/lib/ext/wocky/configure

.include <bsd.port.mk>
