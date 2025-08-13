PORTNAME=	redmine
PORTVERSION=	6.0.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://www.redmine.org/releases/
PKGNAMESUFFIX=	60

# mikael@FreeBSD.org also have full maintainership
MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Flexible project management web application
WWW=		https://www.redmine.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	rubygem-actionpack-xml_parser-rails72>=0:textproc/rubygem-actionpack-xml_parser-rails72 \
		rubygem-addressable>0:www/rubygem-addressable \
		rubygem-bundler>=1.12.0:sysutils/rubygem-bundler \
		rubygem-csv>=3.2.6:devel/rubygem-csv \
		rubygem-debug>=0:devel/rubygem-debug \
		rubygem-erb>0:devel/rubygem-erb \
		rubygem-globalid-rails72>0:databases/rubygem-globalid-rails72 \
		rubygem-i18n>=1.14.1:devel/rubygem-i18n \
		rubygem-mail>=2.8.1:mail/rubygem-mail \
		rubygem-marcel>0:devel/rubygem-marcel \
		rubygem-mini_mime>=1.1.0:mail/rubygem-mini_mime \
		rubygem-mini_portile2>=2.8.2:devel/rubygem-mini_portile2 \
		rubygem-mocha>=0.5.3:devel/rubygem-mocha \
		rubygem-net-imap>=0.3.4:mail/rubygem-net-imap \
		rubygem-net-ldap>=0.19.0:net/rubygem-net-ldap \
		rubygem-net-pop>=0.1.2:mail/rubygem-net-pop \
		rubygem-net-smtp>=0.3.3:mail/rubygem-net-smtp \
		rubygem-nokogiri>=1.15.2:textproc/rubygem-nokogiri \
		rubygem-rails72>=7.2.2:www/rubygem-rails72 \
		rubygem-rbpdf>=1.21.3:print/rubygem-rbpdf \
		rubygem-request_store15>=1.5.1:devel/rubygem-request_store15 \
		rubygem-roadie-rails-rails72>=3.2.0:mail/rubygem-roadie-rails-rails72 \
		rubygem-rotp>=5.0.0:devel/rubygem-rotp \
		rubygem-rouge>=4.2.0:textproc/rubygem-rouge \
		rubygem-rqrcode>0:www/rubygem-rqrcode \
		rubygem-rubocop-performance>=0:devel/rubygem-rubocop-performance \
		rubygem-rubocop-rails>0:devel/rubygem-rubocop-rails \
		rubygem-rubocop>0<2:devel/rubygem-rubocop \
		rubygem-rubyzip>0:archivers/rubygem-rubyzip \
		rubygem-simplecov>0:devel/rubygem-simplecov \
		rubygem-svg_sprite>=0:graphics/rubygem-svg_sprite \
		rubygem-yard>=0:textproc/rubygem-yard

# Per https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=264638#c9
# to be removed if https://www.redmine.org/issues/37394 is fixed
RUN_DEPENDS+=	rubygem-redcarpet>=3.6.0:textproc/rubygem-redcarpet \
		rubygem-html-pipeline>=2.13.2:textproc/rubygem-html-pipeline \
		rubygem-commonmarker0>=0.23.8:textproc/rubygem-commonmarker0 \
		rubygem-sanitize>=6.0:textproc/rubygem-sanitize \
		rubygem-deckar01-task_list>=2.3.2:www/rubygem-deckar01-task_list

USES=		cpe ruby

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	RUBY_SUFFIX=${RUBY_SUFFIX}

OPTIONS_DEFINE=	MYSQL POSTGRESQL PUMA MARKDOWN RMAGIC
OPTIONS_DEFAULT=MYSQL MARKDOWN PUMA RMAGIC
OPTIONS_SUB=	yes
POSTGRESQL_DESC=Enable PostgreSQL support
MARKDOWN_DESC=	Enable Markdown support
PUMA_DESC=	Use Puma WEB server
RMAGIC_DESC=	Enable Gantt charts support
MYSQL_DESC=	MySQL database support (via mysql2 rubygem)
NO_OPTIONS_SORT=	yes
MYSQL_RUN_DEPENDS=	rubygem-mysql2>=0.5.0:databases/rubygem-mysql2 \
			rubygem-with_advisory_lock61>0:devel/rubygem-with_advisory_lock61
POSTGRESQL_RUN_DEPENDS=	rubygem-pg>=1.2.2:databases/rubygem-pg
PUMA_RUN_DEPENDS=	rubygem-puma>=6.5.0<7:www/rubygem-puma \
			rubygem-rb-kqueue>=0.2:devel/rubygem-rb-kqueue
PUMA_SUB_LIST=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PUMA_VARS=		USE_RC_SUBR=redmine
MARKDOWN_RUN_DEPENDS=	rubygem-redcarpet>=3.5.1:textproc/rubygem-redcarpet
RMAGIC_RUN_DEPENDS=	rubygem-mini_magick4>=4.11.0:graphics/rubygem-mini_magick4

.include <bsd.port.options.mk>

post-extract:
	@${RM} -r ${WRKSRC}/.hgignore ${WRKSRC}/.gitignore ${WRKSRC}/.github \
		${WRKSRC}/files/delete.me ${WRKSRC}/log/delete.me
	@${MV} ${WRKSRC}/config/settings.yml ${WRKSRC}/config/settings.yml.sample
	@${MV} ${WRKSRC}/config/database.yml.example ${WRKSRC}/config/database.yml.sample

post-patch:
	@${RM} ${WRKSRC}/Gemfile.orig

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/bundler.d
	${MKDIR} ${STAGEDIR}${WWWDIR}/log
	${MKDIR} ${STAGEDIR}${WWWDIR}/public/plugin_assets
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp

	# https://www.redmine.org/issues/37394
	${CP} ${FILESDIR}/commonmark.rb ${STAGEDIR}${WWWDIR}/bundler.d
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${TOUCH} ${STAGEDIR}${WWWDIR}/Gemfile.lock

do-install-MYSQL-on:
	${CP} ${FILESDIR}/mysql.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-POSTGRESQL-on:
	${CP} ${FILESDIR}/pg.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-MARKDOWN-on:
	${CP} ${FILESDIR}/markdown.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-RMAGIC-on:
	${CP} ${FILESDIR}/mini_magick.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-PUMA-on:
	${CP} ${FILESDIR}/puma.rb ${STAGEDIR}${WWWDIR}/bundler.d

post-install:
	(cd ${STAGEDIR}${WWWDIR} && ${RM} Gemfile.lock && bundle install --local)
	${RM} ${STAGEDIR}${WWWDIR}/package.json \
		${STAGEDIR}${WWWDIR}/yarn.lock

.include <bsd.port.mk>
