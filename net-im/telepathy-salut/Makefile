PORTNAME=	telepathy-salut
PORTVERSION=	0.8.1
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Link-local Connection Manager for Telepathy Framework

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavahi-glib.so:net/avahi-app \
		libtelepathy-glib.so:net-im/telepathy-glib \
		libsoup-2.4.so:devel/libsoup

GNU_CONFIGURE=	yes
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
