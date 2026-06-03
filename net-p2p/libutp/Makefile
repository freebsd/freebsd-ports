PORTNAME=	libutp
DISTVERSION=	g20241117
CATEGORIES=	net-p2p

MAINTAINER=	mondo.debater_0q@icloud.com
COMMENT=	uTorrent Transport Protocol library and sample utilities
WWW=		https://github.com/transmission/libutp

LICENSE=	MIT

USES=		cmake uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	transmission
GH_TAGNAME=	490874c

USE_LDCONFIG=	yes
CMAKE_ON=	LIBUTP_SHARED
CMAKE_OFF=	LIBUTP_ENABLE_WERROR
CMAKE_BUILD_TYPE=	Release

.include <bsd.port.mk>
