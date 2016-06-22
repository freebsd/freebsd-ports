# Created by: gahr
# $FreeBSD$

PORTNAME=	opensmtpd-extras
PORTVERSION=	201606212257
PORTREVISION?=	0
CATEGORIES+=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/

# NB: Please reset PORTREVISION to 0 in all slave subports
# while updating PORTVERSION for master port

MAINTAINER?=	fluffy@FreeBSD.org
COMMENT?=	Addons for OpenSMTPD

LICENSE?=	ISCL

LIB_DEPENDS+=	libevent.so:devel/libevent2

USES+=		autoreconf libtool
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir="${PREFIX}/etc/mail"

NO_OPTIONS_SORT=	yes

# NB: Please *DO NOT* add the following; they are NOT for end-users:
# filter-stub, filter-trace, filter-void
# queue-null, queue-stub
# scheduler-stub
# table-stub

#
# Pass OpenSMTPD branch selection to all extras
#
OPTIONS_DEFINE=	OPENSMTP_DEVEL

OPENSMTP_DEVEL_DESC=	Depend on opensmtpd-devel (opensmtpd if off)
OPENSMTP_DEVEL_BUILD_DEPENDS_OFF=	smtpctl:mail/opensmtpd
OPENSMTP_DEVEL_RUN_DEPENDS_OFF=		smtpctl:mail/opensmtpd
OPENSMTP_DEVEL_BUILD_DEPENDS=	smtpctl:mail/opensmtpd-devel
OPENSMTP_DEVEL_RUN_DEPENDS=	smtpctl:mail/opensmtpd-devel

.if empty(SLAVE_PORT)
OPTIONS_GROUP=			TOOLS TABLE FILTER FILTER_EXP QUEUE SCHEDULER
OPTIONS_GROUP_FILTER=		FILTER_CLAMAV FILTER_DKIM FILTER_DNSBL FILTER_MONKEY FILTER_PAUSE FILTER_REGEX FILTER_SPAMASSASSIN
OPTIONS_GROUP_FILTER_EXP=	FILTER_LUA FILTER_PERL FILTER_PYTHON
OPTIONS_GROUP_QUEUE=		QUEUE_PYTHON QUEUE_RAM
OPTIONS_GROUP_SCHEDULER=	SCHEDULER_PYTHON SCHEDULER_RAM
OPTIONS_GROUP_TABLE=		TABLE_LDAP TABLE_MYSQL TABLE_PASSWD TABLE_PGSQL TABLE_PYTHON TABLE_REDIS TABLE_SOCKETMAP TABLE_SQLITE
OPTIONS_GROUP_TOOLS=		TOOL_STATS
OPTIONS_DEFAULT=		${OPTIONS_GROUP_FILTER} ${OPTIONS_GROUP_TABLE} ${OPTIONS_GROUP_TOOLS}

# Groups
FILTER_DESC=			BASE FILTERS
FILTER_EXP_DESC=		EXPERIMENTAL FILTERS
QUEUE_DESC=			EXPERIMENTAL QUEUES
SCHEDULER_DESC=			EXPERIMENTAL SCHEDULERS
TABLE_DESC=			BASE TABLES
TOOLS_DESC=			BASE TOOLS

# Filters
FILTER_CLAMAV_DESC=		Check messages with ClamAV
FILTER_DKIM_DESC=		Sign messages with DKIM
FILTER_DNSBL_DESC=		Check incoming senders against DNSBLs
FILTER_LUA_DESC=		Lua-filter interface
FILTER_MONKEY_DESC=		Filter to arbitrary reject or delay mails
FILTER_PAUSE_DESC=		Pause before SMTP greeting to reduce spam
FILTER_PERL_DESC=		Perl-filter interface
FILTER_PYTHON_DESC=		Python-filter interface
FILTER_REGEX_DESC=		${REGEX_DESC}
FILTER_SPAMASSASSIN_DESC=	Check messages with SpamAssassin

# Queues
QUEUE_PYTHON_DESC=		The queue-python
QUEUE_RAM_DESC=			The queue-ram

# Schedulers
SCHEDULER_PYTHON_DESC=		The scheduler-python
SCHEDULER_RAM_DESC=		The scheduler-ram

