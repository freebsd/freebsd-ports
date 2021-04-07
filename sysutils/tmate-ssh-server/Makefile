PORTNAME=	tmate-ssh-server
PORTVERSION=	g2020071601
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Instant terminal sharing server

LIB_DEPENDS=	libevent.so:devel/libevent \
		libmsgpackc.so:devel/msgpack \
		libssh.so:security/libssh

USES=		autoreconf compiler:c11 ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	tmate-io
GH_TAGNAME=	97d2024

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/tmate-ssh-server

PORTSCOUT=	skipv:2.3.0

.include <bsd.port.mk>
