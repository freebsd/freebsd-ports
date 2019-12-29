# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	async-http
PORTVERSION=	0.50.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client and server library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-async>=1.23<2:devel/rubygem-async \
		rubygem-async-io>=1.27.0<1.28:devel/rubygem-async-io \
		rubygem-async-pool>=0.2<1:www/rubygem-async-pool \
		rubygem-protocol-http>=0.13.0<0.14:www/rubygem-protocol-http \
		rubygem-protocol-http1>=0.10.0<0.11:www/rubygem-protocol-http1 \
		rubygem-protocol-http2>=0.10.0<0.11:www/rubygem-protocol-http2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
