PORTNAME=	redmine
PORTVERSION=	6.1.2
CATEGORIES=	www
MASTER_SITES=	https://www.redmine.org/releases/
PKGNAMESUFFIX=	61

# mikael@FreeBSD.org also have full maintainership
MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Flexible project management web application
WWW=		https://www.redmine.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	rubygem-actionpack-xml_parser-rails72>=0:textproc/rubygem-actionpack-xml_parser-rails72 \
		rubygem-addressable>0:www/rubygem-addressable \
		rubygem-bcrypt>=3.0<4:security/rubygem-bcrypt \
		rubygem-bullet-rails72>0:devel/rubygem-bullet-rails72 \
		rubygem-bundle-audit>0:sysutils/rubygem-bundle-audit \
		rubygem-bundler>=1.12.0:sysutils/rubygem-bundler \
		rubygem-cgi>=0:www/rubygem-cgi \
		rubygem-commonmarker>=2.3.0:textproc/rubygem-commonmarker \
		rubygem-csv>=3.3.2:devel/rubygem-csv \
		rubygem-debug>=0:devel/rubygem-debug \
		rubygem-doorkeeper-rails72>=5.8.2:security/rubygem-doorkeeper-rails72 \
		rubygem-doorkeeper-i18n-rails72>=5.2:security/rubygem-doorkeeper-i18n-rails72 \
		rubygem-erb>0:devel/rubygem-erb \
		rubygem-globalid-rails72>0:databases/rubygem-globalid-rails72 \
		rubygem-html-pipeline>=2.13.2:textproc/rubygem-html-pipeline \
		rubygem-i18n>=1.14.1:devel/rubygem-i18n \
		rubygem-importmap-rails-rails72>=2.0:www/rubygem-importmap-rails-rails72 \
		rubygem-mail>=2.8.1:mail/rubygem-mail \
		rubygem-marcel>0:devel/rubygem-marcel \
		rubygem-mini_mime>=1.1.0:mail/rubygem-mini_mime \
		rubygem-mini_portile2>=2.8.2:devel/rubygem-mini_portile2 \
		rubygem-mocha>=2.0.1:devel/rubygem-mocha \
		rubygem-net-imap>=0.5.7:mail/rubygem-net-imap \
		rubygem-net-ldap>=0.19.0:net/rubygem-net-ldap \
		rubygem-net-pop>=0.1.2:mail/rubygem-net-pop \
		rubygem-net-smtp>=0.5.0:mail/rubygem-net-smtp \
		rubygem-nokogiri>=1.18.3:textproc/rubygem-nokogiri \
		rubygem-oauth2>2.0<3:net/rubygem-oauth2 \
		rubygem-propshaft-rails72>=1.1.0:www/rubygem-propshaft-rails72 \
		rubygem-rack>=3.1.3:www/rubygem-rack \
		rubygem-rails-dom-testing-rails72>=2.2<3:textproc/rubygem-rails-dom-testing-rails72 \
		rubygem-rails72>=7.2.3:www/rubygem-rails72 \
		rubygem-rbpdf>=1.21.4:print/rubygem-rbpdf \
		rubygem-requestjs-rails-rails72>=0.0.13:www/rubygem-requestjs-rails-rails72 \
		rubygem-request_store15>=1.5.1:devel/rubygem-request_store15 \
		rubygem-rest-client>0:www/rubygem-rest-client \
		rubygem-roadie-rails-rails72>=3.2.0:mail/rubygem-roadie-rails-rails72 \
		rubygem-rotp>=5.0.0:devel/rubygem-rotp \
		rubygem-rouge>=4.5.0:textproc/rubygem-rouge \
		rubygem-rqrcode>0:www/rubygem-rqrcode \
		rubygem-rubocop-performance>=0:devel/rubygem-rubocop-performance \
		rubygem-rubocop-rails>0:devel/rubygem-rubocop-rails \
		rubygem-rubocop>0<2:devel/rubygem-rubocop \
		rubygem-rubyzip>=2.4.0:archivers/rubygem-rubyzip \
		rubygem-sanitize>=6.0:textproc/rubygem-sanitize \
		rubygem-simplecov>0:devel/rubygem-simplecov \
		rubygem-stimulus-rails-rails72>=1.3:www/rubygem-stimulus-rails-rails72 \
		rubygem-svg_sprite>=0:graphics/rubygem-svg_sprite \
		rubygem-yard>=0:textproc/rubygem-yard

USES=		cpe ruby

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	RUBY_SUFFIX=${RUBY_SUFFIX}

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	PUMA MARKDOWN RMAGIC
OPTIONS_DEFAULT=TRILOGY MARKDOWN PUMA RMAGIC
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	TRILOGY MYSQL2 PGSQL SQLITE SQL
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=	yes
MARKDOWN_DESC=	Enable Markdown support
TRILOGY_DESC=	MySQL database support (via trilogy rubygem, preferred)
MYSQL2_DESC=	MySQL database support (via mysql2 rubygem)
PGSQL_DESC=	Postgres database support (via pg rubygem)
PUMA_DESC=	Use Puma WEB server
RMAGIC_DESC=	Enable Gantt charts support
SQLITE_DESC=	Sqlite3 database support (Not for production!)
SQL_DESC=	SQL Server requires manual (non-port) gem install
MARKDOWN_RUN_DEPENDS=	rubygem-redcarpet>=3.5.1:textproc/rubygem-redcarpet
TRILOGY_RUN_DEPENDS=	rubygem-trilogy>=2.9.0:databases/rubygem-trilogy \
			rubygem-with_advisory_lock61>0:devel/rubygem-with_advisory_lock61
MYSQL2_RUN_DEPENDS=	rubygem-mysql2>=0.5.0:databases/rubygem-mysql2 \
			rubygem-with_advisory_lock61>0:devel/rubygem-with_advisory_lock61
PGSQL_RUN_DEPENDS=	rubygem-pg>=1.5.3:databases/rubygem-pg
PUMA_RUN_DEPENDS=	rubygem-puma>=6.5.0:www/rubygem-puma \
			rubygem-rb-kqueue>=0.2:devel/rubygem-rb-kqueue
PUMA_SUB_LIST=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PUMA_VARS=		USE_RC_SUBR=redmine
RMAGIC_RUN_DEPENDS=	rubygem-mini_magick>=5.0.1:graphics/rubygem-mini_magick
SQLITE_RUN_DEPENDS=	rubygem-sqlite3>=2.5.0:databases/rubygem-sqlite3

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
	${MKDIR} ${STAGEDIR}${WWWDIR}/public/assets
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/pdf

	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${TOUCH} ${STAGEDIR}${WWWDIR}/Gemfile.lock

do-install-TRILOGY-on:
	${CP} ${FILESDIR}/trilogy.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-MYSQL2-on:
	${CP} ${FILESDIR}/mysql2.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-PGSQL-on:
	${CP} ${FILESDIR}/pg.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-SQLITE-on:
	${CP} ${FILESDIR}/sqlite3.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-SQL-on:
	${CP} ${FILESDIR}/sql.rb ${STAGEDIR}${WWWDIR}/bundler.d

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
