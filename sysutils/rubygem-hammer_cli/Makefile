PORTNAME=	hammer_cli
PORTVERSION=	3.3.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides CLI interfaces for Ruby apps

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-amazing_print>=0:devel/rubygem-amazing_print \
		rubygem-apipie-bindings>=0.5.0:devel/rubygem-apipie-bindings \
		rubygem-clamp11>=1.1<1.2.0:devel/rubygem-clamp11 \
		rubygem-fast_gettext>=0:devel/rubygem-fast_gettext \
		rubygem-highline>=0:devel/rubygem-highline \
		rubygem-locale>=2.0.6:devel/rubygem-locale \
		rubygem-logging>=0:devel/rubygem-logging \
		rubygem-unicode>=0:devel/rubygem-unicode \
		rubygem-unicode-display_width>=0:devel/rubygem-unicode-display_width

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/hammer \
		bin/hammer-complete \
		"@sample etc/hammer/cli_config.yml.sample" \
		"@dir etc/hammer/cli.modules.d"

CPE_VENDOR=	theforeman

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/hammer/cli.modules.d
	${INSTALL_DATA} ${WRKSRC}/config/cli_config.template.yml ${STAGEDIR}${PREFIX}/etc/hammer/cli_config.yml.sample

.include <bsd.port.mk>
