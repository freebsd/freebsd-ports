# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	1.0.8
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby integrations for Elasticsearch

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-elasticsearch-api=1.0.7:${PORTSDIR}/textproc/rubygem-elasticsearch-api \
		rubygem-elasticsearch-transport=1.0.7:${PORTSDIR}/textproc/rubygem-elasticsearch-transport

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

# NOTE: This port must be updated at the same time as textproc/rubygem-elasticsearch-api
# and textproc/rubygem-elasticsearch-transport

.include <bsd.port.mk>
