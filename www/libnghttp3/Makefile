# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	nghttp3
PORTVERSION=	0.1.1
CATEGORIES=	www net
MASTER_SITES=	https://github.com/ngtcp2/nghttp3/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/3 C Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++17-lang libtool pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-lib-only
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

.include <bsd.port.mk>
