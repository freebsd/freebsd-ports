# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	async-http
PORTVERSION=	0.48.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTTP client and server library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-async>=1.19<2:devel/rubygem-async \
		rubygem-async-io>=1.25<2:devel/rubygem-async-io \
		rubygem-protocol-http>=0.12.0<0.13:www/rubygem-protocol-http \
		rubygem-protocol-http1>=0.9.0<0.10:www/rubygem-protocol-http1 \
		rubygem-protocol-http2>=0.9.0<0.10:www/rubygem-protocol-http2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
