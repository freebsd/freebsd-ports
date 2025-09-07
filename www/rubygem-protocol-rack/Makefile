PORTNAME=	protocol-rack
PORTVERSION=	0.16.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implementation of the Rack protocol/specification
WWW=		https://socketry.github.io/protocol-rack/ \
		https://github.com/socketry/protocol-rack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.md

RUN_DEPENDS=	rubygem-io-stream>=0.10:devel/rubygem-io-stream \
		rubygem-protocol-http>=0.43<1:www/rubygem-protocol-http \
		rubygem-rack>=1.0,3:www/rubygem-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
