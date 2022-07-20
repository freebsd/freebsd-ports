PORTNAME=	faraday-net_http_persistent
PORTVERSION=	2.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Faraday adapter for NetHttpPersistent

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-net_http>=0:www/rubygem-faraday-net_http \
		rubygem-net-http-persistent>=4.0<5:www/rubygem-net-http-persistent

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
