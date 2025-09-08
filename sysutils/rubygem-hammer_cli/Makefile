PORTNAME=	hammer_cli
PORTVERSION=	3.16.0
CATEGORIES=	sysutils ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Provides CLI interfaces for Ruby apps
WWW=		https://github.com/theforeman/hammer-cli

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-amazing_print>=0:devel/rubygem-amazing_print \
		rubygem-apipie-bindings>=0.7.0:devel/rubygem-apipie-bindings \
		rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-clamp>=1.3.1<2.0.0:devel/rubygem-clamp \
		rubygem-csv>=0:devel/rubygem-csv \
		rubygem-fast_gettext>=0:devel/rubygem-fast_gettext \
		rubygem-highline>=0:devel/rubygem-highline \
		rubygem-locale>=2.0.6:devel/rubygem-locale \
		rubygem-logging>=0:devel/rubygem-logging \
		rubygem-unicode-display_width>=0:devel/rubygem-unicode-display_width

USES=		cpe gem

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
