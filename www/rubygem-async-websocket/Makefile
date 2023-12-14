PORTNAME=	async-websocket
PORTVERSION=	0.26.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Async websocket library on top of websocket-driver
WWW=		https://github.com/socketry/async-websocket

LICENSE=	MIT

RUN_DEPENDS=	rubygem-async-http>=0.54<1:www/rubygem-async-http \
		rubygem-async-io>=1.23<2:devel/rubygem-async-io \
		rubygem-protocol-rack>=0.1<1:www/rubygem-protocol-rack \
		rubygem-protocol-websocket>=0.11<1:www/rubygem-protocol-websocket

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
