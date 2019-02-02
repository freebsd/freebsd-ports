# $FreeBSD$

PORTNAME=	tmate
PORTVERSION=	2.2.1
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Instant terminal sharing

LIB_DEPENDS=	libevent.so:devel/libevent \
		libmsgpackc.so:devel/msgpack \
		libssh.so:security/libssh

USES=		autoreconf ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tmate-io

GNU_CONFIGURE=	yes
INSTALL_ARGET=	install-strip
USE_LDCONFIG=	yes
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/tmate man/man1/tmate.1.gz

.include <bsd.port.mk>
