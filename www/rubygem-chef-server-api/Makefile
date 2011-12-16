# Ports collection makefile for:	rubygem-chef-server-api
# Date created:				13 Dec 2011
# Whom:					Scott Sanders <scott@jssjr.com>
#
# $FreeBSD$
#

PORTNAME=	chef-server-api
PORTVERSION=	0.10.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A systems integration framework. Server API

RUN_DEPENDS=	rubygem-dep_selector>=0.0.3:${PORTSDIR}/devel/rubygem-dep_selector \
		rubygem-json>=1.4.4:${PORTSDIR}/devel/rubygem-json146 \
		rubygem-merb-assets>=1.1.0:${PORTSDIR}/www/rubygem-merb-assets \
		rubygem-merb-core>=1.1.0:${PORTSDIR}/www/rubygem-merb-core \
		rubygem-merb-helpers>=1.1.0:${PORTSDIR}/www/rubygem-merb-helpers \
		rubygem-merb-param-protection>=1.1.0:${PORTSDIR}/www/rubygem-merb-param-protection \
		rubygem-mixlib-authentication>=1.1.3:${PORTSDIR}/devel/rubygem-mixlib-authentication \
		rubygem-thin>=0:${PORTSDIR}/www/rubygem-thin \
		rubygem-uuidtools>=2.1.1:${PORTSDIR}/devel/rubygem-uuidtools

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/chef-server

.include <bsd.port.mk>
