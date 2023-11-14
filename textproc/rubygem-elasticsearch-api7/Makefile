PORTNAME=	elasticsearch-api
PORTVERSION=	7.17.10
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	7

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby API for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-ruby/tree/master/elasticsearch-api

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.

.include <bsd.port.mk>
