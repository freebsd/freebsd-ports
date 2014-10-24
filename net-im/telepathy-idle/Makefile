# $FreeBSD$
#    $MCom: ports/net-im/telepathy-idle/Makefile,v 1.6 2012/08/17 19:06:45 kwm Exp $

PORTNAME=	telepathy-idle
PORTVERSION=	0.1.11
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IRC Connection Manager for Telepathy Framework

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig python:build
USE_OPENSSL=	yes
USE_GNOME=	glib20 libxslt:build

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

#.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -lssl -lcrypto" OPENSSL_CFLAGS="-I/usr/include"
#.endif
#  OPENSSL_CFLAGS
#              C compiler flags for OPENSSL, overriding pkg-config
#  OPENSSL_LIBS
#              linker flags for OPENSSL, overriding pkg-config

post-patch:
	@${REINPLACE_CMD} -e 's|strnlen(\([^,]*\), [^)]*)|strlen(\1)|' \
		${WRKSRC}/src/idle-connection.c \
		${WRKSRC}/src/idle-parser.c

.include <bsd.port.mk>
