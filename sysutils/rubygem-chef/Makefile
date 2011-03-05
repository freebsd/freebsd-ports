# Ports collection makefile for:	rubygem-chef
# Date created:				19 Mar 2010
# Whom:					Renaud Chaput <renchap@cocoa-x.com>
#
# $FreeBSD$
#

PORTNAME=	chef
PORTVERSION=	0.9.12
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	A systems integration framework. Client part

BUILD_DEPENDS=	rubygem-mixlib-log>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-mixlib-config>=1.1.2:${PORTSDIR}/devel/rubygem-mixlib-config \
		rubygem-mixlib-cli>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-cli \
		rubygem-mixlib-authentication>=1.1.2:${PORTSDIR}/devel/rubygem-mixlib-authentication \
		rubygem-extlib>=0.9.14:${PORTSDIR}/devel/rubygem-extlib \
		rubygem-json>=1.4.4:${PORTSDIR}/devel/rubygem-json \
		rubygem-uuidtools>=0.0.0:${PORTSDIR}/devel/rubygem-uuidtools \
		rubygem-highline>=0.0.0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-moneta>=0.6.0:${PORTSDIR}/devel/rubygem-moneta \
		rubygem-erubis>=0.0.0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-rest-client>=1.0.4:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-bunny>=0.6.0:${PORTSDIR}/net/rubygem-bunny \
		rubygem-ohai>=0.5.7:${PORTSDIR}/sysutils/rubygem-ohai
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=		yes
USE_RUBYGEMS=		yes
USE_RUBY_FEATURES=	iconv
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/chef-client \
		bin/chef-solo \
		bin/shef \
		bin/knife

SUB_LIST=	RUBY=${RUBY}
USE_RC_SUBR=	chef_client

.include <bsd.port.mk>
