PORTNAME=	async-websocket
PORTVERSION=	0.30.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Async websocket library on top of websocket-driver
WWW=		https://socketry.github.io/async-websocket/ \
		https://github.com/socketry/async-websocket

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-async-http>=0.76<1:www/rubygem-async-http \
		rubygem-protocol-http>=0.34<1:www/rubygem-protocol-http \
		rubygem-protocol-rack>=0.7<1:www/rubygem-protocol-rack \
		rubygem-protocol-websocket>=0.17<1:www/rubygem-protocol-websocket

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
