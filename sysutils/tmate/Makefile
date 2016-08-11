# $FreeBSD$

PORTNAME=	tmate
PORTVERSION=	2.2.1
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Instant terminal sharing

LIB_DEPENDS=	libevent.so:devel/libevent2 \
		libmsgpackc.so:devel/msgpack \
		libssh_threads.so:security/libssh

USES=		autoreconf pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tmate-io

GNU_CONFIGURE=	yes
INSTALL_ARGET=	install-strip
USE_LDCONFIG=	yes
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/tmate man/man1/tmate.1.gz

BROKEN_FreeBSD_9=	Does not build

.include <bsd.port.mk>
