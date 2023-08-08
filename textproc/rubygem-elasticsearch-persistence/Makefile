PORTNAME=	elasticsearch-persistence
PORTVERSION=	7.2.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Persistence layer for Ruby models and Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-rails/tree/master/elasticsearch-persistence

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activemodel5>=4:databases/rubygem-activemodel5 \
		rubygem-activesupport5>=4:devel/rubygem-activesupport5 \
		rubygem-elasticsearch7>=7<8:textproc/rubygem-elasticsearch7 \
		rubygem-elasticsearch-model>=${PORTVERSION}:textproc/rubygem-elasticsearch-model \
		rubygem-hashie>=0:devel/rubygem-hashie

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
