# Created by: Scott Sanders <scott@jssjr.com>
# $FreeBSD$

PORTNAME=	chef-server
PORTVERSION=	10.30.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Systems integration framework. Server

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-chef-expander>=${PORTREVISION}:${PORTSDIR}/sysutils/rubygem-chef-expander \
		rubygem-chef-server-api>=${PORTREVISION}:${PORTSDIR}/www/rubygem-chef-server-api \
		rubygem-chef-server-webui>=${PORTREVISION}:${PORTSDIR}/www/rubygem-chef-server-webui \
		rubygem-chef-solr>=${PORTREVISION}:${PORTSDIR}/sysutils/rubygem-chef-solr

DEPRECATED=	Depends on broken rubygem-dep_selector
EXPIRES=	2014-09-25

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
