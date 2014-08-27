# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli_foreman
PORTVERSION=	0.1.3
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	kvedulv@kvedulv.de
COMMENT=	Foreman commands for Hammer CLI

LICENSE=	GPLv3

RUN_DEPENDS=	rubygem-apipie-bindings>=0.0.8:${PORTSDIR}/devel/rubygem-apipie-bindings \
		rubygem-hammer_cli>=0.1.2:${PORTSDIR}/sysutils/rubygem-hammer_cli \
		rubygem-rest-client>=1.6.7:${PORTSDIR}/www/rubygem-rest-client

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
		${INSTALL_DATA} ${FILESDIR}/foreman.yml.sample ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d/foreman.yml.sample

.include <bsd.port.post.mk>
