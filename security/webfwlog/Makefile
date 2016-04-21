# Created by: Bob Hockney <zeus@ix.netcom.com>
# $FreeBSD$

PORTNAME=	webfwlog
PORTVERSION=	1.01
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	zeus@ix.netcom.com
COMMENT=	Web-based firewall log analyzer

LICENSE=	GPLv2

BROKEN_powerpc64=	Does not build

OPTIONS_DEFINE=		MYSQL MYSQLIPV6 PGSQL DOCS
OPTIONS_DEFAULTS=	MYSQL MYSQLIPV6

MYSQLIPV6_DESC=		Shared library plugin for Mysql IPv6 support

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-html-doc-root=${WWWDIR} \
			--enable-syslog \
			--sysconfdir=${ETCDIR} \
			--disable-dependency-tracking

MYSQL_CONFIGURE_WITH=	mysql
PGSQL_CONFIGURE_WITH=	pgsql
MYSQLIPV6_CONFIGURE_ENABLE=	mysql-ipv6

USE_PHP=	session
WANT_PHP_WEB=	yes

PORTDOCS=	AUTHORS COPYING CREDITS ChangeLog INSTALL \
		README ReleaseNotes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysqli
USE_MYSQL=	server
MYSQL_PLUGIN_DIR_REL=	lib/mysql/plugin
MYSQL_PLUGIN_DIR=	${LOCALBASE}/${MYSQL_PLUGIN_DIR_REL}
.if ${PORT_OPTIONS:MMYSQLIPV6} && exists (${MYSQL_PLUGIN_DIR})
USES+=	libtool
CONFIGURE_ARGS+=	--libdir=${MYSQL_PLUGIN_DIR}
USE_LDCONFIG=	${MYSQL_PLUGIN_DIR}
PLIST_FILES+=	${MYSQL_PLUGIN_DIR_REL}/libwebfwlog_udf.so
PLIST_FILES+=	${MYSQL_PLUGIN_DIR_REL}/libwebfwlog_udf.so.0
PLIST_FILES+=	${MYSQL_PLUGIN_DIR_REL}/libwebfwlog_udf.so.0.0.0
.endif
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
USES+=	pgsql
WANT_PGSQL=	server client
.endif

SUB_FILES=	pkg-message
SUB_LIST+=	VERSION=${PORTVERSION}

PLIST_SUB+=	WWWGRP=${WWWGRP}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/include/
	@${INSTALL_DATA} ${WRKSRC}/webfwlog/style.css ${STAGEDIR}${WWWDIR}
	@${INSTALL_DATA} ${WRKSRC}/webfwlog/index.php ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC}/webfwlog/include/ && ${COPYTREE_SHARE} \*.php ${STAGEDIR}${WWWDIR}/include/)
	@${ECHO} "Installed web files in ${WWWDIR}"
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/webfwlog.conf ${STAGEDIR}${ETCDIR}/webfwlog.conf.sample
	@${ECHO} "Installed ${ETCDIR}/webfwlog.conf"
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wfwl_syslog ${STAGEDIR}${PREFIX}/bin/
	@${ECHO} "Installed ${PREFIX}/bin/wfwl_syslog"
.if ${PORT_OPTIONS:MMYSQLIPV6} && exists (${MYSQL_PLUGIN_DIR})
	@${MKDIR} ${STAGEDIR}${MYSQL_PLUGIN_DIR}
	@(cd ${WRKSRC}/src/mysql && ${MAKE} DESTDIR=${STAGEDIR} install-strip)
	@${ECHO} "Installed mysql shared library in ${MYSQL_PLUGIN_DIR}"
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/mysql
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pgsql
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/examples
	@(cd ${WRKSRC}/mysql/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/mysql/)
	@(cd ${WRKSRC}/pgsql/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/pgsql/)
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/examples/)
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
