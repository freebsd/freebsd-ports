PORTNAME=	elastic-transport
PORTVERSION=	8.4.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low level Ruby client for Elastic
WWW=		https://github.com/elastic/elastic-transport-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday>=0<3:www/rubygem-faraday \
		rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
