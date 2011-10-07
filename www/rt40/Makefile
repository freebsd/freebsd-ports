# New ports collection makefile for:	rt38
# Date created:							26 December 2008
# Whom:									Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$

# TODO:
# o GRANTS
# o Schema
# - Vhost Config
#   o install a sample into etc/apache22/Includes

PORTNAME=	rt
PORTVERSION=	4.0.2
CATEGORIES=	www
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/ \
		ftp://ftp.eu.uu.net/pub/unix/ticketing/rt/release/

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT is an industrial-grade ticketing system written in Perl

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-noportdocs-Makefile.in
.endif

CONFLICTS=	rt-3.6* rt-3.8*
LATEST_LINK=	rt40

# See doc/web_deployment.pod for info on the choices of webserver /
# webapp combinations.  Note: apache-1.3.x is unsupported and untested
# upstream; apache-2.0+ is strongly recommended.  For deployment with
# nginx, use the SPAWN_FCGI method.  A standalone PSGI based webserver
# is always available, but this is really only suitable for
# development usage.
#
# See doc/full_text_indexing.pod if you need to set up full text
# indexes on your ticket database.  PostgreSQL or Oracle are
# recommended in this case: the MYSQL / SphinxSearch combination
# mentioned in the docs is currently unsupported in the ports, but see
# http://www.infracaninophile.co.uk/articles/sphinxse.html

OPTIONS=	AP_MODPERL	"Deploy with ${APACHE_PORT} and mod_perl"	on \
		AP_MODFASTCGI	"Deploy with ${APACHE_PORT} and mod_fastcgi"	off \
		LIGHTTPD	"Deploy with lighttpd and mod_fastcgi"	off \
		SPAWN_FCGI	"Deploy with spawn_fcgi"		off \
		MYSQL 		"Enable MySQL backend" 			on  \
		POSTGRESQL	"Enable PosgreSQL backend"		off \
		ORACLE		"Enable Oracle backend"			off \
		SQLITE		"Enable SQLite backend (dev only)"	off \
		DEV 		"Configure for Developers"		off \
		GPG		"Enable GnuPG support"			on \
		GRAPHVIZ	"Enable GraphViz charts"		off \
		GD		"Enable GD Graphs and Charts"		on

GROUPS?=	rt

BUILD_DEPENDS+=	${LOCALBASE}/bin/jsmin:${PORTSDIR}/devel/jsmin

.include "${.CURDIR}/Makefile.cpan"

BUILD_DEPENDS+=	${CORE_DEPS}       \
		${MASON_DEPS}      \
		${PSGI_DEPS}       \
		${MAILGATE_DEPS}   \
		${CLI_DEPS}        \
		${ICAL_DEPS}       \
		${SMTP_DEPS}       \
		${DASHBOARDS_DEPS} \
		${USERLOGO_DEPS}

RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PERL5=	5.8.3+
USE_AUTOTOOLS=	autoconf

.include <bsd.port.pre.mk>

.if defined(WITH_AP_MODPERL) || defined(WITH_AP_MODFASTCGI)
USE_APACHE=	1.3+
.endif

.if defined(WITH_AP_MODPERL)

.if defined(WITH_AP_MODFASTCGI) || defined(WITH_LIGHTTPD) || \
	defined(WITH_SPAWN_FCGI)
IGNORE=	please select at most one of AP_MODPERL, AP_MODFASTCGI, LIGHTTPD or SPAWN_FCGI
.endif

WITH_APACHE=	yes

.include "${PORTSDIR}/Mk/bsd.apache.mk"

.if ${APACHE_VERSION} == 13
BUILD_DEPENDS+=	${MODPERL1_DEPS}
RUN_DEPENDS+=	${MODPERL1_DEPS}
.else
BUILD_DEPENDS+=	${MODPERL2_DEPS}
RUN_DEPENDS+=	${MODPERL2_DEPS}
.endif

.elif defined(WITH_AP_MODFASTCGI)

.if defined(WITH_LIGHTTPD) || defined(WITH_SPAWN_FCGI)
IGNORE=	please select at most one of AP_MODPERL, AP_MODFASTCGI, LIGHTTPD or SPAWN_FCGI
.endif

WITH_APACHE=	yes

BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi \
		${FASTCGI_DEPS}

.elif defined(WITH_LIGHTTPD)

.if defined(WITH_SPAWN_FCGI)
IGNORE=	please select at most one of AP_MODPERL, AP_MODFASTCGI, LIGHTTPD or SPAWN_FCGI
.endif

BUILD_DEPENDS+=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd
RUN_DEPENDS+=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd

.elif defined(WITH_SPAWN_FCGI)

BUILD_DEPENDS+=	${LOCALBASE}/bin/spawn-fcgi:${PORTSDIR}/www/spawn-fcgi
RUN_DEPENDS+=	${LOCALBASE}/bin/spawn-fcgi:${PORTSDIR}/www/spawn-fcgi

.endif

.if defined(WITH_MYSQL)

.if defined(WITH_POSTGRESQL) || defined(WITH_ORACLE) || \
	defined(WITH_SQLITE)
IGNORE=	please select only one of MYSQL, POSTGRESQL, ORACLE or SQLITE
.endif

DB_TYPE=	mysql
USE_MYSQL=	yes
BUILD_DEPENDS+=	${MYSQL_DEPS}
RUN_DEPENDS+=	${MYSQL_DEPS}

