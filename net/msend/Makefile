PORTNAME=	msend
PORTVERSION=	3.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	LOCAL/markp

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Client and server for the RFC1312 message protocol

USES=		autoreconf readline
USE_RC_SUBR=	mesgd
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CFLAGS+=	-DUSE_READLINE -DNO_GETDTABLESIZE -DNEW_HEADERS -DUSE_UTMPX

PLIST_FILES=	bin/msend \
		share/man/man1/msend.1.gz \
		share/man/man8/mesgd.8.gz \
		sbin/mesgd

.include <bsd.port.mk>
