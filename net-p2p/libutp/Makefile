PORTNAME=	libutp
DISTVERSION=	g20180515
CATEGORIES=	net-p2p

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	uTorrent Transport Protocol library and sample utilities
WWW=		https://github.com/bittorrent/libutp

LICENSE=	MIT

USES=		cmake uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	transmission
GH_TAGNAME=	fda9f4b3db97ccb243fcbed2ce280eb4135d705b

USE_LDCONFIG=	yes

PLIST_FILES=	include/libutp/utp.h \
		include/libutp/utypes.h \
		lib/libutp.so

.include <bsd.port.mk>
