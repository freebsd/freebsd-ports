# $FreeBSD$
#   $MCom: ports/net-im/telepathy-salut/Makefile,v 1.9 2012/08/17 19:06:46 kwm Exp $

PORTNAME=	telepathy-salut
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Link-local Connection Manager for Telepathy Framework

LIB_DEPENDS=	libavahi-glib.so:${PORTSDIR}/net/avahi-app \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig python:build
USE_GNOME=	glib20 libxslt:build
USE_OPENSSL=	yes
USE_SQLITE=	3
CONFIGURE_ARGS=	--disable-Werror --enable-avahi-tests=no
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|make -C|${MAKE_CMD} -C|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
