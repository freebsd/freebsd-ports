PORTNAME=	opensmtpd-extras
PORTVERSION?=	6.7.1
PORTREVISION?=	0
PORTEPOCH?=	1
CATEGORIES+=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/

# NB: Please reset PORTREVISION to 0 in all slave subports
# while updating PORTVERSION for master port

MAINTAINER=	fluffy@FreeBSD.org
COMMENT?=	Addons for OpenSMTPD

LICENSE?=	ISCL

LIB_DEPENDS+=	libevent.so:devel/libevent

USES+=		autoreconf ssl libtool
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

CONFIGURE_ARGS+=	--sysconfdir="${PREFIX}/etc/mail" \
			--with-libevent=${LOCALBASE} \
			--with-libssl=${OPENSSLBASE}

NO_OPTIONS_SORT=	yes

# NB: Please *DO NOT* add the following; they are NOT for end-users:
# queue-null, queue-stub
# scheduler-stub
# table-stub

#
# Pass OpenSMTPD branch selection to all extras
#
#OPTIONS_DEFINE=	OPENSMTP_DEVEL

#OPENSMTP_DEVEL_DESC=	Depend on opensmtpd-devel (opensmtpd if off)
#OPENSMTP_DEVEL_BUILD_DEPENDS_OFF=	smtpctl:mail/opensmtpd
#OPENSMTP_DEVEL_RUN_DEPENDS_OFF=		smtpctl:mail/opensmtpd
#OPENSMTP_DEVEL_BUILD_DEPENDS=	smtpctl:mail/opensmtpd-devel
#OPENSMTP_DEVEL_RUN_DEPENDS=	smtpctl:mail/opensmtpd-devel
BUILD_DEPENDS=	smtpctl:mail/opensmtpd
RUN_DEPENDS=	smtpctl:mail/opensmtpd

.if empty(SLAVE_PORT)
OPTIONS_GROUP=			TABLE QUEUE SCHEDULER
OPTIONS_GROUP_QUEUE=		QUEUE_RAM
OPTIONS_GROUP_SCHEDULER=	SCHEDULER_RAM
OPTIONS_GROUP_TABLE=		TABLE_LDAP TABLE_MYSQL TABLE_PASSWD TABLE_PGSQL TABLE_REDIS TABLE_SOCKETMAP TABLE_SQLITE
OPTIONS_DEFAULT=		${OPTIONS_GROUP_TABLE}

# Groups
QUEUE_DESC=			EXPERIMENTAL QUEUES
SCHEDULER_DESC=			EXPERIMENTAL SCHEDULERS
TABLE_DESC=			BASE TABLES

# Queues
QUEUE_RAM_DESC=			The queue-ram

# Schedulers
SCHEDULER_RAM_DESC=		The scheduler-ram

# Tables
TABLE_LDAP_DESC=		LDAP table support
TABLE_MYSQL_DESC=		MySQL table support
TABLE_PASSWD_DESC=		passwd(5) table support
TABLE_PGSQL_DESC=		PgSQL table support
TABLE_REDIS_DESC=		REDIS table support
TABLE_SOCKETMAP_DESC=		Socketmap protocol support
TABLE_SQLITE_DESC=		SQLite table support

INSTALL_DIR=			${LOCALBASE}/libexec/opensmtpd

NO_ARCH=	yes

# Queues
QUEUE_RAM_RUN_DEPENDS=			${INSTALL_DIR}/queue-ram:mail/opensmtpd-extras-queue-ram

# Schedulers
SCHEDULER_RAM_RUN_DEPENDS=		${INSTALL_DIR}/scheduler-ram:mail/opensmtpd-extras-scheduler-ram

# Tables
TABLE_LDAP_RUN_DEPENDS=			${INSTALL_DIR}/table-ldap:mail/opensmtpd-extras-table-ldap
TABLE_MYSQL_RUN_DEPENDS=		${INSTALL_DIR}/table-mysql:mail/opensmtpd-extras-table-mysql
TABLE_PASSWD_RUN_DEPENDS=		${INSTALL_DIR}/table-passwd:mail/opensmtpd-extras-table-passwd
TABLE_PGSQL_RUN_DEPENDS=		${INSTALL_DIR}/table-postgres:mail/opensmtpd-extras-table-postgresql
TABLE_REDIS_RUN_DEPENDS=		${INSTALL_DIR}/table-redis:mail/opensmtpd-extras-table-redis
TABLE_SOCKETMAP_RUN_DEPENDS=		${INSTALL_DIR}/table-socketmap:mail/opensmtpd-extras-table-socketmap
TABLE_SQLITE_RUN_DEPENDS=		${INSTALL_DIR}/table-sqlite:mail/opensmtpd-extras-table-sqlite

#.else

.endif

.include <bsd.port.mk>
