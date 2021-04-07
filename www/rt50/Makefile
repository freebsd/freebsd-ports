PORTNAME=	rt
DISTVERSION=	5.0.1
CATEGORIES=	www
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/
PKGNAMESUFFIX=	50

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Industrial-grade ticketing system written in Perl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	rt42-4.2* rt44-4.4* brlcad-[0-9]*

NO_ARCH=	yes

# See docs/web_deployment.pod for info on the choices of webserver /
# webapp combinations.  Note: if using apache, apache-2.4+ is
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
# See docs/full_text_indexing.pod if you need to set up full text
# indexes on your ticket database.  PostgreSQL is
# recommended in this case: the MYSQL / SphinxSearch combination
# mentioned in the docs is currently unsupported in the ports, but see
# http://www.infracaninophile.co.uk/articles/sphinxse.html

OPTIONS_DEFINE=		DEVELOPER EXTERNALAUTH GD GPG GRAPHVIZ SMIME DOCS
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL SQLITE
OPTIONS_RADIO=		WEB
OPTIONS_RADIO_WEB=	AP_MODFASTCGI AP_MODPERL LIGHTTPD SPAWN_FCGI

OPTIONS_DEFAULT=	AP_MODFASTCGI EXTERNALAUTH GD GPG MYSQL

USERS?=		www
GROUPS?=	rt www

.include "${.CURDIR}/Makefile.cpan"

RUN_DEPENDS+=	${CLI_DEPS}        \
		${CORE_DEPS}       \
		${DASHBOARDS_DEPS} \
		${ICAL_DEPS}       \
		${MAILGATE_DEPS}   \
		${REST2_DEPS}   \
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

AP_MODFASTCGI_DESC=		Deploy with apache and mod_fastcgi
AP_MODFASTCGI_USE=		APACHE_RUN=22+
AP_MODFASTCGI_RUN_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:www/mod_fastcgi \
				${FASTCGI_DEPS}

EXTERNALAUTH_DESC=		Extension to authenticate users against an external source
EXTERNALAUTH_DEPENDS=		${EXTERNALAUTH_DEPS}

LIGHTTPD_DESC=			Deploy with lighttpd and mod_fastcgi
LIGHTTPD_RUN_DEPENDS=		${LOCALBASE}/sbin/lighttpd:www/lighttpd \
				${FASTCGI_DEPS}

SPAWN_FCGI_DESC=		Deploy with spawn_fcgi
SPAWN_FCGI_RUN_DEPENDS=		${LOCALBASE}/bin/spawn-fcgi:www/spawn-fcgi \
				${FASTCGI_DEPS}

MYSQL_RUN_DEPENDS=		${MYSQL_DEPS}
MYSQL_VARS=			DB_TYPE=mysql DB_DBA_USER=root

PGSQL_RUN_DEPENDS=		${PGSQL_DEPS}
PGSQL_VARS=			DB_TYPE=Pg DB_DBA_USER=pgsql

SQLITE_RUN_DEPENDS=		${SQLITE_DEPS}
SQLITE_VARS=			DB_TYPE=SQLite DB_DBA_USER=root

DEVELOPER_DESC=			Configure for Developers
DEVELOPER_RUN_DEPENDS=		${DEVELOPER_DEPS}
DEVELOPER_CONFIGURE_ENABLE=	developer

SMIME_DESC=			Enable Secure MIME support
SMIME_RUN_DEPENDS=		${SMIME_DEPS}
SMIME_CONFIGURE_ENABLE=		smime

GRAPHVIZ_RUN_DEPENDS=		${GRAPHVIZ_DEPS}
GRAPHVIZ_CONFIGURE_ENABLE=	graphviz

GPG_DESC=			Enable GnuPG support
GPG_RUN_DEPENDS=		${GPG_DEPS}
GPG_CONFIGURE_ENABLE=		gpg

GD_DESC=			Enable GD Graphs and Charts
GD_RUN_DEPENDS=			${GD_DEPS}
GD_CONFIGURE_ENABLE=		gd

BUILD_DEPENDS+=	${RUN_DEPENDS}

DB_DBA_PASSWORD?=
DB_USER?=	rt_user
DB_PASSWORD?=	rt_pass
DB_HOST?=	localhost
DB_DATABASE?=	rt5

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

SUB_FILES=	pkg-message
SUB_LIST=	RT_ETC_PATH=${RT_ETC_PATH}
PLIST_SUB=	RT_ETC_DIR=${RT_ETC_DIR}

pre-fetch:
	@${ECHO} ""
	@${ECHO} "Additional database related settings you can use:"
	@${ECHO} "      DB_HOST=hostname                The database host (localhost)"
	@${ECHO} "      DB_PORT=port                    The database port"
	@${ECHO} "      DB_DATABASE=dbname              The database name (rt5)"
	@${ECHO} ""
	@${ECHO} "      DB_DBA_USER=username            Name of database administrator (root)"
	@${ECHO} "      DB_DBA_PASSWORD=password        Password of database administrator"
	@${ECHO} "      DB_USER=username                Name of database user for RT (rt_user)"
	@${ECHO} "      DB_PASSWORD=password            Name of database password for RT (rt_pass)"

pre-fetch-SQLITE-on:
	@${ECHO} ""
	@${ECHO} "SQLITE is not recommended for production use"

post-patch:
	@${RM} ${WRKSRC}/lib/RT.pm.in.orig
	@${REINPLACE_CMD} -e 's!%%PREFIX%%!${PREFIX}!g' ${WRKSRC}/config.layout
	@${REINPLACE_CMD} -e 's!%%SITE_PERL%%!${PREFIX}/${SITE_PERL_REL}!g' ${WRKSRC}/config.layout
	@${REINPLACE_CMD} -e 's!/path/to/your/etc!${RT_ETC_PATH}!g' ${WRKSRC}/etc/RT_SiteConfig.pm
	@${REINPLACE_CMD} -e 's!/bin:/usr/bin!/bin:/usr/bin:${LOCALBASE}/bin!' ${WRKSRC}/lib/RT/Interface/CLI.pm && \
	    ${RM} ${WRKSRC}/lib/RT/Interface/CLI.pm.bak
	@${REINPLACE_CMD} -e 's!RT_ETC_DIR!${RT_ETC_DIR}!' ${WRKSRC}/sbin/rt-test-dependencies.in

pre-install:
	@${RM} ${WRKSRC}/lib/RT.pm.in

post-install:
	@${RM} -r ${STAGEDIR}/${WWWDIR}${PKGNAMESUFFIX}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/upgrade
	(cd ${WRKSRC}/etc && \
	    ${COPYTREE_SHARE} upgrade ${STAGEDIR}${DOCSDIR} "! -name *\.in")

.include <bsd.port.mk>
