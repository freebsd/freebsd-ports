# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-idle/Makefile 20041 2014-11-04 11:13:49Z kwm $

PORTNAME=	telepathy-idle
PORTVERSION=	0.2.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IRC Connection Manager for Telepathy Framework

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libtelepathy-glib.so:net-im/telepathy-glib

USES=		execinfo gmake libtool pathfix pkgconfig python:build
USE_GNOME=	glib20 libxslt:build
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -lssl -lcrypto" OPENSSL_CFLAGS="-I/usr/include"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|strnlen(\([^,]*\), [^)]*)|strlen(\1)|' \
		${WRKSRC}/src/idle-connection.c \
		${WRKSRC}/src/idle-parser.c

.include <bsd.port.post.mk>
