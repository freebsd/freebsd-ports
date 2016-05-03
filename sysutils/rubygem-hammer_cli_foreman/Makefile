# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli_foreman
PORTVERSION=	0.6.2
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Foreman commands for Hammer CLI

LICENSE=	GPLv3+

RUN_DEPENDS=	rubygem-apipie-bindings>=0.0.16:devel/rubygem-apipie-bindings \
		rubygem-hammer_cli>=0.6.0:sysutils/rubygem-hammer_cli

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/foreman.yml \
		${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d/foreman.yml.sample

.include <bsd.port.mk>
