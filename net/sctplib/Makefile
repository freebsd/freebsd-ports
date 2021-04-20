# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>

PORTNAME=	sctplib
PORTVERSION=	1.0.26
CATEGORIES=	net
MASTER_SITES=	https://www.uni-due.de/~be0001/sctplib/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	User-space implementation of the SCTP protocol RFC 4960

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
