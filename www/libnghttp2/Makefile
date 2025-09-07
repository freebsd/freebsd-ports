PORTNAME=	nghttp2
PORTVERSION=	1.67.0
CATEGORIES=	www net
MASTER_SITES=	https://github.com/nghttp2/nghttp2/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP/2 C Library
WWW=		https://nghttp2.org/ \
		https://github.com/nghttp2/nghttp2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-lib-only
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
