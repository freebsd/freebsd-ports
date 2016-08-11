# $FreeBSD$

PORTNAME=	rt
PORTVERSION=	4.0.24
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/
PKGNAMESUFFIX=	40

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	RT is an industrial-grade ticketing system written in Perl

CONFLICTS_INSTALL=	rt42-4.2* rt44-4.4* brlcad-[0-9]*

NO_ARCH=	yes

# See doc/web_deployment.pod for info on the choices of webserver /
# webapp combinations.  Note: if using apache, apache-2.2+ is
# recommended.  For deployment with nginx, use the SPAWN_FCGI method
# or the builtin webserver with a FCGI handler.
#
# The builtin standalone PSGI based webserver is always available, no
# matter what choice of web deployment platform, or none, that you
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

OPTIONS_DEFINE=		DEV GD GPG GRAPHVIZ SSL_MAILGATE DOCS
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL ORACLE PGSQL SQLITE
OPTIONS_RADIO=		WEB
OPTIONS_RADIO_WEB=	AP_MODFASTCGI AP_MODPERL LIGHTTPD SPAWN_FCGI

OPTIONS_DEFAULT=	AP_MODFASTCGI GD GPG MYSQL

USERS?=		www
GROUPS?=	rt www

RUN_DEPENDS+=	${LOCALBASE}/bin/jsmin:devel/jsmin

.include "${.CURDIR}/Makefile.cpan"

RUN_DEPENDS+=	${CORE_DEPS}       \
		${MASON_DEPS}      \
		${PSGI_DEPS}       \
		${MAILGATE_DEPS}   \
		${CLI_DEPS}        \
		${ICAL_DEPS}       \
		${SMTP_DEPS}       \
		${DASHBOARDS_DEPS} \
		${USERLOGO_DEPS}   \
		${HTML_DOC_DEPS}

USES=		cpe perl5
CPE_VENDOR=	bestpractical

RT_LAYOUT=	FreeBSD
RT_ETC_DIR?=	etc/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
RT_ETC_PATH=	${PREFIX}/${RT_ETC_DIR}

AP_MODPERL_DESC=		Deploy with apache and mod_perl
AP_MODPERL_RUN_DEPENDS=		${MODPERL2_DEPS}
AP_MODPERL_CONFIGURE_ON=	--with-apachectl=${LOCALBASE}/sbin/apachectl

AP_MODFASTCGI_DESC=		Deploy with apache and mod_fastcgi
AP_MODFASTCGI_USE=		APACHE_RUN=22+
AP_MODFASTCGI_RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:www/mod_fastcgi \
				${FASTCGI_DEPS}
AP_MODFASTCGI_CONFIGURE_ON=	--with-apachectl=${LOCALBASE}/sbin/apachectl

LIGHTTPD_DESC=			Deploy with lighttpd and mod_fastcgi
LIGHTTPD_RUN_DEPENDS=		${LOCALBASE}/sbin/lighttpd:www/lighttpd

SPAWN_FCGI_DESC=		Deploy with spawn_fcgi
SPAWN_FCGI_RUN_DEPENDS=		${LOCALBASE}/bin/spawn-fcgi:www/spawn-fcgi

MYSQL_USE=			MYSQL=yes
MYSQL_RUN_DEPENDS=		${MYSQL_DEPS}

PGSQL_USES=			pgsql
PGSQL_RUN_DEPENDS=		${PGSQL_DEPS}

ORACLE_RUN_DEPENDS=		${ORACLE_DEPS}

SQLITE_USES=			sqlite
SQLITE_RUN_DEPENDS=		${SQLITE_DEPS}

DEV_DESC=			Configure for Developers
DEV_RUN_DEPENDS=		${DEV_DEPS}
DEV_CONFIGURE_ON=		--enable-developer-mode

SSL_MAILGATE_DESC=		Enable HTTPS support for rt-mailgate
SSL_MAILGATE_RUN_DEPENDS=	${SSL_MAILGATE_DEPS}
SSL_MAILGATE_CONFIGURE_ENABLE=	ssl-mailgate

GRAPHVIZ_RUN_DEPENDS=		${GRAPHVIZ_DEPS}
GRAPHVIZ_CONFIGURE_ENABLE=	graphviz

GPG_DESC=			Enable GnuPG support
GPG_RUN_DEPENDS=		${GPG_DEPS}
GPG_CONFIGURE_ENABLE=		gpg

GD_DESC=			Enable GD Graphs and Charts
GD_RUN_DEPENDS=			${GD_DEPS}
GD_CONFIGURE_ENABLE=		gd

BUILD_DEPENDS+=	${RUN_DEPENDS}

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MMYSQL} && !${PORT_OPTIONS:MPGSQL} && \
	! ${PORT_OPTIONS:MORACLE} && !${PORT_OPTIONS:MSQLITE}
IGNORE=	please select one of MYSQL, PGSQL, ORACLE or SQLITE
.endif

.if ${PORT_OPTIONS:MMYSQL}
DB_TYPE=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
DB_TYPE=	Pg
.endif

.if ${PORT_OPTIONS:MORACLE}
DB_TYPE=	Oracle
.endif

.if ${PORT_OPTIONS:MSQLITE}
DB_TYPE=	SQLite
.endif


.if ${PORT_OPTIONS:MPGSQL}
DB_DBA_USER?=	pgsql
.else
DB_DBA_USER?=	root
.endif
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
PLIST_SUB=	RT_ETC_DIR=${RT_ETC_DIR}

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
.if ${PORT_OPTIONS:MSQLITE}
	@${ECHO} ""
	@${ECHO} "SQLITE is not recommended for production use"
.endif

post-patch:
	@${RM} -f ${WRKSRC}/lib/RT.pm.in.orig
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!g' ${WRKSRC}/config.layout
	@${REINPLACE_CMD} -e 's!%%SITE_PERL%%!${PREFIX}/${SITE_PERL_REL}!g' ${WRKSRC}/config.layout
	@${REINPLACE_CMD} -e 's!/path/to/your/etc!${RT_ETC_PATH}!g' ${WRKSRC}/etc/RT_SiteConfig.pm
	@${REINPLACE_CMD} -e 's!/bin:/usr/bin!/bin:/usr/bin:${LOCALBASE}/bin!' ${WRKSRC}/lib/RT/Interface/CLI.pm && \
	    ${RM} ${WRKSRC}/lib/RT/Interface/CLI.pm.bak

pre-install:
	@${RM} -f ${WRKSRC}/lib/RT.pm.in

post-install:
	@${RM} -rf ${STAGEDIR}/${WWWDIR}${PKGNAMESUFFIX}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/upgrade
	(cd ${WRKSRC}/etc && \
	    ${COPYTREE_SHARE} upgrade ${STAGEDIR}${DOCSDIR} "! -name *\.in")

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502200
CORE_DEPS+=	p5-CGI>0:www/p5-CGI
.endif

.include <bsd.port.post.mk>
