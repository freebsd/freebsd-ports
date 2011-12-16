# Ports collection makefile for:	rubygem-chef
# Date created:				19 Mar 2010
# Whom:					Renaud Chaput <renchap@cocoa-x.com>
#
# $FreeBSD$
#

PORTNAME=	chef
PORTVERSION=	0.10.8
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	A systems integration framework. Client part

RUN_DEPENDS=	rubygem-mixlib-log>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-mixlib-config>=1.1.2:${PORTSDIR}/devel/rubygem-mixlib-config \
		rubygem-mixlib-cli>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-cli \
		rubygem-mixlib-authentication>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-authentication \
		rubygem-json>=1.4.4:${PORTSDIR}/devel/rubygem-json146 \
		rubygem-uuidtools>=0:${PORTSDIR}/devel/rubygem-uuidtools \
		rubygem-highline>=0:${PORTSDIR}/devel/rubygem-highline \
		rubygem-moneta>=0:${PORTSDIR}/devel/rubygem-moneta \
		rubygem-erubis>=0:${PORTSDIR}/www/rubygem-erubis \
		rubygem-rest-client>=1.7.0:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-bunny>=0.6.0:${PORTSDIR}/net/rubygem-bunny \
		rubygem-ohai>=0.6.0:${PORTSDIR}/sysutils/rubygem-ohai \
		rubygem-net-ssh>=2.1.3:${PORTSDIR}/security/rubygem-net-ssh \
		rubygem-net-ssh-multi>=1.1.0:${PORTSDIR}/security/rubygem-net-ssh-multi \
		rubygem-treetop>=1.4.9:${PORTSDIR}/devel/rubygem-treetop

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
