# New ports collection makefile for: vpopmail
# Date created:		21 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vpopmail
PORTVERSION=	5.3.9
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/devel/

FORBIDDEN=	'Checksum mismatch, new features investigated'

MAINTAINER=	roam@FreeBSD.org

BUILD_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp
RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail \
		${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_REINPLACE=	YES

VCFGDIR?=	${WRKDIR}/vcfg
VCFGFILES?=	inc_deps lib_deps tcp.smtp

CONFIGURE_ENV+=	VCFGDIR="${VCFGDIR}"
CONFIGURE_ARGS=	--enable-qmaildir=${QMAIL_DIR} \
		--enable-tcprules-bin=${LOCALBASE}/bin/tcprules \
		--enable-tcpserver-file=${PREFIX}/vpopmail/etc/tcp.smtp

#
# User-configurable variables
#
# Define these to change from the default behaviour
#
# WITH_PASSWD   - allow authentication off /etc/passwd
# WITHOUT_MD5_PASSWORDS - store encrypted passwords in MD5 format
# WITH_MYSQL	- allow authentitation via mysql
# WITH_MYSQL_LARGE_SITE - enables large site layout
# WITH_MYSQL_REPLICATION - enables MySQL database replication
# WITH_SYBASE   - allow authentication via Sybase (NOT TESTED!)
# WITH_ORACLE   - allow authentication via Oracle (NOT TESTED!)
# WITH_CLEAR_PASSWD - store passwords in plaintext into the MySQL db
# WITH_VALIAS   - enable valias processing
# WITHOUT_ROAMING - disallow roaming users
# WITH_IP_ALIAS - enables IP aliasing
# WITH_DELIVER_FILTER - enables the experimental vdelivermail filter
# WITH_QMAIL_EXT - enables qmail-like user-* address extesions processing
# WITHOUT_FILE_LOCKING - disable file locking
# WITH_FILE_SYNC - enables immediate synching (may decrease performance)
# WITHOUT_USERS_BIG_DIR - disables using big directories for users
# WITHOUT_SEEKABLE - disables vdelivermail's attempt to make its input seekable
#
# Set these to the values you'd prefer
#
# HARDQUOTA     - size of hard quota, or 'n' for no hard quota
# RELAYCLEAR    - time in minutes before clearing relay hole (requires roaming)
# DEFAULT_DOMAIN - default domain for non-vhost lookups
# WITH_SINGLE_DOMAIN - optimize for a site with many users in a single domain
# LOGLEVEL	- n - no logging, y - log all,
#                 e - log errors, p - log passwords in errors
# WITHOUT_AUTH_LOG - disables authentication logging
# WITH_MYSQL_LOG - enable logging to a MySQL database
# QMAIL_DIR     - location of qmail directory
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

HARDQUOTA?=	10000000
RELAYCLEAR?=	30
LOGLEVEL?=	y

.if exists(${LOCALBASE}/qmail/bin/qmail-send)
QMAIL_DIR?=	${LOCALBASE}/qmail
.else
QMAIL_DIR?=	/var/qmail
.endif

# Uncomment this, or set PREFIX to /home if you have an existing
# vpopmail install with the vpopmail users' home directory set to
# /home/vpopmail - package rules dictate we default to /usr/local/vpopmail
#
#PREFIX?=	/home

# End of user-configurable variables

#
# Some suggestions from Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#

CONFIGURE_ARGS+=	--enable-defaultquota=${HARDQUOTA} \
			--enable-logging=${LOGLEVEL}

.if defined(WITH_PASSWD)
CONFIGURE_ARGS+=	--enable-passwd=y
.endif

.if defined(WITHOUT_MD5_PASSWORDS)
CONFIGURE_ARGS+=	--enable-md5-passwords=n
.endif

.if defined(WITH_APOP)
BROKEN=		"The WITH_APOP option is deprecated; set WITH_CLEAR_PASSWD instead, APOP will just work"
.endif

.if defined(WITH_VALIAS)
CONFIGURE_ARGS+=	--enable-valias=y
.endif

.if defined(WITH_SQWEBMAIL)
CONFIGURE_ARGS+=	--enable-sqwebmail-pass=y
.endif

.if !defined(WITHOUT_ROAMING)
CONFIGURE_ARGS+=	--enable-roaming-users=y \
			--enable-relay-clear-minutes=${RELAYCLEAR}
.endif

.if !defined(WITH_CLEAR_PASSWD)
CONFIGURE_ARGS+=	--enable-clear-passwd=n
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=	--enable-mysql=y \
			--enable-sqlincdir=${LOCALBASE}/include/mysql \
			--enable-sqllibdir=${LOCALBASE}/lib/mysql
.if defined(WITH_MYSQL_LARGE_SITE)
CONFIGURE_ARGS+=	--enable-large-site=y
.endif
.if defined(WITH_MYSQL_REPLICATION)
CONFIGURE_ARGS+=	--enable-mysql-replication=y
.endif
.if defined(WITH_MYSQL_LOG)
CONFIGURE_ARGS+=	--enable-mysql-logging=y
.endif

.if defined(WITH_MYSQL_SERVER)
WITH_MYSQL_READ_SERVER?=	${WITH_MYSQL_SERVER}
WITH_MYSQL_UPDATE_SERVER?=	${WITH_MYSQL_SERVER}
.endif
.if defined(WITH_MYSQL_USER)
WITH_MYSQL_READ_USER?=	${WITH_MYSQL_USER}
WITH_MYSQL_UPDATE_USER?=	${WITH_MYSQL_USER}
.endif
.if defined(WITH_MYSQL_PASSWD)
WITH_MYSQL_READ_PASSWD?=	${WITH_MYSQL_PASSWD}
WITH_MYSQL_UPDATE_PASSWD?=	${WITH_MYSQL_PASSWD}
.endif
.endif

.if defined(WITH_SYBASE)
CONFIGURE_ARGS+=	--enable-sybase=y
.endif

.if defined(WITH_ORACLE)
WITH_ORACLE_PROC?=	proc
CONFIGURE_ARGS+=	--enable-oracle=y
.endif

.if defined(DEFAULT_DOMAIN)
CONFIGURE_ARGS+=	--enable-default-domain=${DEFAULT_DOMAIN}
.endif

.if defined(WITH_SINGLE_DOMAIN)
CONFIGURE_ARGS+=	--enable-many-domains=n
.endif

.if defined(WITH_IP_ALIAS)
CONFIGURE_ARGS+=	--enable-ip-alias-domains=y
.endif

.if defined(WITH_DELIVER_FILTER)
CONFIGURE_ARGS+=	--enable-deliver-filter=y
.endif

.if defined(WITH_QMAIL_EXT)
CONFIGURE_ARGS+=	--enable-qmail-ext=y
.endif

.if defined(WITHOUT_FILE_LOCKING)
CONFIGURE_ARGS+=	--enable-file-locking=n
.endif

.if defined(WITH_FILE_SYNC)
CONFIGURE_ARGS+=	--enable-file-sync=y
.endif

.if defined(WITHOUT_AUTH_LOG)
CONFIGURE_ARGS+=	--enable-auth-logging=n
.endif

.if defined(WITHOUT_USERS_BIG_DIR)
CONFIGURE_ARGS+=	--enable-users-big-dir=n
.endif

.if defined(WITHOUT_SEEKABLE)
CONFIGURE_ARGS+=	--enable-make-seekable=n
.endif

# autoconf and automake can remove our patches to the configure scripts.

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e 's,@(ACLOCAL|AUTO(MAKE|CONF|HEADER))@,/usr/bin/true,'

#
# This port doesn't honour PREFIX, it honours vpopmail's home directory.
# Since we create vpopmail if it doesn't exist, we set it so that it
# does honour PREFIX. -- nbm
#

pre-configure:
	@PKG_PREFIX=${PREFIX}/vpopmail ${PERL5} ${PKGINSTALL}
.if defined(WITH_MYSQL)
.if defined(WITH_MYSQL_UPDATE_SERVER)
	${PERL} -pi -e "s/(#define MYSQL_UPDATE_SERVER.*)localhost(.*)/\$$1${WITH_MYSQL_UPDATE_SERVER}\$$2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_READ_SERVER)
	${PERL} -pi -e "s/(#define MYSQL_READ_SERVER.*)localhost(.*)/\$$1${WITH_MYSQL_READ_SERVER}\$$2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_UPDATE_USER)
	${PERL} -pi -e "s/(#define MYSQL_UPDATE_USER.*)root(.*)/\$$1${WITH_MYSQL_UPDATE_USER}\$$2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_READ_USER)
	${PERL} -pi -e "s/(#define MYSQL_READ_USER.*)root(.*)/\$$1${WITH_MYSQL_READ_USER}\$$2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_UPDATE_PASSWD)
	${PERL} -pi -e "s/(#define MYSQL_UPDATE_PASSWD.*)secret(.*)/\$$1${WITH_MYSQL_UPDATE_PASSWD}\$$2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_READ_PASSWD)
	${PERL} -pi -e "s/(#define MYSQL_READ_PASSWD.*)secret(.*)/\$$1${WITH_MYSQL_READ_PASSWD}\$$2/" ${WRKSRC}/vmysql.h
.endif
.if defined(WITH_MYSQL_DB)
	${PERL} -pi -e "s/(#define MYSQL_DATABASE.*)vpopmail(.*)/\$$1${WITH_MYSQL_DB}\$$2/" ${WRKSRC}/vmysql.h
.endif
.endif
.if defined(WITH_ORACLE)
.if defined(WITH_ORACLE_SERVICE)
	${PERL} -pi -e "s/(#define ORACLE_SERVICE.*)jimmy(.*)/\$$1${WITH_ORACLE_SERVICE}\$$2/" ${WRKSRC}/voracle.h
.endif
.if defined(WITH_ORACLE_USER)
	${PERL} -pi -e "s/(#define ORACLE_USER.*)system(.*)/\$$1${WITH_ORACLE_USER}\$$2/" ${WRKSRC}/voracle.h
.endif
.if defined(WITH_ORACLE_PASSWD)
	${PERL} -pi -e "s/(#define ORACLE_PASSWD.*)manager(.*)/\$$1${WITH_ORACLE_PASSWD}\$$2/" ${WRKSRC}/voracle.h
.endif
.if defined(WITH_ORACLE_HOME)
	${PERL} -pi -e "s@(#define ORACLE_HOME.*)/export/home/oracle(.*)@\$$1${WITH_ORACLE_HOME}\$$2@" ${WRKSRC}/voracle.h
.endif
.if defined(WITH_ORACLE_DB)
	${PERL} -pi -e "s/(#define ORACLE_DATABASE.*)orcl1(.*)/\$$1${WITH_ORACLE_DB}\$$2/" ${WRKSRC}/voracle.h
.endif
	cd ${WRKSRC} && ${WITH_ORACLE_PROC} voracle.pc
.endif
.if defined(WITH_SYBASE)
.if defined(WITH_SYBASE_SERVER)
	${PERL} -pi -e "s/(#define SYBASE_SERVER.*)\"\"(.*)/\$$1\"${WITH_SYBASE_SERVER}\"\$$2/" ${WRKSRC}/vsybase.h
.endif
.if defined(WITH_SYBASE_USER)
	${PERL} -pi -e "s/(#define SYBASE_USER.*)sa(.*)/\$$1${WITH_SYBASE_USER}\$$2/" ${WRKSRC}/vsybase.h
.endif
.if defined(WITH_SYBASE_PASSWD)
	${PERL} -pi -e "s/(#define SYBASE_PASSWD.*)\"\"(.*)/\$$1\"${WITH_SYBASE_PASSWD}\"\$$2/" ${WRKSRC}/vsybase.h
.endif
.if defined(WITH_SYBASE_APP)
	${PERL} -pi -e "s@(#define SYBASE_APP.*)vpopmail(.*)@\$$1${WITH_SYBASE_APP}\$$2@" ${WRKSRC}/vsybase.h
.endif
.if defined(WITH_SYBASE_DB)
	${PERL} -pi -e "s/(#define SYBASE_DATABASE.*)vpopmail(.*)/\$$1${WITH_SYBASE_DB}\$$2/" ${WRKSRC}/vsybase.h
.endif
.endif
	${MKDIR} ${VCFGDIR}

post-install:
	${CHMOD} o-rwx ${PREFIX}/vpopmail/bin ${PREFIX}/vpopmail/lib
	${MKDIR} ${PREFIX}/vpopmail/etc
	if [ ! -f "${PREFIX}/vpopmail/etc/tcp.smtp" ]; then \
		if [ -f "${VCFGDIR}/tcp.smtp" ]; then \
			${INSTALL_DATA} ${VCFGDIR}/tcp.smtp ${PREFIX}/vpopmail/etc/; \
		else \
			${TOUCH} ${PREFIX}/vpopmail/etc/tcp.smtp; \
		fi; \
	fi
	${INSTALL_DATA} ${VCFGDIR}/inc_deps ${VCFGDIR}/lib_deps ${PREFIX}/vpopmail/etc/

.include <bsd.port.mk>
