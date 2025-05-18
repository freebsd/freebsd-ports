PORTNAME=	elasticsearch-model
PORTVERSION=	8.0.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ActiveModel/Record integrations for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-rails/tree/master/elasticsearch-model

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport71>=3:devel/rubygem-activesupport71 \
		rubygem-elasticsearch8>=8<9:textproc/rubygem-elasticsearch8 \
		rubygem-hashie>=0:devel/rubygem-hashie

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
