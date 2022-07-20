PORTNAME=	elasticsearch
PORTVERSION=	7.13.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	713

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby integrations for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-elasticsearch-api713>=${PORTVERSION}:textproc/rubygem-elasticsearch-api713 \
		rubygem-elasticsearch-transport713>=${PORTVERSION}:textproc/rubygem-elasticsearch-transport713

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.13\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/elastic_ruby_console

.include <bsd.port.mk>
