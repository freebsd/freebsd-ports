PORTNAME=	async-http
PORTVERSION=	0.91.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client and server library
WWW=		https://socketry.github.io/async-http/ \
		https://github.com/socketry/async-http

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-async>=2.10.2:devel/rubygem-async \
		rubygem-async-pool>=0.11<1:www/rubygem-async-pool \
		rubygem-io-endpoint>=0.14<1:devel/rubygem-io-endpoint \
		rubygem-io-stream>=0.6<1:devel/rubygem-io-stream \
		rubygem-metrics>=0.12<1:devel/rubygem-metrics \
		rubygem-protocol-http>=0.49<1:www/rubygem-protocol-http \
		rubygem-protocol-http1>=0.30<1:www/rubygem-protocol-http1 \
		rubygem-protocol-http2>=0.22<1:www/rubygem-protocol-http2 \
		rubygem-traces>=0.10<1:devel/rubygem-traces

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
