# New ports collection makefile for: vpopmail
# Date created:		21 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vpopmail
PORTVERSION=	5.5.0
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Easy virtual domain and authentication package for use with qmail

BUILD_DEPENDS=	${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp
RUN_DEPENDS=	${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp
USE_QMAIL=	yes

CONFLICTS=	vpopmail-5.*

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	YES

VCFGDIR?=	${WRKDIR}/vcfg
VCFGFILES?=	inc_deps lib_deps tcp.smtp

CONFIGURE_ENV+=	VCFGDIR="${VCFGDIR}"
CONFIGURE_ARGS=	--enable-qmaildir=${QMAIL_PREFIX} \
		--enable-tcprules-prog=${LOCALBASE}/bin/tcprules \
		--enable-tcpserver-file=${PREFIX}/vpopmail/etc/tcp.smtp

#
# User-configurable variables
#
# Define these to change from the default behaviour
#
# WITH_PASSWD   - allow authentication off /etc/passwd
# WITHOUT_MD5_PASSWORDS - store encrypted passwords in MD5 format
# WITH_CLEAR_PASSWD - store passwords in plaintext
# WITH_LEARN_PASSWORDS	- enable learning passwords during pop auth
# WITH_MYSQL	- allow authentitation via mysql
# WITH_MYSQL_REPLICATION - enables MySQL database replication
# WITH_MYSQL_LIMITS - enables the MySQL mailbox limit code
# WITH_PGSQL	- allow authentication via PostgreSQL
# WITH_SYBASE   - allow authentication via Sybase (NOT TESTED!)
# WITH_ORACLE   - allow authentication via Oracle (NOT TESTED!)
# WITH_VALIAS   - enable valias processing
# WITHOUT_ROAMING - disallow roaming users
# WITH_IP_ALIAS - enables IP aliasing
# WITH_QMAIL_EXT - enables qmail-like user-* address extesions processing
# WITHOUT_FILE_LOCKING - disable file locking
# WITH_FILE_SYNC - enables immediate synching (may decrease performance)
# WITHOUT_USERS_BIG_DIR - disables using big directories for users
# WITHOUT_SEEKABLE - disables vdelivermail's attempt to make its input seekable
# WITH_DOMAIN_QUOTAS	- enable domain quotas
# WITH_SPAMASSASSIN	- enable SpamAssassin checks before Maildir delivery
#
# Set these to the values you'd prefer
#
# RELAYCLEAR    - time in minutes before clearing relay hole (requires roaming)
# SPAM_THRESHOLD - minimum score required to delete spam messages (requires spamassassin)
# DEFAULT_DOMAIN - default domain for non-vhost lookups
# WITH_SINGLE_DOMAIN - optimize for a site with many users in a single domain
# LOGLEVEL	- n - no logging, y - log all,
#                 e - log errors, p - log passwords in errors,
#		  v - verbose success and errors with passwords
# WITHOUT_AUTH_LOG - disables authentication logging
# WITH_MYSQL_LOG - enable logging to a MySQL database
# WITH_PGSQL_LOG - enable logging to a PostgreSQL database
# QMAIL_PREFIX   - location of qmail directory
# PREFIX	- installation area for vpopmail (see comment below)
# VCHKPW_GID	- the group ID of the new vchkpw group (89)
# VPOPMAIL_UID	- the user ID of the new vpopmail user (89)
#
# MySQL database configuration options
#
# WITH_MYSQL_SERVER - the hostname of the MySQL server (localhost)
# WITH_MYSQL_USER - the username for connecting to the MySQL server (root)
# WITH_MYSQL_PASSWD - the password for connecting to the MySQL server (secret)
# WITH_MYSQL_DB - the name of the MySQL database to use (vpopmail)
# The server, user and password variables may be defined separately
# for read and update access, allowing you to set up a less-priviledged
# MySQL connection account with read-only access, and another one which
# is used for administrative purposes:
# WITH_MYSQL_READ_SERVER, WITH_MYSQL_READ_USER, WITH_MYSQL_READ_PASSWD
# WITH_MYSQL_UPDATE_SERVER, WITH_MYSQL_UPDATE_USER, WITH_MYSQL_UPDATE_PASSWD
# Those variables, if defined, override WITH_MYSQL_{SERVER,USER,PASSWD}
#
# PostgreSQL database configuration options
#
# WITH_PGSQL_USER - the username for connecting to the PostgreSQL server (postgres)
# WITH_PGSQL_DB - the name of the PostgreSQL database to use (vpopmail)
#
# Oracle database configuration options
#
# WARNING: This is NOT TESTED, not in the least.
# Please report any success or failure to the port maintainer,
# Peter Pentchev <roam@FreeBSD.org>
#
# WITH_ORACLE_PROC - the name of the Oracle Pro-C precompiler, default 'proc'
# WITH_ORACLE_SERVICE - the Oracle service name (jimmy)
# WITH_ORACLE_USER - the username for connecting to the Oracle server (system)
# WITH_ORACLE_PASSWD - the password for connecting to the Oracle server (manager)
# WITH_ORACLE_DB  - the name of the Oracle database to connect to (orcl1)
# WITH_ORACLE_HOME - the Oracle installation directory (/export/home/oracle)
#
# Sybase database configuration options
#
# WARNING: This is NOT TESTED, not in the least.
# Please report any success or failure to the port maintainer,
# Peter Pentchev <roam@FreeBSD.org>
#
# WITH_SYBASE_SERVER - the Sybase server name (empty)
# WITH_SYBASE_USER - the username for connecting to the Sybase server (sa)
# WITH_SYBASE_PASSWD - the password for connecting to the Sybase server (empty)
# WITH_SYBASE_APP - the app for connecting to the Sybase server (vpopmail)
# WITH_SYBASE_DB  - the name of the Sybase database to connect to (vpopmail)
#

RELAYCLEAR?=	30
SPAM_THRESHOLD?=15
LOGLEVEL?=	y

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-auth-module=mysql \
			--enable-incdir=${LOCALBASE}/include/mysql \
			--enable-libdir=${LOCALBASE}/lib/mysql
.if defined(WITH_MYSQL_REPLICATION)
CONFIGURE_ARGS+=	--enable-mysql-replication
.endif
.if defined(WITH_MYSQL_LOG)
CONFIGURE_ARGS+=	--enable-mysql-logging
.endif
.if defined(WITH_MYSQL_LIMITS)
CONFIGURE_ARGS+=	--enable-mysql-limits
.endif

WITH_MYSQL_SERVER?=		localhost
WITH_MYSQL_READ_SERVER?=	${WITH_MYSQL_SERVER}
WITH_MYSQL_UPDATE_SERVER?=	${WITH_MYSQL_SERVER}
WITH_MYSQL_USER?=		vpopmail
WITH_MYSQL_READ_USER?=		${WITH_MYSQL_USER}
WITH_MYSQL_UPDATE_USER?=	${WITH_MYSQL_USER}
WITH_MYSQL_PASSWD?=		secret
WITH_MYSQL_READ_PASSWD?=	${WITH_MYSQL_PASSWD}
WITH_MYSQL_UPDATE_PASSWD?=	${WITH_MYSQL_PASSWD}
WITH_MYSQL_DB?=			vpopmail
.endif

.if defined(WITH_POSTGRESQL)
WITH_PGSQL=	yes
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-auth-module=pgsql

.if defined(WITH_PGSQL_LOG)
CONFIGURE_ARGS+=	--enable-pgsql-logging
.endif
.endif

.include <bsd.port.pre.mk>

# Uncomment this, or set PREFIX to /home if you have an existing
# vpopmail install with the vpopmail users' home directory set to
# /home/vpopmail - package rules dictate we default to /usr/local/vpopmail
#
#PREFIX?=	/home

# End of user-configurable variables

#
# Some suggestions from Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#

CONFIGURE_ARGS+=	--enable-logging=${LOGLEVEL}

.if defined(WITH_PASSWD)
CONFIGURE_ARGS+=	--enable-passwd
.endif

.if defined(WITHOUT_MD5_PASSWORDS)
CONFIGURE_ARGS+=	--disable-md5-passwords
.endif

.if defined(WITH_APOP)
BROKEN=		"The WITH_APOP option is deprecated; set WITH_CLEAR_PASSWD instead, APOP will just work"
.endif

.if defined(WITH_VALIAS)
CONFIGURE_ARGS+=	--enable-valias
.endif

.if !defined(WITHOUT_ROAMING)
CONFIGURE_ARGS+=	--enable-roaming-users \
			--enable-relay-clear-minutes=${RELAYCLEAR}
.endif

.if !defined(WITH_CLEAR_PASSWD)
CONFIGURE_ARGS+=	--disable-clear-passwd
.endif

.if defined(WITH_LEARN_PASSWORDS)
CONFIGURE_ARGS+=	--enable-learn-passwords
.endif

.if defined(WITH_SYBASE)
CONFIGURE_ARGS+=	--enable-auth-module=sybase
.endif

.if defined(WITH_ORACLE)
WITH_ORACLE_PROC?=	proc
CONFIGURE_ARGS+=	--enable-auth-module=oracle
.endif

.if defined(WITH_SINGLE_DOMAIN)
CONFIGURE_ARGS+=	--disable-many-domains
.endif

.if defined(WITH_IP_ALIAS)
CONFIGURE_ARGS+=	--enable-ip-alias-domains
.endif

.if defined(WITH_QMAIL_EXT)
CONFIGURE_ARGS+=	--enable-qmail-ext
.endif

.if defined(WITHOUT_FILE_LOCKING)
CONFIGURE_ARGS+=	--disable-file-locking
.endif

.if defined(WITH_FILE_SYNC)
CONFIGURE_ARGS+=	--enable-file-sync
.endif

.if defined(WITHOUT_AUTH_LOG)
CONFIGURE_ARGS+=	--disable-auth-logging
.endif

.if defined(WITHOUT_USERS_BIG_DIR)
CONFIGURE_ARGS+=	--disable-users-big-dir
.endif

.if defined(WITHOUT_SEEKABLE)
CONFIGURE_ARGS+=	--disable-make-seekable
.endif

.if defined(WITH_DOMAIN_QUOTAS)
CONFIGURE_ARGS+=	--enable-domainquotas
.endif

.if defined(WITH_SPAMASSASSIN)
BUILD_DEPENDS+=		spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
CONFIGURE_ARGS+=	--enable-spamassassin=${LOCALBASE}/bin/spamc \
			--enable-spam-threshold=${SPAM_THRESHOLD}
.endif

#
# This port doesn't honour PREFIX, it honours vpopmail's home directory.
# Since we create vpopmail if it doesn't exist, we set it so that it
# does honour PREFIX. -- nbm
#

pre-configure:
	@PKG_PREFIX=${PREFIX}/vpopmail ${PERL5} ${PKGINSTALL}
.if defined(WITH_PGSQL)
.if defined(WITH_PGSQL_DB)
	${REINPLACE_CMD} -E -e "s/(#define DB.*)vpopmail(.*)/\1${WITH_PGSQL_DB}\2/" ${WRKSRC}/vpgsql.h
.endif
.if defined(WITH_PGSQL_USER)
	${REINPLACE_CMD} -E -e "s/(#define PG_CONNECT.*)postgres(.*)/\1${WITH_PGSQL_USER}\2/" ${WRKSRC}/vpgsql.h
.endif
.endif
.if defined(WITH_ORACLE)
.if defined(WITH_ORACLE_SERVICE)
	${REINPLACE_CMD} -E -e "s/(#define ORACLE_SERVICE.*)jimmy(.*)/\1${WITH_ORACLE_SERVICE}\2/" ${WRKSRC}/voracle.h
.endif
.if defined(WITH_ORACLE_USER)
	${REINPLACE_CMD} -E -e "s/(#define ORACLE_USER.*)system(.*)/\1${WITH_ORACLE_USER}\2/" ${WRKSRC}/voracle.h
.endif
.if defined(WITH_ORACLE_PASSWD)
	${REINPLACE_CMD} -E -e "s/(#define ORACLE_PASSWD.*)manager(.*)/\1${WITH_ORACLE_PASSWD}\2/" ${WRKSRC}/voracle.h
.endif
.if defined(WITH_ORACLE_HOME)
	${REINPLACE_CMD} -E -e "s@(#define ORACLE_HOME.*)/export/home/oracle(.*)@\1${WITH_ORACLE_HOME}\2@" ${WRKSRC}/voracle.h
.endif
.if defined(WITH_ORACLE_DB)
	${REINPLACE_CMD} -E -e "s/(#define ORACLE_DATABASE.*)orcl1(.*)/\1${WITH_ORACLE_DB}\2/" ${WRKSRC}/voracle.h
.endif
	cd ${WRKSRC} && ${WITH_ORACLE_PROC} voracle.pc
.endif
.if defined(WITH_SYBASE)
.if defined(WITH_SYBASE_SERVER)
	${REINPLACE_CMD} -E -e "s/(#define SYBASE_SERVER.*)\"\"(.*)/\1\"${WITH_SYBASE_SERVER}\"\2/" ${WRKSRC}/vsybase.h
.endif
.if defined(WITH_SYBASE_USER)
	${REINPLACE_CMD} -E -e "s/(#define SYBASE_USER.*)sa(.*)/\1${WITH_SYBASE_USER}\2/" ${WRKSRC}/vsybase.h
.endif
.if defined(WITH_SYBASE_PASSWD)
	${REINPLACE_CMD} -E -e "s/(#define SYBASE_PASSWD.*)\"\"(.*)/\1\"${WITH_SYBASE_PASSWD}\"\2/" ${WRKSRC}/vsybase.h
.endif
.if defined(WITH_SYBASE_APP)
	${REINPLACE_CMD} -E -e "s@(#define SYBASE_APP.*)vpopmail(.*)@\1${WITH_SYBASE_APP}\2@" ${WRKSRC}/vsybase.h
.endif
.if defined(WITH_SYBASE_DB)
	${REINPLACE_CMD} -E -e "s/(#define SYBASE_DATABASE.*)vpopmail(.*)/\1${WITH_SYBASE_DB}\2/" ${WRKSRC}/vsybase.h
.endif
.endif
	${MKDIR} ${VCFGDIR}

post-install:
	${MKDIR} ${PREFIX}/vpopmail/etc
	if [ ! -e "${PREFIX}/vpopmail/etc/tcp.smtp" ]; then \
		if [ -e "${VCFGDIR}/tcp.smtp" ]; then \
			${INSTALL_DATA} ${VCFGDIR}/tcp.smtp ${PREFIX}/vpopmail/etc/tcp.smtp-dist; \
		else \
			${TOUCH} ${PREFIX}/vpopmail/etc/tcp.smtp-dist; \
		fi; \
		${CP} -p ${PREFIX}/vpopmail/etc/tcp.smtp-dist ${PREFIX}/vpopmail/etc/tcp.smtp; \
	fi
.if defined(DEFAULT_DOMAIN)
	${ECHO_CMD} ${DEFAULT_DOMAIN} > ${PREFIX}/vpopmail/etc/defaultdomain
.endif
.if defined(WITH_MYSQL)
	${ECHO_CMD} "${WITH_MYSQL_READ_SERVER}|0|${WITH_MYSQL_READ_USER}|${WITH_MYSQL_READ_PASSWD}|${WITH_MYSQL_DB}" \
		>> ${PREFIX}/vpopmail/etc/vpopmail.mysql
	${ECHO_CMD} "${WITH_MYSQL_UPDATE_SERVER}|0|${WITH_MYSQL_UPDATE_USER}|${WITH_MYSQL_UPDATE_PASSWD}|${WITH_MYSQL_DB}" \
		>> ${PREFIX}/vpopmail/etc/vpopmail.mysql
.endif
	${CHOWN} -R vpopmail:vchkpw ${PREFIX}/vpopmail/bin/ ${PREFIX}/vpopmail/etc/
.if defined(WITH_SPAMASSASSIN)
	${ECHO_CMD} "***********************************************************************"
	${ECHO_CMD} "Now you should add the following options to your spamd.sh startup file:"
	${ECHO_CMD} "-v -u vpopmail"
	${ECHO_CMD} "***********************************************************************"
.endif

.include <bsd.port.post.mk>
