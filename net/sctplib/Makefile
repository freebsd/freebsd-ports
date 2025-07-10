PORTNAME=	sctplib
DISTVERSION=	1.0.32
CATEGORIES=	net
MASTER_SITES=	https://www.nntb.no/~dreibh/sctplib/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	User-space implementation of the SCTP protocol RFC 4960
WWW=		https://www.nntb.no/~dreibh/sctplib/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sctp-over-udp
INSTALL_TARGET=	install-strip
PLIST_FILES=	include/sctp.h \
		lib/libsctplib.a \
		lib/libsctplib.so \
		lib/libsctplib.so.1 \
		lib/libsctplib.so.1.0.8

.include <bsd.port.mk>
