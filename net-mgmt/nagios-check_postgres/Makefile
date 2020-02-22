# Created by: Matthew Seaman <matthew@FreeBSD.org>
# $FreeBSD$

PORTNAME=	check_postgres
PORTVERSION=	2.25.0
CATEGORIES=	net-mgmt databases perl5
MASTER_SITES=	http://bucardo.org/downloads/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Monitor various attributes of your PostgreSQL database

LICENSE=	BSD2CLAUSE

NO_ARCH=	yes

USES=		perl5
USE_PERL5=	configure
USES+=		pgsql

# This script is primarily used for monitoring via Nagios, but it also
# has output styles compatible with cacti or mrtg.  The options
# control whether symlinks get made to locations where those
# applications expect to find their plugin scripts.

OPTIONS_DEFINE=		NAGIOS CACTI
OPTIONS_DEFAULT=	NAGIOS
OPTIONS_SUB=		yes

NAGIOS_DESC=	Create symlinks in Nagios plugins dir
NAGIOS_PLUGINS=	${PREFIX}/libexec/nagios
NAGIOS_LINKS=	archive_ready		\
		autovac_freeze		\
		backends		\
		bloat			\
		checkpoint		\
		cluster_id		\
		commitratio		\
		connection		\
		custom_query		\
		database_size		\
		disabled_triggers	\
		disk_space		\
		fsm_pages		\
		fsm_relations		\
		hitratio		\
		hot_standby_delay	\
		index_size		\
		last_analyze		\
		last_autoanalyze	\
		last_autovacuum		\
		last_vacuum		\
		listener		\
		locks			\
		logfile			\
		new_version_bc		\
		new_version_box		\
		new_version_cp		\
		new_version_pg		\
		new_version_tnm		\
		pgagent_jobs		\
		pgb_pool_cl_active	\
		pgb_pool_cl_waiting	\
		pgb_pool_maxwait	\
		pgb_pool_sv_active	\
		pgb_pool_sv_idle	\
		pgb_pool_sv_login	\
		pgb_pool_sv_tested	\
		pgb_pool_sv_used	\
		pgbouncer_backends	\
		pgbouncer_checksum	\
		prepared_txns		\
		query_runtime		\
		query_time		\
		relation_size		\
		replicate_row		\
		same_schema		\
		sequence		\
		settings_checksum	\
		slony_status		\
		table_size		\
		timesync		\
		txn_idle		\
		txn_time		\
		txn_wraparound		\
		version			\
		wal_files

CACTI_DESC=	Create symlinks in Cacti scripts dir
CACTI_SCRIPTS=	${PREFIX}/share/cacti/scripts
CACTI_LINKS=	dbstats

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e s,%%LOCALBASE%%,${LOCALBASE}, ${WRKSRC}/check_postgres.pl

post-install-NAGIOS-on:
	@${MKDIR} ${STAGEDIR}${NAGIOS_PLUGINS}
.for l in ${NAGIOS_LINKS}
	${LN} -s ../../bin/check_postgres.pl \
		${STAGEDIR}${NAGIOS_PLUGINS}/check_postgres_${l}
.endfor

post-install-CACTI-on:
	@${MKDIR} ${STAGEDIR}${CACTI_SCRIPTS}
.for l in ${CACTI_LINKS}
	${LN} -s ../../../bin/check_postgres.pl \
		${STAGEDIR}${CACTI_SCRIPTS}/check_postgres_${l}
.endfor

regression-test: build
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
