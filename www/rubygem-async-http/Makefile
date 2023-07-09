PORTNAME=	async-http
PORTVERSION=	0.60.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client and server library
WWW=		https://github.com/socketry/async-http

LICENSE=	MIT

RUN_DEPENDS=	rubygem-async>=1.25:devel/rubygem-async \
		rubygem-async-io>=1.28:devel/rubygem-async-io \
		rubygem-async-pool>=0.2:www/rubygem-async-pool \
		rubygem-protocol-http>=0.24.0<0.25:www/rubygem-protocol-http \
		rubygem-protocol-http1>=0.15.0<0.16:www/rubygem-protocol-http1 \
		rubygem-protocol-http2>=0.15.0<0.16:www/rubygem-protocol-http2 \
		rubygem-traces>=0.10.0:devel/rubygem-traces

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
