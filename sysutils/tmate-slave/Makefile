# $FreeBSD$

PORTNAME=	tmate-slave
PORTVERSION=	0.0.0.2016051901
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Instant terminal sharing server

LIB_DEPENDS=	libevent.so:devel/libevent2 \
		libmsgpackc.so:devel/msgpack \
		libssh_threads.so:security/libssh

USES=		autoreconf pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tmate-io
GH_TAGNAME=	b3c85fa

GNU_CONFIGURE=	yes
INSTALL_ARGET=	install-strip
USE_LDCONFIG=	yes
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/tmate-slave

BROKEN_FreeBSD_9=	Does not build

.include <bsd.port.mk>
