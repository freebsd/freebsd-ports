PORTNAME=	elasticsearch
PORTVERSION=	7.17.10
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	7

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby integrations for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-elasticsearch-api7>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-elasticsearch-api7 \
		rubygem-elasticsearch-transport>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-elasticsearch-transport

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/elastic_ruby_console

.include <bsd.port.mk>
