PORTNAME=	protocol-http2
PORTVERSION=	0.18.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low level implementation of the HTTP/2 protocol
WWW=		https://socketry.github.io/protocol-http2/ \
		https://github.com/socketry/protocol-http2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-protocol-hpack>=1.4<2:www/rubygem-protocol-hpack \
		rubygem-protocol-http>=0.18<1:www/rubygem-protocol-http

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
