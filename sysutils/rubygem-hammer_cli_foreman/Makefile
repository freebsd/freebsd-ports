# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli_foreman
PORTVERSION=	0.10.2
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Foreman commands for Hammer CLI

LICENSE=	GPLv3+

RUN_DEPENDS=	rubygem-apipie-bindings>=0.2.0:devel/rubygem-apipie-bindings \
		rubygem-hammer_cli>=${PORTVERSION}:sysutils/rubygem-hammer_cli \
		rubygem-rest-client>=1.8.0:www/rubygem-rest-client

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	"@sample etc/hammer/cli.modules.d/foreman.yml.sample"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/foreman.yml \
		${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d/foreman.yml.sample

.include <bsd.port.mk>
