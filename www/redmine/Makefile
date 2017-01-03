# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	redmine
PORTVERSION=	3.2.3
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible project management web application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	rubygem-bundler>=1.5.0:sysutils/rubygem-bundler \
		rubygem-rails4>=4.2.5:www/rubygem-rails4 \
		rubygem-jquery-rails4>=3.1.4:www/rubygem-jquery-rails4 \
		rubygem-coderay>=1.1.0:textproc/rubygem-coderay \
		rubygem-builder>=3.0.4:devel/rubygem-builder \
		rubygem-request_store>=1.0.5:devel/rubygem-request_store \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-mimemagic>=0:misc/rubygem-mimemagic \
		rubygem-protected_attributes>=0:devel/rubygem-protected_attributes \
		rubygem-actionpack-action_caching>=0:devel/rubygem-actionpack-action_caching \
		rubygem-actionpack-xml_parser>=0:textproc/rubygem-actionpack-xml_parser \
		rubygem-roadie-rails>=0:mail/rubygem-roadie-rails \
		rubygem-rbpdf>=1.19.0:print/rubygem-rbpdf \
		rubygem-rake>=0:devel/rubygem-rake \
		rubygem-ruby-openid>=2.3.0:net/rubygem-ruby-openid \
		rubygem-rack-openid>=0:www/rubygem-rack-openid \
		rubygem-net-ldap>=0.12.0:net/rubygem-net-ldap

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USES=		cpe

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	RUBY_NAME=${RUBY_NAME}

OPTIONS_DEFINE=	MYSQL POSTGRESQL LDAP MARKDOWN RMAGIC
OPTIONS_DEFAULT=MYSQL MARKDOWN RMAGIC THIN
OPTIONS_SINGLE=	WWWSERVER
OPTIONS_SINGLE_WWWSERVER=	THIN PASSENGER
OPTIONS_SUB=	yes
POSTGRESQL_DESC=	Enable PostgreSQL support
LDAP_DESC=	Enable LDAP Authentification
MARKDOWN_DESC=	Enable Markdown support
RMAGIC_DESC=	Enable Gantt charts support
THIN_DESC=	Use Thin WEB server
PASSENGER_DESC=	Use Apache/Nginx WEB server
MYSQL_DESC=	MySQL database support (via mysql2 rubygem)
NO_OPTIONS_SORT=	yes

MYSQL_RUN_DEPENDS=	rubygem-mysql2>=0.4.5:databases/rubygem-mysql2
PASSENGER_RUN_DEPENDS=	passenger-config:www/rubygem-passenger
POSTGRESQL_RUN_DEPENDS=	rubygem-pg>=0.18.1:databases/rubygem-pg
MARKDOWN_RUN_DEPENDS=	rubygem-redcarpet>=3.3.2:textproc/rubygem-redcarpet
RMAGIC_RUN_DEPENDS=	rubygem-rmagick>=2.14.0:graphics/rubygem-rmagick
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
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${TOUCH} ${STAGEDIR}${WWWDIR}/Gemfile.lock

do-install-MYSQL-on:
	${CP} ${FILESDIR}/mysql.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-POSTGRESQL-on:
	${CP} ${FILESDIR}/pg.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-LDAP-on:
	${CP} ${FILESDIR}/ldap.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-MARKDOWN-on:
	${CP} ${FILESDIR}/markdown.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-RMAGIC-on:
	${CP} ${FILESDIR}/rmagic.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-THIN-on:
	${CP} ${FILESDIR}/thin.rb ${STAGEDIR}${WWWDIR}/bundler.d

.include <bsd.port.mk>