# Tables
TABLE_LDAP_DESC=		LDAP table support
TABLE_MYSQL_DESC=		MySQL table support
TABLE_PASSWD_DESC=		passwd(5) table support
TABLE_PGSQL_DESC=		PgSQL table support
TABLE_PYTHON_DESC=		Python table support
TABLE_REDIS_DESC=		REDIS table support
TABLE_SOCKETMAP_DESC=		Socketmap protocol support
TABLE_SQLITE_DESC=		SQLite table support

# Tools
TOOL_STATS_DESC=		Stats tool for OpenSMTPD

PLIST_FILES=			man/man3/filter_api.3.gz
INSTALL_DIR=			${LOCALBASE}/libexec/opensmtpd

NO_ARCH=	yes

# Filters
FILTER_CLAMAV_RUN_DEPENDS=		${INSTALL_DIR}/filter-clamav:mail/opensmtpd-extras-filter-clamav
FILTER_DKIM_RUN_DEPENDS=		${INSTALL_DIR}/filter-dkim-signer:mail/opensmtpd-extras-filter-dkim
FILTER_DNSBL_RUN_DEPENDS=		${INSTALL_DIR}/filter-dnsbl:mail/opensmtpd-extras-filter-dnsbl
FILTER_LUA_RUN_DEPENDS=			${INSTALL_DIR}/filter-lua:mail/opensmtpd-extras-filter-lua
FILTER_MONKEY_RUN_DEPENDS=		${INSTALL_DIR}/filter-monkey:mail/opensmtpd-extras-filter-monkey
FILTER_PAUSE_RUN_DEPENDS=		${INSTALL_DIR}/filter-pause:mail/opensmtpd-extras-filter-pause
FILTER_PERL_RUN_DEPENDS=		${INSTALL_DIR}/filter-perl:mail/opensmtpd-extras-filter-perl
FILTER_PYTHON_RUN_DEPENDS=		${INSTALL_DIR}/filter-python:mail/opensmtpd-extras-filter-python
FILTER_REGEX_RUN_DEPENDS=		${INSTALL_DIR}/filter-regex:mail/opensmtpd-extras-filter-regex
FILTER_SPAMASSASSIN_RUN_DEPENDS=	${INSTALL_DIR}/filter-spamassassin:mail/opensmtpd-extras-filter-spamassassin

# Queues
QUEUE_PYTHON_RUN_DEPENDS=		${INSTALL_DIR}/queue-python:mail/opensmtpd-extras-queue-python
QUEUE_RAM_RUN_DEPENDS=			${INSTALL_DIR}/queue-ram:mail/opensmtpd-extras-queue-ram

# Schedulers
SCHEDULER_PYTHON_RUN_DEPENDS=		${INSTALL_DIR}/scheduler-python:mail/opensmtpd-extras-scheduler-python
SCHEDULER_RAM_RUN_DEPENDS=		${INSTALL_DIR}/scheduler-ram:mail/opensmtpd-extras-scheduler-ram

# Tables
TABLE_LDAP_RUN_DEPENDS=			${INSTALL_DIR}/table-ldap:mail/opensmtpd-extras-table-ldap
TABLE_MYSQL_RUN_DEPENDS=		${INSTALL_DIR}/table-mysql:mail/opensmtpd-extras-table-mysql
TABLE_PASSWD_RUN_DEPENDS=		${INSTALL_DIR}/table-passwd:mail/opensmtpd-extras-table-passwd
TABLE_PGSQL_RUN_DEPENDS=		${INSTALL_DIR}/table-postgres:mail/opensmtpd-extras-table-postgresql
TABLE_PYTHON_RUN_DEPENDS=		${INSTALL_DIR}/table-python:mail/opensmtpd-extras-table-python
TABLE_REDIS_RUN_DEPENDS=		${INSTALL_DIR}/table-redis:mail/opensmtpd-extras-table-redis
TABLE_SOCKETMAP_RUN_DEPENDS=		${INSTALL_DIR}/table-socketmap:mail/opensmtpd-extras-table-socketmap
TABLE_SQLITE_RUN_DEPENDS=		${INSTALL_DIR}/table-sqlite:mail/opensmtpd-extras-table-sqlite

# Tools
TOOL_STATS_RUN_DEPENDS=			tool-stats:mail/opensmtpd-extras-tool-stats
.else

# Only install this for the opensmtpd-extras master port
pre-patch:
	@${REINPLACE_CMD} -e '/man_MANS.*filter_api.3/s/^/#/' \
		${WRKSRC}/extras/wip/filters/Makefile.am

.endif

.include <bsd.port.mk>
