# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli_foreman_bootdisk
PORTVERSION=	0.3.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Foreman bootdisk commands for Hammer CLI

LICENSE=	GPLv3+

RUN_DEPENDS=	rubygem-hammer_cli_foreman>=0.1.2:sysutils/rubygem-hammer_cli_foreman

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	"@sample etc/hammer/cli.modules.d/foreman_bootdisk.yml.sample"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/foreman_bootdisk.yml ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d/foreman_bootdisk.yml.sample

.include <bsd.port.mk>
