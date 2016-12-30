# Created by: Michael Moll <kvedulv@kvedulv.de>
# $FreeBSD$

PORTNAME=	hammer_cli
PORTVERSION=	0.9.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides CLI interfaces for Ruby apps

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-apipie-bindings>=0.0.14:devel/rubygem-apipie-bindings \
		rubygem-awesome_print>=0:devel/rubygem-awesome_print \
		rubygem-clamp>=1.0:devel/rubygem-clamp \
		rubygem-fast_gettext>=0:devel/rubygem-fast_gettext \
		rubygem-highline>=0:devel/rubygem-highline \
		rubygem-locale>=2.0.6:devel/rubygem-locale \
		rubygem-logging>=0:devel/rubygem-logging \
		rubygem-table_print>=0:devel/rubygem-table_print \
		rubygem-unicode-display_width>=0:devel/rubygem-unicode-display_width

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/cli_config.template.yml \
		${STAGEDIR}${PREFIX}/etc/hammer/cli_config.yml.sample

.include <bsd.port.mk>
