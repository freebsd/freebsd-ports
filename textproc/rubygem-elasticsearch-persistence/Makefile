PORTNAME=	elasticsearch-persistence
PORTVERSION=	8.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Persistence layer for Ruby models and Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-rails/tree/master/elasticsearch-persistence

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activemodel71>=4:databases/rubygem-activemodel71 \
		rubygem-activesupport71>=4:devel/rubygem-activesupport71 \
		rubygem-elasticsearch>=8<9:textproc/rubygem-elasticsearch \
		rubygem-elasticsearch-model>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-elasticsearch-model \
		rubygem-hashie>=0:devel/rubygem-hashie

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
