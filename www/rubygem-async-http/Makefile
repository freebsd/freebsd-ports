PORTNAME=	async-http
PORTVERSION=	0.64.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client and server library
WWW=		https://github.com/socketry/async-http

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-async>=1.25:devel/rubygem-async \
		rubygem-async-io>=1.28:devel/rubygem-async-io \
		rubygem-async-pool>=0.2:www/rubygem-async-pool \
		rubygem-protocol-http>=0.26.0<0.27:www/rubygem-protocol-http \
		rubygem-protocol-http1>=0.19.0<0.20:www/rubygem-protocol-http1 \
		rubygem-protocol-http2>=0.16.0<0.17:www/rubygem-protocol-http2 \
		rubygem-traces>=0.10.0:devel/rubygem-traces

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
