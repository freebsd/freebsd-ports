PORTNAME=	async-websocket
PORTVERSION=	0.19.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Async websocket library on top of websocket-driver

LICENSE=	MIT

RUN_DEPENDS=	rubygem-async-http>=0.54<1:www/rubygem-async-http \
		rubygem-async-io>=1.23<2:devel/rubygem-async-io \
		rubygem-protocol-websocket>=0.7.0<0.8:www/rubygem-protocol-websocket

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
