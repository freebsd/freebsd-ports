PORTNAME=	elasticsearch
PORTVERSION=	7.17.11
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby integrations for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-elasticsearch-api-gitlab>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-elasticsearch-api-gitlab \
		rubygem-elasticsearch-transport-gitlab>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-elasticsearch-transport-gitlab

USES=		gem

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/elastic_ruby_console

.include <bsd.port.mk>
