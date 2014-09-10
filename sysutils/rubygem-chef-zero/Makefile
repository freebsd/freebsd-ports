# Created by: Renaud Chaput <renchap@cocoa-x.com>
# $FreeBSD$

PORTNAME=	chef-zero
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Self-contained, easy-setup, fast-start in-memory Chef server

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-hashie2>=2.0.0:${PORTSDIR}/devel/rubygem-hashie2 \
		rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json \
		rubygem-mixlib-log>=1.3.0:${PORTSDIR}/devel/rubygem-mixlib-log \
		rubygem-rack>=0.0.0:${PORTSDIR}/www/rubygem-rack

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=		bin/chef-zero

.include <bsd.port.mk>
