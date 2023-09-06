PORTNAME=	libutp
DISTVERSION=	g20230213
CATEGORIES=	net-p2p

MAINTAINER=	mondo.debater_0q@icloud.com
COMMENT=	uTorrent Transport Protocol library and sample utilities.
WWW=		https://github.com/transmission/libutp

LICENSE=	MIT

USES=		cmake uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	transmission
GH_TAGNAME=	c95738b1a6644b919e5b64d3ea9736cfc5894e0b

USE_LDCONFIG=	yes
CMAKE_ON=	LIBUTP_SHARED
CMAKE_OFF=	LIBUTP_ENABLE_WERROR
CMAKE_BUILD_TYPE=	Release

.include <bsd.port.mk>
