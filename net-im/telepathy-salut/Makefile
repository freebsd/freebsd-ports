PORTNAME=	telepathy-salut
PORTVERSION=	0.8.1
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Link-local Connection Manager for Telepathy Framework
WWW=		https://telepathy.freedesktop.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Fails to build with libxml2 2.13.2 (PR 279963)
EXPIRATION_DATE=2024-08-21

LIB_DEPENDS=	libavahi-glib.so:net/avahi-app \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libsoup-2.4.so:devel/libsoup

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake gnome libtool pathfix pkgconfig python:build sqlite ssl
USE_GNOME=	glib20 libxslt:build
CONFIGURE_ARGS=	--disable-Werror --enable-avahi-tests=no
LDFLAGS+=	-lpthread
INSTALL_TARGET=	install-strip

PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|make -C|${GMAKE} -C|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
