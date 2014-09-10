# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch-transport
PORTVERSION=	1.0.5
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby client for Elasticsearch

RUN_DEPENDS=	rubygem-faraday>0:${PORTSDIR}/www/rubygem-faraday \
		rubygem-multi_json>0:${PORTSDIR}/devel/rubygem-multi_json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

# NOTE: This port must be updated at the same time as textproc/rubygem-elasticsearch
# and textproc/rubygem-elasticsearch-api

.include <bsd.port.mk>
