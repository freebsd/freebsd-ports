PORTNAME=	libcapn
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	C Library to interact with Apple Push Notification Service
WWW=		https://github.com/adobkin/libcapn

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Fails to build with CMake 4
DEPRECATED=	Archived upstream, does not build with CMake 4
EXPIRATION_DATE=2026-11-30

LIB_DEPENDS=	libjansson.so:devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	adobkin

USES=		cmake ssl
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DOS_FREEBSD=yes \
		-DCAPN_INSTALL_PATH_PKGCONFIG=${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
