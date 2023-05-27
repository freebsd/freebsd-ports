PORTNAME=	elasticsearch-transport
PORTVERSION=	7.17.7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby client for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-ruby/tree/master/elasticsearch-transport

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday1>=1<2:www/rubygem-faraday1 \
		rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
