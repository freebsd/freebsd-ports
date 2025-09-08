PORTNAME=	hammer_cli_foreman
PORTVERSION=	3.16.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Foreman commands for Hammer CLI
WWW=		https://github.com/theforeman/hammer-cli-foreman

LICENSE=	GPLv3+

RUN_DEPENDS=	rubygem-apipie-bindings>=0.7.0:devel/rubygem-apipie-bindings \
		rubygem-hammer_cli>=${PORTVERSION:R}.0:sysutils/rubygem-hammer_cli \
		rubygem-jwt>=2.2.1:www/rubygem-jwt \
		rubygem-rest-client>=1.8.0<3.0.0:www/rubygem-rest-client

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	"@sample etc/hammer/cli.modules.d/foreman.yml.sample"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/foreman.yml ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d/foreman.yml.sample

.include <bsd.port.mk>
