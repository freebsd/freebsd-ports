PORTNAME=	redmine
PORTVERSION=	5.0.8
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://www.redmine.org/releases/
PKGNAMESUFFIX=	50

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Flexible project management web application
WWW=		https://www.redmine.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

DEPRECATED=		Requires ruby31
EXPIRATION_DATE=	2025-03-31

RUN_DEPENDS=	rubygem-bundler>=1.12.0:sysutils/rubygem-bundler \
		rubygem-globalid-rails61>0:databases/rubygem-globalid-rails61 \
		rubygem-rails61>=6.1:www/rubygem-rails61 \
		rubygem-rouge3>=3.28.0:textproc/rubygem-rouge3 \
		rubygem-request_store15>=1.5.0:devel/rubygem-request_store15 \
		rubygem-mini_mime>=1.0.1:mail/rubygem-mini_mime \
		rubygem-actionpack-xml_parser-rails61>=0:textproc/rubygem-actionpack-xml_parser-rails61 \
		rubygem-roadie-rails-rails61>=3.0.0:mail/rubygem-roadie-rails-rails61 \
		rubygem-marcel>0:devel/rubygem-marcel \
		rubygem-mail>=2.7.1:mail/rubygem-mail \
		rubygem-csv>=3.2.0:devel/rubygem-csv \
		rubygem-nokogiri>=1.13.8:textproc/rubygem-nokogiri \
		rubygem-i18n>=1.10.0:devel/rubygem-i18n \
		rubygem-rbpdf>=1.20.0:print/rubygem-rbpdf \
		rubygem-addressable>0:www/rubygem-addressable \
		rubygem-rubyzip>0:archivers/rubygem-rubyzip \
		rubygem-net-smtp>0:mail/rubygem-net-smtp \
		rubygem-net-imap>0:mail/rubygem-net-imap \
		rubygem-net-pop>0:mail/rubygem-net-pop \
		rubygem-psych>0:textproc/rubygem-psych \
		rubygem-net-ldap>=0.17.0:net/rubygem-net-ldap \
		rubygem-rotp>=5.0.0:devel/rubygem-rotp \
		rubygem-rqrcode>0:www/rubygem-rqrcode \
		rubygem-erb>0:devel/rubygem-erb \
		rubygem-mini_portile2>=2.8.2<2.9:devel/rubygem-mini_portile2

# Per https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=264638#c9
# to be removed if https://www.redmine.org/issues/37394 is fixed
RUN_DEPENDS+=	rubygem-redcarpet>=3.5.1:textproc/rubygem-redcarpet \
		rubygem-html-pipeline>=2.13.2:textproc/rubygem-html-pipeline \
		rubygem-commonmarker0>=0.23.6:textproc/rubygem-commonmarker0 \
		rubygem-sanitize>=6.0:textproc/rubygem-sanitize \
		rubygem-deckar01-task_list>=2.3.1:www/rubygem-deckar01-task_list

USES=		cpe ruby
BROKEN_RUBY32=	yes

CONFLICTS_INSTALL=	redmine42

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	RUBY_SUFFIX=${RUBY_SUFFIX}

OPTIONS_DEFINE=	MYSQL POSTGRESQL MARKDOWN RMAGIC THIN
OPTIONS_DEFAULT=MYSQL MARKDOWN RMAGIC THIN
OPTIONS_SUB=	yes
POSTGRESQL_DESC=Enable PostgreSQL support
MARKDOWN_DESC=	Enable Markdown support
RMAGIC_DESC=	Enable Gantt charts support
THIN_DESC=	Use Thin WEB server
MYSQL_DESC=	MySQL database support (via mysql2 rubygem)
NO_OPTIONS_SORT=	yes
MYSQL_RUN_DEPENDS=	rubygem-mysql2>=0.5.0:databases/rubygem-mysql2
POSTGRESQL_RUN_DEPENDS=	rubygem-pg>=1.2.2:databases/rubygem-pg
MARKDOWN_RUN_DEPENDS=	rubygem-redcarpet>=3.5.1:textproc/rubygem-redcarpet
RMAGIC_RUN_DEPENDS=	rubygem-mini_magick4>=4.11.0:graphics/rubygem-mini_magick4
THIN_RUN_DEPENDS=	rubygem-thin>=1.6.2:www/rubygem-thin
THIN_SUB_LIST=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
THIN_VARS=		USE_RC_SUBR=redmine

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

do-install-THIN-on:
	${CP} ${FILESDIR}/thin.rb ${STAGEDIR}${WWWDIR}/bundler.d

post-install:
	(cd ${STAGEDIR}${WWWDIR} && ${RM} Gemfile.lock && bundle install --local)
	${RM} ${STAGEDIR}${WWWDIR}/package.json \
		${STAGEDIR}${WWWDIR}/yarn.lock

.include <bsd.port.mk>
