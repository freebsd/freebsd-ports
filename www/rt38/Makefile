# $FreeBSD$

NO_STAGE=	yes
# TODO:
# o etc/rt38 files permissions
# o GRANTS
# o Schema
# - Vhost Config
#   o install a sample into etc/apache22/Includes

PORTNAME=	rt
PORTVERSION=	3.8.17
CATEGORIES=	www
MASTER_SITES=	http://download.bestpractical.com/pub/rt/release/ \
		ftp://ftp.eu.uu.net/pub/unix/ticketing/rt/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RT is an industrial-grade ticketing system written in Perl

CONFLICTS=	rt40-4.0* rt42-4.2* brlcad-[0-9]*
LATEST_LINK=	rt38

OPTIONS_DEFINE=	APACHE DEV DOCS FASTCGI GRAPHVIZ MODPERL STANDALONE
OPTIONS_SINGLE=	DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL ORACLE SQLITE
OPTIONS_DEFAULT=	APACHE GRAPHVIZ MODPERL MYSQL
DEV_DESC=		Configure for Developers
STANDALONE_DESC=	Enable standalone server

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

USES=		perl5
USE_AUTOTOOLS=	autoconf

.include <bsd.port.options.mk>
.if empty(PORT_OPTIONS:MDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-noportdocs-Makefile.in
.endif

.if ${PORT_OPTIONS:MDEV}
BUILD_DEPENDS+=	${DEV_DEPS}
RUN_DEPENDS+=	${DEV_DEPS}
.endif

.if ${PORT_OPTIONS:MSTANDALONE}
BUILD_DEPENDS+=	${STANDALONE_DEPS}
RUN_DEPENDS+=	${STANDALONE_DEPS}
.endif

.if !empty(PORT_OPTIONS:MAPACHE) || !empty(PORT_OPTIONS:MFASTCGI) || !empty(PORT_OPTIONS:MMODPERL)
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MFASTCGI}
BUILD_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_fastcgi.so:${PORTSDIR}/www/mod_fastcgi \
		p5-FCGI>=0.74:${PORTSDIR}/www/p5-FCGI
.endif

.if ${PORT_OPTIONS:MGRAPHVIZ}
BUILD_DEPENDS+=	${GRAPHVIZ_DEPS}
RUN_DEPENDS+=	${GRAPHVIZ_DEPS}
.endif

.if ${PORT_OPTIONS:MMODPERL}
WITH_APACHE=	yes

.include "${.CURDIR}/../../Mk/bsd.apache.mk"

BUILD_DEPENDS+=	p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2 \
	p5-Apache-DBI>=0:${PORTSDIR}/www/p5-Apache-DBI
RUN_DEPENDS+=	p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2 \
	p5-Apache-DBI>=0:${PORTSDIR}/www/p5-Apache-DBI
.endif

.if ${PORT_OPTIONS:MMYSQL}
DB_TYPE=	mysql
USE_MYSQL=	yes
BUILD_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.elif ${PORT_OPTIONS:MPGSQL}
DB_TYPE=	Pg
USE_PGSQL=	yes
BUILD_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.elif ${PORT_OPTIONS:MQLITE}
DB_TYPE=	SQLite
USE_SQLITE=	yes
BUILD_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
.elif ${PORT_OPTIONS:MORACLE}
DB_TYPE=	Oracle
BUILD_DEPENDS+=	p5-DBD-Oracle>=0:${PORTSDIR}/databases/p5-DBD-Oracle
RUN_DEPENDS+=	p5-DBD-Oracle>=0:${PORTSDIR}/databases/p5-DBD-Oracle
.endif

RT_ETC_PATH?=	${PREFIX}/etc/${PORTNAME}38
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
.if ${PORT_OPTIONS:MSQLITE}
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

.include <bsd.port.mk>
