PORTNAME=	nghttp2
DISTVERSION=	1.51.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2.0 C Library
WWW=		https://nghttp2.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang pathfix pkgconfig tar:xz

USE_LDCONFIG=	yes

CMAKE_OFF=	ENABLE_DOC \
		ENABLE_HTTP3 \
		ENABLE_PYTHON_BINDINGS
CMAKE_ON=	ENABLE_LIB_ONLY \
		ENABLE_STATIC_LIB

.include <bsd.port.mk>
