# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	redmine
PORTVERSION=	2.6.9
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible project management web application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/doc/COPYING

RUN_DEPENDS=	rubygem-builder>=3.0.0:devel/rubygem-builder \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-coderay>=1.0.9:textproc/rubygem-coderay \
		rubygem-i18n>=0.7.0:devel/rubygem-i18n \
		rubygem-jquery-rails>=3.1.4:www/rubygem-jquery-rails \
		rubygem-mime-types>=0:misc/rubygem-mime-types \
		rubygem-net-ldap>=0.3.1:net/rubygem-net-ldap \
		rubygem-rack-openid>=0:www/rubygem-rack-openid \
		rubygem-ruby-openid>=2.3.0:net/rubygem-ruby-openid \
		rubygem-rails>=3.2.22:www/rubygem-rails \
		rubygem-rake>=0:devel/rubygem-rake \
		rubygem-rbpdf>=0:print/rubygem-rbpdf \
		rubygem-redcarpet>=3.3.2:textproc/rubygem-redcarpet \
		rubygem-request_store>=1.1.0:devel/rubygem-request_store \
		rubygem-rubytree>=0:devel/rubygem-rubytree

NO_ARCH=	yes
NO_BUILD=	yes
USE_RUBY=	yes
USES=		cpe

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_LIST=	RUBY_NAME=${RUBY_NAME}

OPTIONS_DEFINE=	MYSQL MYSQL2 POSTGRESQL RMAGIC
OPTIONS_DEFAULT=MYSQL2 RMAGIC THIN
OPTIONS_SINGLE=	WWWSERVER
OPTIONS_SINGLE_WWWSERVER=	THIN PASSENGER
OPTIONS_SUB=	yes
POSTGRESQL_DESC=Enable PostgreSQL support
RMAGIC_DESC=	Enable Gantt charts support
THIN_DESC=	Use Thin WEB server
PASSENGER_DESC=	Use Apache/Nginx WEB server
MYSQL2_DESC=	MySQL database support (via mysql2 rubygem)
NO_OPTIONS_SORT=yes

MYSQL_RUN_DEPENDS=	rubygem-mysql>=2.8.1:databases/rubygem-mysql
MYSQL2_RUN_DEPENDS=	rubygem-mysql2>=0:databases/rubygem-mysql2
PASSENGER_RUN_DEPENDS=	passenger-config:www/rubygem-passenger
POSTGRESQL_RUN_DEPENDS=	rubygem-pg>=0:databases/rubygem-pg
RMAGIC_RUN_DEPENDS=	rubygem-rmagick>=2.13.4:graphics/rubygem-rmagick
THIN_RUN_DEPENDS=	thin:www/rubygem-thin
THIN_SUB_LIST=		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
THIN_VARS=		USE_RC_SUBR=redmine

post-extract:
	@${RM} ${WRKSRC}/.hgignore ${WRKSRC}/.travis.yml
	@${MV} ${WRKSRC}/config/settings.yml ${WRKSRC}/config/settings.yml.sample

post-patch:
	@${FIND} ${WRKSRC} -name '*.bak' -o -name '*.orig' -delete

pre-install:
	${MKDIR} ${WRKSRC}/public/plugin_assets

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/pids
	${MKDIR} ${STAGEDIR}${WWWDIR}/bundler.d
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

do-install-RMAGIC-on:
	${CP} ${FILESDIR}/rmagic.rb ${STAGEDIR}${WWWDIR}/bundler.d

do-install-THIN-on:
	${CP} ${FILESDIR}/thin.rb ${STAGEDIR}${WWWDIR}/bundler.d

post-install:
	${TOUCH} ${STAGEDIR}${WWWDIR}/Gemfile.lock

.include <bsd.port.mk>
