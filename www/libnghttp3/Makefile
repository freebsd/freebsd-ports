PORTNAME=	nghttp3
PORTVERSION=	1.11.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/ngtcp2/nghttp3/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/3 C Library
WWW=		https://nghttp2.org/nghttp3/ \
		https://github.com/ngtcp2/nghttp3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-lib-only
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
