# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli_foreman
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	Foreman commands for Hammer CLI

LICENSE=	GPLv3

RUN_DEPENDS=	rubygem-apipie-bindings>=0.0.11:${PORTSDIR}/devel/rubygem-apipie-bindings \
		rubygem-hammer_cli>=0.2.0:${PORTSDIR}/sysutils/rubygem-hammer_cli \
		rubygem-rest-client>=1.6.7:${PORTSDIR}/www/rubygem-rest-client

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/foreman.yml \
		${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d/foreman.yml.sample

.include <bsd.port.mk>
