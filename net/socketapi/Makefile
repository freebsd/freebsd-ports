PORTNAME=	socketapi
DISTVERSION=	2.2.25
CATEGORIES=	net
MASTER_SITES=	https://www.nntb.no/~dreibh/sctplib/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Socket API library for the SCTPLIB user-space SCTP implementation
WWW=		https://www.nntb.no/~dreibh/sctplib/

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
