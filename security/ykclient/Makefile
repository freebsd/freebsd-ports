# $FreeBSD$

PORTNAME=	ykclient
PORTVERSION=	2.15
CATEGORIES=	security
MASTER_SITES=	http://opensource.yubico.com/yubico-c-client/releases/

MAINTAINER=	matt@mjslabs.com
COMMENT=	Yubico C client library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
BUILD_DEPENDS=	curl-config:ftp/curl \
		help2man:misc/help2man

GNU_CONFIGURE=	yes
USES=		libtool pkgconfig
USE_LDCONFIG=	yes
TEST_TARGET=	check

PLIST_FILES=	bin/ykclient \
		include/ykclient.h \
		include/ykclient_errors.h \
		include/ykclient_server_response.h \
		include/ykclient_version.h \
		lib/libykclient.so \
		lib/libykclient.so.3 \
		lib/libykclient.so.3.6.0 \
		man/man1/ykclient.1.gz

OPTIONS_DEFINE=	STATIC

STATIC_CONFIGURE_ENABLE=	static
STATIC_PLIST_FILES=		lib/libykclient.a

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
