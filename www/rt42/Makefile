# $FreeBSD$

PORTNAME=	rt
DISTVERSION=	4.2.1
CATEGORIES=	www
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/
PKGNAMESUFFIX=	42

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	RT is an industrial-grade ticketing system written in Perl

CONFLICTS=	rt-3.8* rt-4.0* brlcad-[0-9]*
NEED_ROOT=	yes

# See doc/web_deployment.pod for info on the choices of webserver /
# webapp combinations.  Note: if using apache, apache-2.2+ is
# recommended.  For deployment with nginx, use the SPAWN_FCGI method
# or the builtin webserver with a FCGI handler.
#
# The builtin standalone PSGI based webserver is always available, no
# mater what choice of web deployment platform, or none, that you
# make.  Best Practical state that this is really only suitable for
# development usage, although I have heard reports of people using it
# successfully for medium sized deployments.  If you only want the
# builtin webserver, simply deselect all of the web options.
#
# See doc/full_text_indexing.pod if you need to set up full text
# indexes on your ticket database.  PostgreSQL or Oracle are
# recommended in this case: the MYSQL / SphinxSearch combination
# mentioned in the docs is currently unsupported in the ports, but see
# http://www.infracaninophile.co.uk/articles/sphinxse.html

OPTIONS_DEFINE=		DEV GD GPG GRAPHVIZ SMIME
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL ORACLE PGSQL SQLITE
OPTIONS_RADIO=		WEB
OPTIONS_RADIO_WEB=	AP_MODFASTCGI AP_MODPERL LIGHTTPD SPAWN_FCGI

OPTIONS_DEFAULT=	AP_MODPERL GD GPG MYSQL

AP_MODFASTCGI_DESC=	Deploy with apache and mod_fastcgi
AP_MODPERL_DESC=	Deploy with apache and mod_perl
DEV_DESC=		Configure for Developers
GD_DESC=		Enable GD Graphs and Charts
GPG_DESC=		Enable GnuPG support
SMIME_DESC=		Enable Secure MIME support
LIGHTTPD_DESC=		Deploy with lighttpd and mod_fastcgi
SPAWN_FCGI_DESC=	Deploy with spawn_fcgi

USERS?=		www
GROUPS?=	rt www

BUILD_DEPENDS+=	${LOCALBASE}/bin/jsmin:${PORTSDIR}/devel/jsmin

.include "${.CURDIR}/Makefile.cpan"

BUILD_DEPENDS+=	${CLI_DEPS}        \
		${CORE_DEPS}       \
		${DASHBOARDS_DEPS} \
		${ICAL_DEPS}       \
		${MAILGATE_DEPS}   \
		${USERLOGO_DEPS}

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES+=		perl5
USE_AUTOTOOLS=	autoconf

DATADIR=	${LOCALBASE}/share/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-noportdocs-Makefile.in
.endif

.if ${PORT_OPTIONS:MAP_MODPERL}
BUILD_DEPENDS+=	${MODPERL2_DEPS}
RUN_DEPENDS+=	${MODPERL2_DEPS}
.endif

.if ${PORT_OPTIONS:MAP_MODFASTCGI}
USE_APACHE_RUN=	22+
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi \
		${FASTCGI_DEPS}
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
BUILD_DEPENDS+=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd
RUN_DEPENDS+=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd
.endif

.if ${PORT_OPTIONS:MSPAWN_FCGI}
BUILD_DEPENDS+=	${LOCALBASE}/bin/spawn-fcgi:${PORTSDIR}/www/spawn-fcgi
RUN_DEPENDS+=	${LOCALBASE}/bin/spawn-fcgi:${PORTSDIR}/www/spawn-fcgi
.endif

.if !${PORT_OPTIONS:MMYSQL} && !${PORT_OPTIONS:MPGSQL} && \
	! ${PORT_OPTIONS:MORACLE} && !${PORT_OPTIONS:MSQLITE}
IGNORE=	please select one of MYSQL, PGSQL, ORACLE or SQLITE
.endif

