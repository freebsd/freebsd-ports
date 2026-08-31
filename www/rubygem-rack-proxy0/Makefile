PORTNAME=	rack-proxy
PORTVERSION=	0.8.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	0

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Request/response rewriting proxy capabilities with streaming
WWW=		https://github.com/ncr/rack-proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-rack>=0,3:www/rubygem-rack

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.

.include <bsd.port.mk>
