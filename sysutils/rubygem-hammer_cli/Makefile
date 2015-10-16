# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli
PORTVERSION=	0.4.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	mmoll@FreeBSD.org
COMMENT=	Provides CLI interfaces for Ruby apps

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-apipie-bindings>=0.0.14:${PORTSDIR}/devel/rubygem-apipie-bindings \
		rubygem-awesome_print>=1.1.0:${PORTSDIR}/devel/rubygem-awesome_print \
		rubygem-clamp>=1.0.0:${PORTSDIR}/devel/rubygem-clamp \
		rubygem-fast_gettext>=0.8.1:${PORTSDIR}/devel/rubygem-fast_gettext \
		rubygem-highline>=1.6.20:${PORTSDIR}/devel/rubygem-highline \
		rubygem-json>=1.8.1:${PORTSDIR}/devel/rubygem-json \
		rubygem-locale>=2.0.6:${PORTSDIR}/devel/rubygem-locale \
		rubygem-logging>=1.8.1:${PORTSDIR}/devel/rubygem-logging \
		rubygem-table_print>=1.5.1:${PORTSDIR}/devel/rubygem-table_print

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/cli_config.template.yml \
		${STAGEDIR}${PREFIX}/etc/hammer/cli_config.yml.sample

.include <bsd.port.mk>
