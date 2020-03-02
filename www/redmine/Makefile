# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	redmine
PORTVERSION=	3.4.11
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://www.redmine.org/releases/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible project management web application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

DEPRECATED=	EOLed upstream
# Remove the port before 2020Q3
EXPIRATION_DATE=	2020-06-25

RUN_DEPENDS=	rubygem-bundler>=1.5.0:sysutils/rubygem-bundler \
		rubygem-rails4>=4.2.11.1:www/rubygem-rails4 \
		rubygem-jquery-rails>=3.1.4:www/rubygem-jquery-rails \
		rubygem-coderay>=1.1.1:textproc/rubygem-coderay \
		rubygem-request_store>=1.0.5:devel/rubygem-request_store \
		rubygem-mime-types>=3.0:misc/rubygem-mime-types \
		rubygem-protected_attributes>=0:devel/rubygem-protected_attributes \
		rubygem-actionpack-xml_parser1-rails4>=0:textproc/rubygem-actionpack-xml_parser1-rails4 \
		rubygem-roadie3>=3.2.1<4:mail/rubygem-roadie3 \
		rubygem-roadie-rails-rails4>=1.1.1:mail/rubygem-roadie-rails-rails4 \
		rubygem-mimemagic>=0:misc/rubygem-mimemagic \
		rubygem-mail>=2.6.4:mail/rubygem-mail \
		rubygem-nokogiri18>=1.8.1:textproc/rubygem-nokogiri18 \
		rubygem-i18n>=0.7:devel/rubygem-i18n \
		rubygem-rails-html-sanitizer>=1.0.3:textproc/rubygem-rails-html-sanitizer \
		rubygem-rbpdf>=1.19.6:print/rubygem-rbpdf \
		rubygem-net-ldap>=0.12:net/rubygem-net-ldap \
		rubygem-ruby-openid>=2.3:net/rubygem-ruby-openid \
		rubygem-rack-openid>=0:www/rubygem-rack-openid \
		rubygem-rake>=0:devel/rubygem-rake

USES=		cpe
USE_RUBY=	yes

CONFLICTS_INSTALL=	redmine4

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	RUBY_NAME=${RUBY_NAME}

OPTIONS_DEFINE=	MYSQL POSTGRESQL MARKDOWN RMAGIC THIN
OPTIONS_DEFAULT=MYSQL MARKDOWN RMAGIC THIN
OPTIONS_SUB=	yes
POSTGRESQL_DESC=Enable PostgreSQL support
MARKDOWN_DESC=	Enable Markdown support
RMAGIC_DESC=	Enable Gantt charts support
THIN_DESC=	Use Thin WEB server
MYSQL_DESC=	MySQL database support (via mysql2 rubygem)
NO_OPTIONS_SORT=	yes

MYSQL_RUN_DEPENDS=	rubygem-mysql204>=0.4.6<0.5.0:databases/rubygem-mysql204
POSTGRESQL_RUN_DEPENDS=	rubygem-pg018>=0.18.1:databases/rubygem-pg018
MARKDOWN_RUN_DEPENDS=	rubygem-redcarpet>=3.4.0:textproc/rubygem-redcarpet
RMAGIC_RUN_DEPENDS=	rubygem-rmagick>=2.16.0:graphics/rubygem-rmagick
THIN_RUN_DEPENDS=	rubygem-thin>=1.6.2:www/rubygem-thin
THIN_SUB_LIST=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
THIN_VARS=		USE_RC_SUBR=redmine

post-extract:
	@${RM} ${WRKSRC}/.hgignore ${WRKSRC}/.travis.yml
	@${MV} ${WRKSRC}/config/settings.yml ${WRKSRC}/config/settings.yml.sample
	@${MV} ${WRKSRC}/config/database.yml.example ${WRKSRC}/config/database.yml.sample
	@${TOUCH} ${WRKSRC}/log/development.log

post-patch:
	@${FIND} ${WRKSRC} -name '*.bak' -delete

pre-install:
	${MKDIR} ${WRKSRC}/public/plugin_assets

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/pids
	${MKDIR} ${STAGEDIR}${WWWDIR}/bundler.d
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/pdf
	${TOUCH} ${STAGEDIR}${WWWDIR}/tmp/pdf/empty
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/test
	${TOUCH} ${STAGEDIR}${WWWDIR}/tmp/test/empty
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/thumbnails
	${TOUCH} ${STAGEDIR}${WWWDIR}/tmp/thumbnails/empty
	${MKDIR} ${STAGEDIR}${WWWDIR}/log
	${TOUCH} ${STAGEDIR}${WWWDIR}/log/development.log
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${TOUCH} ${STAGEDIR}${WWWDIR}/Gemfile.lock

do-install-MYSQL-on:
	${CP} ${FILESDIR}/mysql.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-POSTGRESQL-on:
	${CP} ${FILESDIR}/pg.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-MARKDOWN-on:
	${CP} ${FILESDIR}/markdown.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-RMAGIC-on:
	${CP} ${FILESDIR}/rmagic.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-THIN-on:
	${CP} ${FILESDIR}/thin.rb ${STAGEDIR}${WWWDIR}/bundler.d

post-install:
	(cd ${STAGEDIR}${WWWDIR} && ${RM} Gemfile.lock && bundle install --local)

.include <bsd.port.mk>
