PORTNAME=	elasticsearch
PORTVERSION=	9.1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby integrations for Elasticsearch
WWW=		https://github.com/elastic/elasticsearch-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-elastic-transport>=8.3<9:textproc/rubygem-elastic-transport \
		rubygem-elasticsearch-api>=${PORTVERSION}<${PORTVERSION}_99:textproc/rubygem-elasticsearch-api

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/elastic_ruby_console

.include <bsd.port.mk>
