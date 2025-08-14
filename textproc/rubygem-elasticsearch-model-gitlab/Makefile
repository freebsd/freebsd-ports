PORTNAME=	elasticsearch-model
PORTVERSION=	7.2.1
PORTREVISION=	2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActiveModel/Record integrations for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-rails/tree/master/elasticsearch-model

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport-gitlab>=3:devel/rubygem-activesupport-gitlab \
		rubygem-elasticsearch-gitlab>=7<8:textproc/rubygem-elasticsearch-gitlab \
		rubygem-hashie>=0:devel/rubygem-hashie

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
