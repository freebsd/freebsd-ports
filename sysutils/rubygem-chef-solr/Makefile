# Created by: Scott Sanders <scott@jssjr.com>
# $FreeBSD$

PORTNAME=	chef-solr
PORTVERSION=	10.30.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Systems integration framework. Client part

LICENSE=	APACHE20

RUN_DEPENDS=	apache-solr>=0:${PORTSDIR}/textproc/apache-solr \
		rubygem-chef>=${PORTVERSION}:${PORTSDIR}/sysutils/rubygem-chef

#BROKEN=	fails to install

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/chef-solr \
		bin/chef-solr-installer

.include <bsd.port.mk>
