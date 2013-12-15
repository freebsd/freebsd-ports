# $FreeBSD$
#    $MCom: ports/net-im/telepathy-idle/Makefile,v 1.6 2012/08/17 19:06:45 kwm Exp $

PORTNAME=	telepathy-idle
PORTVERSION=	0.1.11
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	IRC Connection Manager for Telepathy Framework

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20
USE_PYTHON_BUILD=yes

MAN8=		telepathy-idle.8

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

#.if defined(WITH_OPENSSL_BASE)
CONFIGURE_ENV+=	OPENSSL_LIBS="-L/usr/lib -lssl -lcrypto" OPENSSL_CFLAGS="-I/usr/include"
#.endif
#  OPENSSL_CFLAGS
#              C compiler flags for OPENSSL, overriding pkg-config
#  OPENSSL_LIBS
#              linker flags for OPENSSL, overriding pkg-config

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|strnlen(\([^,]*\), [^)]*)|strlen(\1)|' \
		${WRKSRC}/src/idle-connection.c \
		${WRKSRC}/src/idle-parser.c

.include <bsd.port.mk>
