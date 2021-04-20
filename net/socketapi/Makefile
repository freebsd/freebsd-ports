# Created by: Thomas Dreibholz <dreibh@iem.uni-due.de>

PORTNAME=	socketapi
PORTVERSION=	2.2.19
CATEGORIES=	net
MASTER_SITES=	https://www.uni-due.de/~be0001/sctplib/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	Socket API library for the SCTPLIB user-space SCTP implementation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsctplib.so:net/sctplib

USES=		gnome libtool pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-sctp-over-udp
INSTALL_TARGET=	install-strip

LDFLAGS+=	-L${LOCALBASE}/lib -lsctplib

.include <bsd.port.mk>
