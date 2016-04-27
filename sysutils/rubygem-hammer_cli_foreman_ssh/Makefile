# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli_foreman_ssh
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SSH host commands for Hammer CLI

LICENSE=	GPLv3+

RUN_DEPENDS=	rubygem-hammer_cli>=0.0.6:sysutils/rubygem-hammer_cli \
		rubygem-hammer_cli_foreman>=0:sysutils/rubygem-hammer_cli_foreman \
		rubygem-net-ssh-multi>=1.2.1:security/rubygem-net-ssh-multi

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	"@sample etc/hammer/cli.modules.d/foreman_ssh.yml.sample"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/foreman_ssh.yml ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d/foreman_ssh.yml.sample

.include <bsd.port.mk>
