PORTNAME=	elasticsearch-transport
PORTVERSION=	7.17.11
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-ruby/tree/master/elasticsearch-transport

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday-gitlab>=1<3:www/rubygem-faraday-gitlab \
		rubygem-multi_json-gitlab>=0:devel/rubygem-multi_json-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
