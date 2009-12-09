# New ports collection makefile for:	rt38
# Date created:							26 December 2008
# Whom:									Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$

# TODO:
# o etc/rt38 files permissions
# o GRANTS
# o Schema
# - Vhost Config
#   o install a sample into etc/apache22/Includes

PORTNAME=	rt
PORTVERSION=	3.8.6
CATEGORIES=	www
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/ \
		ftp://ftp.eu.uu.net/pub/unix/ticketing/rt/release/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	RT is an industrial-grade ticketing system written in Perl

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-noportdocs-Makefile.in
.endif

CONFLICTS=	rt-2* rt-3.0* rt-3.2* rt-3.4* rt-3.6*
LATEST_LINK=	rt38

OPTIONS=	MYSQL 		"Enable MySQL backend" 		on  \
		APACHE		"Enable ${APACHE_PORT} server"		on  \
		MODPERL		"Enable mod_perl support"	on \
		POSTGRESQL 	"Enable Postgresql backend"	off \
		ORACLE		"Enable Oracle backend"		off \
		SQLITE		"Enable SQLite backend" 	off \
		DEV 		"Configure for Developers"	off \
		STANDALONE	"Enable standalone server"	off \
		MODPERL2	"Enable mod_perl2 support"	off  \
		FASTCGI		"Enable FastCGI support" 	off \
		GRAPHVIZ	"Enable GraphViz charts"	on

.include "${.CURDIR}/Makefile.cpan"

BUILD_DEPENDS+=	${CORE_DEPS} \
		${CLI_DEPS} \
		${DASHBOARD_DEPS} \
		${GD_DEPS} \
		${GPG_DEPS} \
		${ICAL_DEPS} \
		${MAILGATE_DEPS} \
		${MASON_DEPS} \
		${SMTP_DEPS}

RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PERL5=	5.8.3+
USE_AUTOTOOLS=	autoconf:262

.include <bsd.port.pre.mk>

.if defined(WITH_DEV)
BUILD_DEPENDS+=	${DEV_DEPS}
RUN_DEPENDS+=	${DEV_DEPS}
.endif

.if defined(WITH_STANDALONE)
BUILD_DEPENDS+=	${STANDALONE_DEPS}
RUN_DEPENDS+=	${STANDALONE_DEPS}
.endif

.if defined(WITH_APACHE)
USE_APACHE=	1.3+
.endif

.if defined(WITH_FASTCGI)
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
.endif

.if defined(WITH_GRAPHVIZ)
BUILD_DEPENDS+=	${GRAPVIZ_DEPS}
RUN_DEPENDS+=	${GRAPVIZ_DEPS}
.endif

.if defined(WITH_MODPERL2)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/Request.pm:${PORTSDIR}/www/p5-libapreq2 \
	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp2
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/Request.pm:${PORTSDIR}/www/p5-libapreq2 \
	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp2
.endif

.if defined(WITH_MODPERL)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp1
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
	${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI-mp1
.endif

.if !defined(WITHOUT_MYSQL)
DB_TYPE=	mysql
USE_MYSQL=	yes
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.elif defined(WITH_POSTGRESQL)
DB_TYPE=	Pg
USE_PGSQL=	yes
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.elif defined (WITH_SQLITE)
DB_TYPE=	SQLite
USE_SQLITE=	yes
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
.elif defined (WITH_ORACLE)
DB_TYPE=	Oracle
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Oracle.pm:${PORTSDIR}/databases/p5-DBD-Oracle
.else
IGNORE=	you must choose a database backend
.endif

### Only 1 Backend
#.if (defined(WITH_MYSQL) && (defined(WITH_POSTGRESQL) || defined(WITH_SQLITE) || defined(WITH_ORACLE))) ||
#    (defined(WITH_POSTGRESQL) && (defined(WITH_MYSQL) || defined(WITH_SQLITE) || defined(WITH_ORACLE))) ||
#    (defined(WITH_SQLITE) && (defined(WITH_MYSQL) || defined(WITH_POSTGRELSQL) || defined(WITH_ORACLE))) ||
#    (defined(WITH_ORACLE) && (defined(WITH_MYSQL) || defined(WITH_POSTGRELSQL) || defined(WITH_SQLITE)))
#IGNORE=	Select exactly one of WITH_MYSQL, WITH_POSTGRESQL, WITH_SQLITE, WITH_ORACLE
#.endif

### MODPERL or MODPERL2
.if defined(WITH_MODPERL) && defined(WITH_MODPERL2)
IGNORE=	options WITH_MODPERL and WITH_MODPERL2 are mutually exclusive
.endif

RT_ETC_PATH?=	${LOCALBASE}/etc/${PORTNAME}38
RT_LAYOUT=	FreeBSD
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}38

DB_DBA_USER?=	root
DB_DBA_PASSWORD?=
DB_USER?=	rt_user
DB_PASSWORD?=	rt_pass
DB_HOST?=	localhost
DB_DATABASE?=	rt3

WEB_USER?=	${WWWOWN}
WEB_GROUP?=	${WWWGRP}
LIBS_GROUP?=	wheel

LATEST_LINK=	rt38
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

run-autotools::	run-autotools-autoconf

pre-fetch:
	@${ECHO} ""
	@${ECHO} "      DB_TYPE=type                    mysql, Oracle, Pg or SQLite (mysql)"
	@${ECHO} "      DB_HOST=hostname                The database host (localhost)"
	@${ECHO} "      DB_PORT=port                    The database port"
	@${ECHO} "      DB_DATABASE=dbname              The database name (rt3)"
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
	@${REINPLACE_CMD} -e 's!/bin:/usr/bin!/bin:/usr/bin:${LOCALBASE}/bin!' ${WRKSRC}/bin/webmux.pl.in
	@${REINPLACE_CMD} -e 's!/bin:/usr/bin!/bin:/usr/bin:${LOCALBASE}/bin!' ${WRKSRC}/lib/RT/Interface/CLI.pm && \
	    ${RM} ${WRKSRC}/lib/RT/Interface/CLI.pm.bak

pre-install:
	@${RM} -f ${WRKSRC}/lib/RT.pm.in
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@[ -f ${RT_ETC_PATH}/RT_SiteConfig.pm ] || \
		${CP} -p ${RT_ETC_PATH}/RT_SiteConfig.pm-dist ${RT_ETC_PATH}/RT_SiteConfig.pm
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
