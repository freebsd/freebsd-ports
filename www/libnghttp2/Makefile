# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	nghttp2
PORTVERSION=	1.48.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/nghttp2/nghttp2/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2.0 C Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++14-lang cpe libtool pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-lib-only
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

.include <bsd.port.mk>
