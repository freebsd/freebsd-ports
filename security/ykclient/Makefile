# $FreeBSD$

PORTNAME=	ykclient
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	matt@mjslabs.com
COMMENT=	Yubico C client library

LICENSE=	BSD

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	curl-config:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	bin/ykclient \
		include/ykclient.h \
		include/ykclient_server_response.h \
		lib/libykclient.a \
		lib/libykclient.la \
		lib/libykclient.so \
		lib/libykclient.so.7

PROJECTHOST=	yubico-c-client

MAKE_JOBS_UNSAFE=	yes

regression-test: build
	@(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
