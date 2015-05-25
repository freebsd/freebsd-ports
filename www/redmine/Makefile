# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	redmine
PORTVERSION=	2.6.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.redmine.org/releases/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible project management web application

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-rubytree>=0:${PORTSDIR}/devel/rubygem-rubytree \
		rubygem-i18n>=0.7.0:${PORTSDIR}/devel/rubygem-i18n \
		rubygem-rake>=0:${PORTSDIR}/devel/rubygem-rake \
		rubygem-bundler>=0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-rails>=3.2.16:${PORTSDIR}/www/rubygem-rails \
		rubygem-rack-openid>=0:${PORTSDIR}/www/rubygem-rack-openid \
		rubygem-coderay>=1.0.9:${PORTSDIR}/textproc/rubygem-coderay \
		rubygem-fastercsv>=1.5.0:${PORTSDIR}/devel/rubygem-fastercsv \
		rubygem-builder>=3.0.0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-redcarpet>0:${PORTSDIR}/textproc/rubygem-redcarpet \
		rubygem-net-ldap>=0.3.1:${PORTSDIR}/net/rubygem-net-ldap \
		rubygem-rbpdf>=0:${PORTSDIR}/print/rubygem-rbpdf \
		rubygem-request_store>=1.1.0:${PORTSDIR}/devel/rubygem-request_store

USES=		cpe
USE_RUBY=	yes
#USE_RAKE=	yes
NO_BUILD=	yes
SUB_LIST+=	RUBY_NAME=${RUBY_NAME}
USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	MYSQL MYSQL2 POSTGRESQL RMAGIC WWWSERVER
OPTIONS_DEFAULT=MYSQL2 RMAGIC WWWSERVER THIN
OPTIONS_SINGLE=	WWWSERVER
OPTIONS_SINGLE_WWWSERVER=	THIN PASSENGER
POSTGRESQL_DESC=Enable PostgreSQL support
RMAGIC_DESC=	Enable Gantt charts support
THIN_DESC=	Use Thin WEB server
PASSENGER_DESC=	Use Apache/Nginx WEB server
MYSQL2_DESC=	MySQL database support (via mysql2 rubygem)
NO_OPTIONS_SORT=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	rubygem-mysql>=2.8.1:${PORTSDIR}/databases/rubygem-mysql
.endif

.if ${PORT_OPTIONS:MMYSQL2}
RUN_DEPENDS+=	rubygem-mysql2>=0:${PORTSDIR}/databases/rubygem-mysql2
.endif

.if ${PORT_OPTIONS:MPOSTGRESQL}
RUN_DEPENDS+=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
.endif

.if ${PORT_OPTIONS:MRMAGIC}
RUN_DEPENDS+=	rubygem-rmagick>=2.0.0:${PORTSDIR}/graphics/rubygem-rmagick
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Gemfile
.endif

.if ${PORT_OPTIONS:MWWWSERVER}
.if ${PORT_OPTIONS:MTHIN}
RUN_DEPENDS+=	thin:${PORTSDIR}/www/rubygem-thin
USE_RC_SUBR=	redmine
SUB_LIST+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-thin-Gemfile
.endif

.if ${PORT_OPTIONS:MPASSENGER}
RUN_DEPENDS+=	passenger-config:${PORTSDIR}/www/rubygem-passenger
.endif
.endif

post-extract:
	${MV} ${WRKSRC}/config/settings.yml ${WRKSRC}/config/settings.yml-dist

pre-install:
	${MKDIR} ${WRKSRC}/public/plugin_assets

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/tmp/pids
	cd ${WRKSRC} && \
	${COPYTREE_SHARE} "*" ${STAGEDIR}${WWWDIR} "! ( -name *\.orig -o -name *\.bak )"
	${FIND} ${WRKSRC}/script -type f -print | ${XARGS} ${CHMOD} 755

post-install:
	${TOUCH} ${STAGEDIR}${WWWDIR}/Gemfile.lock
	if ! [ -r ${STAGEDIR}${WWWDIR}/config/settings.yml ]; then		\
		${INSTALL_DATA} ${STAGEDIR}${WWWDIR}/config/settings.yml-dist	\
			${STAGEDIR}${WWWDIR}/config/settings.yml;		\
	fi

.include <bsd.port.mk>
