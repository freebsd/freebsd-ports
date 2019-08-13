# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-persistence
PORTVERSION=	6.1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Persistence layer for Ruby models and Elasticsearch

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-activemodel5>=4:databases/rubygem-activemodel5 \
		rubygem-activesupport5>=4:devel/rubygem-activesupport5 \
		rubygem-elasticsearch6>=6:textproc/rubygem-elasticsearch6 \
		rubygem-elasticsearch-model>=5:textproc/rubygem-elasticsearch-model \
		rubygem-hashie>=0:devel/rubygem-hashie

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
