# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/telepathy-salut/Makefile 19802 2014-08-13 12:13:08Z gusi $

PORTNAME=	telepathy-salut
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Link-local Connection Manager for Telepathy Framework

LIB_DEPENDS=	libavahi-glib.so:net/avahi-app \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libsoup-2.4.so:devel/libsoup

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig python:build sqlite
USE_GNOME=	glib20 libxslt:build
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--disable-Werror --enable-avahi-tests=no
LDFLAGS+=	-lpthread
INSTALL_TARGET=	install-strip

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|make -C|${GMAKE} -C|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
