PORTNAME=	elasticsearch-transport
PORTVERSION=	7.17.10
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-ruby/tree/master/elasticsearch-transport

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday>=1<3:www/rubygem-faraday \
		rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
