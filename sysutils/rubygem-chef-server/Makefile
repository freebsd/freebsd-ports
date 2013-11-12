# Created by: Scott Sanders <scott@jssjr.com>
# $FreeBSD$

PORTNAME=	chef-server
PORTVERSION=	10.28.0
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A systems integration framework. Server

RUN_DEPENDS=	rubygem-chef-expander>=${PORTREVISION}:${PORTSDIR}/sysutils/rubygem-chef-expander \
		rubygem-chef-server-api>=${PORTREVISION}:${PORTSDIR}/www/rubygem-chef-server-api \
		rubygem-chef-server-webui>=${PORTREVISION}:${PORTSDIR}/www/rubygem-chef-server-webui \
		rubygem-chef-solr>=${PORTREVISION}:${PORTSDIR}/sysutils/rubygem-chef-solr

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
