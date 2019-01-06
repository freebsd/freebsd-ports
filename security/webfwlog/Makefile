# Created by: Bob Hockney <zeus@ix.netcom.com>
# $FreeBSD$

PORTNAME=	webfwlog
PORTVERSION=	1.1.1
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/
MASTER_SITES=	http://devel.webfwlog.net/download/v1.1.x/

MAINTAINER=	zeus@ix.netcom.com
COMMENT=	Web-based firewall log analyzer

LICENSE=	GPLv2

USES=			php:web

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-syslog \
			--sysconfdir=${ETCDIR} \
			--disable-dependency-tracking

USE_PHP=		session

OPTIONS_DEFINE=		DOCS

OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	MYSQLIPV6 MYSQL PGSQL
BACKENDS_DESC=		Database backends, choose at least one

OPTIONS_GROUP=		GEOIPV2
OPTIONS_GROUP_GEOIPV2=	LIBMAXMINDDB MAXMINDDB BDB
GEOIPV2_DESC=		GEOIPv2 support

OPTIONS_DEFAULT=	MYSQLIPV6 MYSQL

MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USE=		php=mysqli

MYSQLIPV6_DESC=			Build plugin for Mysql IPv6 support (implies MYSQL)
MYSQLIPV6_IMPLIES=		MYSQL
MYSQLIPV6_CONFIGURE_ENABLE=	mysql-ipv6
MYSQLIPV6_PLUGIN_DIR_REL=	lib/mysql/plugin
MYSQLIPV6_PLUGIN_DIR=		${LOCALBASE}/${MYSQLIPV6_PLUGIN_DIR_REL}
MYSQLIPV6_CONFIGURE_ON=		--libdir=${MYSQLIPV6_PLUGIN_DIR}
MYSQLIPV6_USES=			libtool
MYSQLIPV6_USE=			ldconfig=${MYSQLIPV6_PLUGIN_DIR}
MYSQLIPV6_PLIST_FILES=		${MYSQLIPV6_PLUGIN_DIR_REL}/libwebfwlog_udf.so \
				${MYSQLIPV6_PLUGIN_DIR_REL}/libwebfwlog_udf.so.0 \
				${MYSQLIPV6_PLUGIN_DIR_REL}/libwebfwlog_udf.so.0.0.0

PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_USE=		php=pgsql
PGSQL_USES=		pgsql

LIBMAXMINDDB_DESC=		Full geoipv2 support for file logs, and lookup only
LIBMAXMINDDB_CONFIGURE_WITH=	libmaxminddb
LIBMAXMINDDB_CPPFLAGS=		-I${LOCALBASE}/include
LIBMAXMINDDB_LDFLAGS=		-L${LOCALBASE}/lib
LIBMAXMINDDB_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

MAXMINDDB_DESC=			PHP extension for geoipv2 speed (implies LIBMAXMINDDB)
MAXMINDDB_IMPLIES=		LIBMAXMINDDB
MAXMINDDB_RUN_DEPENDS=		${PHPBASE}/lib/php/${PHP_EXT_DIR}/maxminddb.so:devel/php-maxminddb

BDB_DESC=			Use berkeley DB for file log speed (implies LIBMAXMINDDB)
BDB_IMPLIES=			LIBMAXMINDDB
BDB_CONFIGURE_WITH=		libdb=${BDB_LIB_NAME}
BDB_CPPFLAGS=			-I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=			-L${BDB_LIB_DIR}
BDB_USES=			bdb

PORTDOCS=	AUTHORS COPYING CREDITS ChangeLog INSTALL \
		README README.geoip README.pdf ReleaseNotes

SUB_FILES=	pkg-message
SUB_LIST+=	VERSION=${PORTVERSION}

PLIST_SUB+=	WWWGRP=${WWWGRP}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQLIPV6}
USES+=	mysql:server,client
.elif ${PORT_OPTIONS:MMYSQL}
USES+=	mysql:client
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/include/
	${INSTALL_DATA} ${WRKSRC}/webfwlog/style.css ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webfwlog/index.php ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/webfwlog/include/ && ${COPYTREE_SHARE} \*.php ${STAGEDIR}${WWWDIR}/include/)
	@${MKDIR} ${STAGEDIR}${WWWDIR}-vendor
	@(cd ${WRKSRC}/webfwlog-vendor/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}-vendor)
	@${RM} -r ${STAGEDIR}${WWWDIR}-vendor/maxmind-db/reader/ext
	@${ECHO} "Installed web files in ${WWWDIR}"
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/webfwlog.conf ${STAGEDIR}${ETCDIR}/webfwlog.conf.sample
	@${ECHO} "Installed ${ETCDIR}/webfwlog.conf"
	${INSTALL_PROGRAM} ${WRKSRC}/src/wfwl_syslog ${STAGEDIR}${PREFIX}/bin/
	@${ECHO} "Installed ${PREFIX}/bin/wfwl_syslog"
.if ${PORT_OPTIONS:MMYSQLIPV6} && exists (${MYSQLIPV6_PLUGIN_DIR})
	@${MKDIR} ${STAGEDIR}${MYSQLIPV6_PLUGIN_DIR}
	@(cd ${WRKSRC}/src/mysql && ${MAKE} DESTDIR=${STAGEDIR} install-strip)
	@${ECHO} "Installed mysql shared library in ${MYSQLIPV6_PLUGIN_DIR}"
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/mysql
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pgsql
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/examples
	@(cd ${WRKSRC}/mysql/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/mysql/)
	@(cd ${WRKSRC}/pgsql/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/pgsql/)
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/examples/)
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
