PORTNAME=	elasticsearch-api
PORTVERSION=	8.19.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	8

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby API for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-ruby/tree/master/elasticsearch-api

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.

.include <bsd.port.mk>
