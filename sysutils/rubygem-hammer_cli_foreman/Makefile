# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli_foreman
PORTVERSION=	0.0.18
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Foreman commands for Hammer CLI

LICENSE=	GPLv3

RUN_DEPENDS=	rubygem-foreman_api>=0.1.11:${PORTSDIR}/devel/rubygem-foreman_api \
		rubygem-hammer_cli>=0.0.18:${PORTSDIR}/sysutils/rubygem-hammer_cli

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
