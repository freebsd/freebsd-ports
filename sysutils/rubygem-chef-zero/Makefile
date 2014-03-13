# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef-zero
PORTVERSION=	1.7.3
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Self-contained, easy-setup, fast-start in-memory Chef server

RUN_DEPENDS=	rubygem-hashie>=2.0.0:${PORTSDIR}/devel/rubygem-hashie \
		rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json \
		rubygem-moneta06>=0.0.0:${PORTSDIR}/devel/rubygem-moneta06 \
		rubygem-mixlib-log>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-rack>=0.0.0:${PORTSDIR}/www/rubygem-rack

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=		bin/chef-zero

.include <bsd.port.mk>