.elif defined(WITH_POSTGRESQL)

.if defined(WITH_ORACLE) || defined(WITH_SQLITE)
IGNORE=	please select only one of MYSQL, POSTGRESQL, ORACLE or SQLITE
.endif

DB_TYPE=	Pg
USE_PGSQL=	yes
BUILD_DEPENDS+=	${POSTGRESQL_DEPS}
RUN_DEPENDS+=	${POSTGRESQL_DEPS}

.elif defined(WITH_ORACLE)

.if defined(WITH_SQLITE)
IGNORE=	please select only one of MYSQL, POSTGRESQL, ORACLE or SQLITE
.endif

DB_TYPE=	Oracle
BUILD_DEPENDS+=	${ORACLE_DEPS}
RUN_DEPENDS+=	${ORACLE_DEPS}

.elif defined(WITH_SQLITE)

DB_TYPE=	SQLite
USE_SQLITE=	yes
BUILD_DEPENDS+=	${SQLITE_DEPS}
RUN_DEPENDS+=	${SQLITE_DEPS}

.else

IGNORE=	please select one of MYSQL, POSTGRESQL, ORACLE or SQLITE

.endif

.if defined(WITH_DEV)
BUILD_DEPENDS+=	${DEV_DEPS}
RUN_DEPENDS+=	${DEV_DEPS}
CONFIGURE_ARGS+=	"--enable-developer-mode"
.endif

.if defined(WITH_GRAPHVIZ)
BUILD_DEPENDS+=	${GRAPHVIZ_DEPS}
RUN_DEPENDS+=	${GRAPHVIZ_DEPS}
CONFIGURE_ARGS+=	"--enable-graphviz"
.endif

.if defined(WITH_GPG)
BUILD_DEPENDS+=	${GPG_DEPS}
RUN_DEPENDS+=	${GPG_DEPS}
CONFIGURE_ARGS+=	"--enable-gpg"
.endif

.if defined(WITH_GD)
BUILD_DEPENDS+=	${GD_DEPS}
RUN_DEPENDS+=	${GD_DEPS}
configure_args+=	"--enable-gd"
.endif

RT_ETC_PATH?=	${PREFIX}/etc/${PORTNAME}40
RT_LAYOUT=	FreeBSD
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}40

DB_DBA_USER?=	root
DB_DBA_PASSWORD?=
DB_USER?=	rt_user
DB_PASSWORD?=	rt_pass
DB_HOST?=	localhost
DB_DATABASE?=	rt4

WEB_USER?=	${WWWOWN}
WEB_GROUP?=	${WWWGRP}
LIBS_GROUP?=	wheel

HAS_CONFIGURE=	yes
NO_BUILD=	yes

CONFIGURE_ARGS=	--enable-layout=${RT_LAYOUT} \
	--with-web-user=${WEB_USER} \
	--with-web-group=${WEB_GROUP} \
	--with-libs-group=${LIBS_GROUP} \
	--with-db-host=${DB_HOST} \
	--with-db-port=${DB_PORT} \
	--with-db-type=${DB_TYPE} \
	--with-db-rt-user=${DB_USER} \
	--with-db-rt-pass=${DB_PASSWORD} \
	--with-db-database=${DB_DATABASE} \
	--with-db-dba=${DB_DBA_USER}

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	RT_ETC_PATH=${RT_ETC_PATH}

run-autotools:	run-autotools-autoconf

pre-fetch:
	@${ECHO} ""
	@${ECHO} "      DB_TYPE=type                    mysql, Oracle, Pg or SQLite (mysql)"
	@${ECHO} "      DB_HOST=hostname                The database host (localhost)"
	@${ECHO} "      DB_PORT=port                    The database port"
	@${ECHO} "      DB_DATABASE=dbname              The database name (rt4)"
	@${ECHO} ""
	@${ECHO} "      DB_DBA_USER=username            Name of database administrator (root)"
	@${ECHO} "      DB_DBA_PASSWORD=password        Password of database administrator"
	@${ECHO} "      DB_USER=username                Name of database user for RT (rt_user)"
	@${ECHO} "      DB_PASSWORD=password            Name of database password for RT (rt_pass)"
.if defined(WITH_SQLITE)
	@${ECHO} ""
	@${ECHO} "SQLITE is not recommended for production use"
.endif

post-patch:
	@${RM} -f ${WRKSRC}/lib/RT.pm.in.orig
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!g' ${WRKSRC}/config.layout
	@${REINPLACE_CMD} -e 's!%%SITE_PERL%%!${SITE_PERL}!g' ${WRKSRC}/config.layout
	@${REINPLACE_CMD} -e 's!/path/to/your/etc!${RT_ETC_PATH}!g' ${WRKSRC}/etc/RT_SiteConfig.pm
	@${REINPLACE_CMD} -e 's!/bin:/usr/bin!/bin:/usr/bin:${LOCALBASE}/bin!' ${WRKSRC}/lib/RT/Interface/CLI.pm && \
	    ${RM} ${WRKSRC}/lib/RT/Interface/CLI.pm.bak

pre-install:
	@${RM} -f ${WRKSRC}/lib/RT.pm.in

post-install:
	@[ -f ${RT_ETC_PATH}/RT_SiteConfig.pm ] || \
		${CP} -p ${RT_ETC_PATH}/RT_SiteConfig.pm-dist ${RT_ETC_PATH}/RT_SiteConfig.pm
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
