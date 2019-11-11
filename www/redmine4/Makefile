# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	redmine
PORTVERSION=	4.0.5
CATEGORIES=	www
MASTER_SITES=	https://www.redmine.org/releases/
PKGNAMESUFFIX=	4

MAINTAINER=	mikael.urankar@gmail.com
COMMENT=	Flexible project management web application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	rubygem-bundler>=1.5.0:sysutils/rubygem-bundler \
		rubygem-rails52>=5.2.3:www/rubygem-rails52 \
		rubygem-rouge>=3.12.0:textproc/rubygem-rouge \
		rubygem-request_store>=1.0.5:devel/rubygem-request_store \
		rubygem-mini_mime>=1.0.1:mail/rubygem-mini_mime \
		rubygem-actionpack-xml_parser52>=0:textproc/rubygem-actionpack-xml_parser52 \
		rubygem-roadie-rails52>=1.3.0:mail/rubygem-roadie-rails52 \
		rubygem-mimemagic>=0:misc/rubygem-mimemagic \
		rubygem-mail>=2.7.1:mail/rubygem-mail \
		rubygem-nokogiri>=1.10.0:textproc/rubygem-nokogiri \
		rubygem-i18n>=0.7:devel/rubygem-i18n \
		rubygem-sprockets3>=3.7.2:devel/rubygem-sprockets3 \
		rubygem-rbpdf>=1.19.6:print/rubygem-rbpdf \
		rubygem-net-ldap>=0.16:net/rubygem-net-ldap \
		rubygem-ruby-openid>=2.9.2:net/rubygem-ruby-openid \
		rubygem-rack-openid>=0:www/rubygem-rack-openid \
		rubygem-rake>=0:devel/rubygem-rake

USES=		cpe
USE_RUBY=	yes

CONFLICTS_INSTALL=	redmine

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

MYSQL_RUN_DEPENDS=	rubygem-mysql2>=0.5.0:databases/rubygem-mysql2
POSTGRESQL_RUN_DEPENDS=	rubygem-pg>=1.1.4:databases/rubygem-pg
MARKDOWN_RUN_DEPENDS=	rubygem-redcarpet>=3.4.0:textproc/rubygem-redcarpet
RMAGIC_RUN_DEPENDS=	rubygem-rmagick>=2.16.0:graphics/rubygem-rmagick
THIN_RUN_DEPENDS=	rubygem-thin>=1.6.2:www/rubygem-thin
THIN_SUB_LIST=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
THIN_VARS=		USE_RC_SUBR=redmine

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

.include <bsd.port.mk>
