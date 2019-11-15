# Created by: Eric F Crist <ecrist@secure-computing.net>
# $FreeBSD$

PORTNAME=	rackmonkey
PORTVERSION=	1.2.5
DISTVERSIONSUFFIX=	-1
PORTREVISION=	5
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF \
		ftp://ftp.secure-computing.net/pub/FreeBSD/ports/${PORTNAME}/ \
		ftp://ftp2.secure-computing.net/pub/FreeBSD/ports/${PORTNAME}/

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	Web-based tool for managing racks of equipment

RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-CGI>=0:www/p5-CGI \
		p5-HTML-Template>=0:www/p5-HTML-Template \
		p5-Spreadsheet-WriteExcel>=0:textproc/p5-Spreadsheet-WriteExcel \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-HTML-Parser>=0:www/p5-HTML-Parser

OPTIONS_DEFINE=	SQLITE MYSQL PGSQL INIT_DB SAMPLE
OPTIONS_DEFAULT=	SQLITE INIT_DB SAMPLE
INIT_DB_DESC=	Initialize DB at installation (SQLite Only)
SAMPLE_DESC=	Install sample data (SQLite Only)

NO_ARCH=	yes
NO_BUILD=	YES

USES=		perl5
USE_PERL5=	run

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
USES+=		sqlite
RUN_DEPENDS+=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite
.endif
.if ${PORT_OPTIONS:MMYSQL}
USES+=		mysql
RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
.endif
.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
RUN_DEPENDS+=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MINIT_DB}
PLIST_SUB+=	INIT_DB=""
.else
PLIST_SUB+=	INIT_DB="@comment "
.endif

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/perl/rackmonkey.pl ${WRKSRC}/perl/rack2xls.pl ${WRKSRC}/perl/rackdns.pl ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/www && ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} tmpl ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/perl && ${COPYTREE_SHARE} RackMonkey ${STAGEDIR}${WWWDIR}/
	${MKDIR} ${WRKDIR}/build_conf
	${CP} ${WRKSRC}/conf/rackmonkey.conf-default ${WRKDIR}/build_conf/rackmonkey.conf
.if ${PORT_OPTIONS:MSQLITE}
	${SED} -i '' -e 's%dbconnect =%dbconnect = dbi:SQLite:dbname=${WWWDIR}/rackmonkey.db%' ${WRKDIR}/build_conf/rackmonkey.conf
.if ${PORT_OPTIONS:MINIT_DB}
	${LOCALBASE}/bin/sqlite3 ${STAGEDIR}${WWWDIR}/rackmonkey.db.sample < ${WRKSRC}/sql/schema/schema.sqlite.sql
	${LOCALBASE}/bin/sqlite3 ${STAGEDIR}${WWWDIR}/rackmonkey.db.sample < ${WRKSRC}/sql/data/default_data.sql
.if ${PORT_OPTIONS:MSAMPLE}
	${LOCALBASE}/bin/sqlite3 ${STAGEDIR}${WWWDIR}/rackmonkey.db.sample < ${WRKSRC}/sql/data/sample_data.sql
.endif
.endif
.endif
	${SED} -i '' \
		-e 's/#plugin_xls/plugin_xls/' \
		-e 's/#plugin_dns/plugin_dns/' \
		-e 's%tmplpath =%tmplpath = ${WWWDIR}/tmpl%' \
		-e 's%wwwpath =%wwwpath = /rackmonkey%' \
		${WRKDIR}/build_conf/rackmonkey.conf
	${INSTALL_DATA} ${WRKDIR}/build_conf/rackmonkey.conf ${STAGEDIR}${WWWDIR}/rackmonkey.conf.sample
	cd ${WRKSRC} && ${COPYTREE_SHARE} sql ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
