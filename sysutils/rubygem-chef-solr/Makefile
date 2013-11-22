# Created by: Scott Sanders <scott@jssjr.com>
# $FreeBSD$

PORTNAME=	chef-solr
PORTVERSION=	11.0.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A systems integration framework. Client part

RUN_DEPENDS=	rubygem-chef>=${PORTVERSION}:${PORTSDIR}/sysutils/rubygem-chef \
		apache-solr>=0:${PORTSDIR}/textproc/apache-solr

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes
USERS=	chef_server
GROUPS=	chef_server

PLIST_FILES=	bin/chef-solr \
		bin/chef-solr-installer

DISTVERSIONSUFFIX=	.alpha.1
GEM_NAME=	${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}
MASTER_SITE_RUBYGEMS=	http://dist.reallyenglish.com/pub/gems/%SUBDIR%/

.include <bsd.port.mk>
