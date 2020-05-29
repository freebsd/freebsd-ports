# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	7.7.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby integrations for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-elasticsearch-api=${PORTVERSION}:textproc/rubygem-elasticsearch-api \
		rubygem-elasticsearch-transport=${PORTVERSION}:textproc/rubygem-elasticsearch-transport

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/elastic_ruby_console

.include <bsd.port.mk>
