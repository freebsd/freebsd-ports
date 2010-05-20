# Ports collection makefile for:	RackMonkey
# Date created:				2010-02-10
# Whom:					Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	rackmonkey
PORTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	net-mgmt www
MASTER_SITES=	SF \
		ftp://ftp.secure-computing.net/pub/FreeBSD/ports/${PORTNAME}/ \
		ftp://ftp2.secure-computing.net/pub/FreeBSD/ports/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	A web-based tool for managing racks of equipment

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-Spreadsheet-WriteExcel>=0:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

OPTIONS=	\
	SQLITE		"Use SQLite Backend"	on  \
	MYSQL		"Use MySQL Backend" 	off \
	POSTGRES	"Use Posgres Backend"	off \
	INIT_DB		"Initialize DB at installation (SQLite Only)"	on  \
	SAMPLE		"Install sample data (SQLite Only)"	on

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}-1
NO_BUILD=	YES

USE_PERL5_RUN=	YES

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>
.if defined(WITH_SQLITE)
USE_SQLITE=	yes
RUN_DEPENDS+=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
.endif
.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.endif
.if defined(WITH_POSTGRES)
USE_PGSQL=	83
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

do-install:
	${MKDIR} ${WWWDIR}/
	${INSTALL} ${WRKSRC}/perl/rackmonkey.pl ${WRKSRC}/perl/rack2xls.pl ${WRKSRC}/perl/rackdns.pl ${WWWDIR}/
	cd ${WRKSRC}/www && ${COPYTREE_SHARE} \* ${WWWDIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} tmpl ${WWWDIR}/
	cd ${WRKSRC}/perl && ${COPYTREE_SHARE} RackMonkey ${WWWDIR}/
	${MKDIR} ${WRKDIR}/build_conf; \
	${CP} ${WRKSRC}/conf/rackmonkey.conf-default ${WRKDIR}/build_conf/rackmonkey.conf; \
	if [ "${WITH_SQLITE}" ]; then \
		${ECHO} "Building with SQLite............."; \
		${SED} -i '' -e 's%dbconnect =%dbconnect = dbi:SQLite:dbname=${WWWDIR}/rackmonkey.db%' ${WRKDIR}/build_conf/rackmonkey.conf; \
		if [ "${WITH_INIT_DB}" ]; then \
			if [ -e "${WWWDIR}/rackmonkey.db" ]; then \
				${ECHO} "Database exists, skipping initalization..."; \
			else \
				${LOCALBASE}/bin/sqlite3 ${WWWDIR}/rackmonkey.db < ${WRKSRC}/sql/schema/schema.sqlite.sql; \
				${LOCALBASE}/bin/sqlite3 ${WWWDIR}/rackmonkey.db < ${WRKSRC}/sql/data/default_data.sql; \
				if [ "${WITH_SAMPLE}" ]; then \
					${LOCALBASE}/bin/sqlite3 ${WWWDIR}/rackmonkey.db < ${WRKSRC}/sql/data/sample_data.sql; \
				fi \
			fi \
		fi \
	elif [ "${WITH_MYSQL}" -o "${WITH_POSTGRES}" ]; then \
		${INSTALL} ${WRKSRC}/conf/rackmonkey.conf-default ${WWWDIR}/; \
	fi
	if [ -e "${WWWDIR}/rackmonkey.conf" ]; then \
		${MV} ${WWWDIR}/rackmonkey.conf ${WWWDIR}/rackmonkey.conf.old; \
	fi
	${SED} -i '' \
		-e 's/#plugin_xls/plugin_xls/' \
		-e 's/#plugin_dns/plugin_dns/' \
		-e 's%tmplpath =%tmplpath = ${WWWDIR}/tmpl%' \
		-e 's%wwwpath =%wwwpath = /rackmonkey%' \
		${WRKDIR}/build_conf/rackmonkey.conf
	${INSTALL} ${WRKDIR}/build_conf/rackmonkey.conf ${WWWDIR}/
	${INSTALL} ${WRKDIR}/build_conf/rackmonkey.conf ${WWWDIR}/rackmonkey.conf-default
	cd ${WRKSRC} && ${COPYTREE_SHARE} sql ${WWWDIR}/
	cd ${WRKSRC} && ${COPYTREE_SHARE} doc ${WWWDIR}/
	${CHOWN} -R 80:80 ${WWWDIR}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