.if ${PORT_OPTIONS:MMYSQL}
DB_TYPE=	mysql
USE_MYSQL=	yes
BUILD_DEPENDS+=	${MYSQL_DEPS}
RUN_DEPENDS+=	${MYSQL_DEPS}
.endif

.if ${PORT_OPTIONS:MPGSQL}
DB_TYPE=	Pg
USE_PGSQL=	yes
BUILD_DEPENDS+=	${PGSQL_DEPS}
RUN_DEPENDS+=	${PGSQL_DEPS}
.endif

.if ${PORT_OPTIONS:MORACLE}
DB_TYPE=	Oracle
BUILD_DEPENDS+=	${ORACLE_DEPS}
RUN_DEPENDS+=	${ORACLE_DEPS}
.endif

.if ${PORT_OPTIONS:MSQLITE}
DB_TYPE=	SQLite
USE_SQLITE=	yes
BUILD_DEPENDS+=	${SQLITE_DEPS}
RUN_DEPENDS+=	${SQLITE_DEPS}
.endif

.if ${PORT_OPTIONS:MDEV}
BUILD_DEPENDS+=	${DEVELOPER_DEPS}
RUN_DEPENDS+=	${DEVELOPER_DEPS}
CONFIGURE_ARGS+=	--enable-developer
.else
CONFIGURE_ARGS+=	--disable-developer
.endif

.if ${PORT_OPTIONS:MSMIME}
BUILD_DEPENDS+=	${SMIME_DEPS}
RUN_DEPENDS+=	${SMIME_DEPS}
CONFIGURE_ARGS+=	--enable-smime
.else
CONFIGURE_ARGS+=	--disable-smime
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
BUILD_DEPENDS+=	${GRAPHVIZ_DEPS}
RUN_DEPENDS+=	${GRAPHVIZ_DEPS}
CONFIGURE_ARGS+=	--enable-graphviz
.else
CONFIGURE_ARGS+=	--disable-graphviz
.endif

.if ${PORT_OPTIONS:MGPG}
BUILD_DEPENDS+=	${GPG_DEPS}
RUN_DEPENDS+=	${GPG_DEPS}
CONFIGURE_ARGS+=	--enable-gpg
.else
CONFIGURE_ARGS+=	--disable-gpg
.endif

.if ${PORT_OPTIONS:MGD}
BUILD_DEPENDS+=	${GD_DEPS}
RUN_DEPENDS+=	${GD_DEPS}
CONFIGURE_ARGS+=	--enable-gd
.else
CONFIGURE_ARGS+=	--disable-gd
.endif

RT_ETC_PATH?=	${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}
RT_LAYOUT=	FreeBSD
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

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

CONFIGURE_ARGS+=	--enable-layout=${RT_LAYOUT} \
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

CONFIGURE_ENV+=	PERL=${LOCALBASE}/bin/perl

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST=	RT_ETC_PATH=${RT_ETC_PATH}

run-autotools:	run-autotools-autoconf

pre-fetch:
	@${ECHO} ""
	@${ECHO} "Additional database related settings you can use:"
	@${ECHO} "      DB_HOST=hostname                The database host (localhost)"
	@${ECHO} "      DB_PORT=port                    The database port"
	@${ECHO} "      DB_DATABASE=dbname              The database name (rt4)"
	@${ECHO} ""
	@${ECHO} "      DB_DBA_USER=username            Name of database administrator (root)"
	@${ECHO} "      DB_DBA_PASSWORD=password        Password of database administrator"
	@${ECHO} "      DB_USER=username                Name of database user for RT (rt_user)"
	@${ECHO} "      DB_PASSWORD=password            Name of database password for RT (rt_pass)"
.if ${PORT_OPTIONS:MSQLITE}
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/upgrade
	(cd ${WRKSRC}/etc && \
	    ${COPYTREE_SHARE} upgrade ${STAGEDIR}${DOCSDIR} "! -name *\.in")
.endif

.include <bsd.port.mk>
