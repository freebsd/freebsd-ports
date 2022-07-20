PORTNAME=	async-http
PORTVERSION=	0.56.6
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client and server library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-async>=1.25:devel/rubygem-async \
		rubygem-async-io>=1.28:devel/rubygem-async-io \
		rubygem-async-pool>=0.2:www/rubygem-async-pool \
		rubygem-protocol-http>=0.22.0<0.23:www/rubygem-protocol-http \
		rubygem-protocol-http1>=0.14.0<0.15:www/rubygem-protocol-http1 \
		rubygem-protocol-http2>=0.14.0<0.15:www/rubygem-protocol-http2 \
		rubygem-traces>=0.4.0:devel/rubygem-traces

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
