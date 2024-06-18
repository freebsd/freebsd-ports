PORTNAME=	async-http
PORTVERSION=	0.67.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client and server library
WWW=		https://socketry.github.io/async-http/ \
		https://github.com/socketry/async-http

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-async>=2.10.2:devel/rubygem-async \
		rubygem-async-pool>=0.6.1:www/rubygem-async-pool \
		rubygem-io-endpoint>=0.10.3<1:devel/rubygem-io-endpoint \
		rubygem-io-stream>=0.4<1:devel/rubygem-io-stream \
		rubygem-protocol-http>=0.26.0<0.27:www/rubygem-protocol-http \
		rubygem-protocol-http1>=0.19.0<0.20:www/rubygem-protocol-http1 \
		rubygem-protocol-http2>=0.18.0<0.19:www/rubygem-protocol-http2 \
		rubygem-traces>=0.10.0:devel/rubygem-traces

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
