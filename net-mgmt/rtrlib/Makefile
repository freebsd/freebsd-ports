PORTNAME=	rtrlib
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-mgmt sysutils

MAINTAINER=	freebsd@bodems.net
COMMENT=	Open-source C implementation of the RPKI/Router Protocol client
WWW=		https://rtrlib.realmv6.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libssh.so:security/libssh

USES=		cmake pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DRTRLIB_TRANSPORT_SSH=Yes
CMAKE_ARGS+=	-DWITH_BGPSEC=Yes
CMAKE_ARGS+=	-DLIBSSH_LIBRARIES=${LOCALBASE}/lib/libssh.so
CMAKE_ARGS+=	-DLIBSSH_INCLUDE_DIRS=${LOCALBASE}/include

.include <bsd.port.mk>
