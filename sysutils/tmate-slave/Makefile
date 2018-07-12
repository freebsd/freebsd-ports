# $FreeBSD$

PORTNAME=	tmate-slave
PORTVERSION=	g20171113
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Instant terminal sharing server

LIB_DEPENDS=	libevent.so:devel/libevent \
		libmsgpackc.so:devel/msgpack \
		libssh_threads.so:security/libssh

USES=		autoreconf ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tmate-io
GH_TAGNAME=	d6a76e0

GNU_CONFIGURE=	yes
INSTALL_ARGET=	install-strip
USE_LDCONFIG=	yes
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/tmate-slave

PORTSCOUT=	skipv:1.8,1.7

.include <bsd.port.mk>
