# $FreeBSD$

PORTNAME=	ykclient
PORTVERSION=	2.12
CATEGORIES=	security
MASTER_SITES=	http://opensource.yubico.com/yubico-c-client/releases/

MAINTAINER=	matt@mjslabs.com
COMMENT=	Yubico C client library

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	curl-config:${PORTSDIR}/ftp/curl \
		help2man:${PORTSDIR}/misc/help2man

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	bin/ykclient \
		include/ykclient.h \
		include/ykclient_errors.h \
		include/ykclient_server_response.h \
		include/ykclient_version.h \
		lib/libykclient.la \
		lib/libykclient.so \
		lib/libykclient.so.8 \
		man/man1/ykclient.1.gz

OPTIONS_DEFINE=	STATIC

STATIC_CONFIGURE_ENABLE=	static
STATIC_PLIST_FILES=		lib/libykclient.a

MAKE_JOBS_UNSAFE=	yes

regression-test: build
	@(cd ${WRKSRC}; ${MAKE} check)

.include <bsd.port.mk>
