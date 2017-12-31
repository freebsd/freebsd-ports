# Created by: Bob Hockney <zeus@ix.netcom.com>
# $FreeBSD$

PORTNAME=	webfwlog
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	zeus@ix.netcom.com
COMMENT=	Web-based firewall log analyzer

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-syslog \
			--sysconfdir=${ETCDIR} \
			--disable-dependency-tracking

USE_PHP=	session

OPTIONS_DEFINE=		MODPHP DOCS

OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	MYSQLIPV6 MYSQL PGSQL
BACKENDS_DESC=		Database backends, choose at least one

OPTIONS_GROUP=		GEOIPV2
OPTIONS_GROUP_GEOIPV2=	LIBMAXMINDDB BDB
GEOIPV2_DESC=		GEOIPv2 support, LIBMAXMINDDB required, BDB optional

OPTIONS_DEFAULT=	MYSQLIPV6 MYSQL

MODPHP_DESC=		Require mod_php (adds apache dependency)
MODPHP_USES=		php:mod
MODPHP_USES_OFF=	php:web

MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USE=		php=mysqli
MYSQL_USES=		mysql:client

MYSQLIPV6_DESC=			Build plugin for Mysql IPv6 support (implies MYSQL)
MYSQLIPV6_IMPLIES=		MYSQL
MYSQLIPV6_CONFIGURE_ENABLE=	mysql-ipv6
MYSQLIPV6_PLUGIN_DIR_REL=	lib/mysql/plugin
MYSQLIPV6_PLUGIN_DIR=		${LOCALBASE}/${MYSQLIPV6_PLUGIN_DIR_REL}
MYSQLIPV6_CONFIGURE_ON=		--libdir=${MYSQLIPV6_PLUGIN_DIR}
MYSQLIPV6_USES=			libtool mysql:server,client
MYSQLIPV6_USE=			ldconfig=${MYSQLIPV6_PLUGIN_DIR}
MYSQLIPV6_PLIST_FILES=		${MYSQLIPV6_PLUGIN_DIR_REL}/libwebfwlog_udf.so \
				${MYSQLIPV6_PLUGIN_DIR_REL}/libwebfwlog_udf.so.0 \
				${MYSQLIPV6_PLUGIN_DIR_REL}/libwebfwlog_udf.so.0.0.0

PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_USE=		php=pgsql
PGSQL_USES=		pgsql
PGSQL_ARGS=		want_pgsql=client

LIBMAXMINDDB_DESC=		Libmaxminddb support for geoipv2 (.mmdb extension)
LIBMAXMINDDB_CONFIGURE_WITH=	libmaxminddb
LIBMAXMINDDB_CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
LIBMAXMINDDB_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb

BDB_DESC=			Berkeley DB support (implies LIBMAXMINDDB)
BDB_IMPLIES=			LIBMAXMINDDB
BDB_CONFIGURE_WITH=		libdb
BDB_CONFIGURE_ENV=		CPPFLAGS="-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include" LDFLAGS=-L${LOCALBASE}/lib LIBS=-l${BDB_LIB_NAME}
BDB_USES=			bdb

PORTDOCS=	AUTHORS COPYING CREDITS ChangeLog INSTALL \
		README ReleaseNotes

SUB_FILES=	pkg-message
SUB_LIST+=	VERSION=${PORTVERSION}

PLIST_SUB+=	WWWGRP=${WWWGRP}

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/include/
	${INSTALL_DATA} ${WRKSRC}/webfwlog/style.css ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/webfwlog/index.php ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/webfwlog/include/ && ${COPYTREE_SHARE} \*.php ${STAGEDIR}${WWWDIR}/include/)
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
