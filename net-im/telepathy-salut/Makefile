# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/telepathy-salut/Makefile 18965 2013-12-20 11:02:42Z kwm $

PORTNAME=	telepathy-salut
PORTVERSION=	0.8.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Link-local Connection Manager for Telepathy Framework

LIB_DEPENDS=	libavahi-glib.so:${PORTSDIR}/net/avahi-app \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup

GNU_CONFIGURE=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	glib20 libxslt:build
USE_OPENSSL=	yes
USE_PYTHON_BUILD=	yes
USE_SQLITE=	3
CONFIGURE_ARGS=	--disable-Werror --enable-avahi-tests=no
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|make -C|${GMAKE} -C|g' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/tests/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/telepathy/salut-0/lib/lib*.so

.include <bsd.port.mk>
