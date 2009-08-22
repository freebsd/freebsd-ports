# New ports collection makefile for: vpopmail
# Date created:		21 Sep 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	vpopmail
PORTVERSION=	5.4.27
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Easy virtual domain and authentication package for use with qmail

BUILD_DEPENDS=	${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp
RUN_DEPENDS=	${LOCALBASE}/bin/tcprules:${PORTSDIR}/sysutils/ucspi-tcp

PATCH_STRIP=	-p1

USE_QMAIL=	yes

CONFLICTS=	vpopmail-devel-5.*

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	YES

VCFGDIR?=	${WRKDIR}/vcfg
VCFGFILES?=	inc_deps lib_deps tcp.smtp

CONFIGURE_ENV+=	VCFGDIR="${VCFGDIR}" \
		AUTOCONF=true ACLOCAL=true AUTOMAKE=true AUTOHEADER=true
CONFIGURE_ARGS=	--enable-qmaildir=${QMAIL_PREFIX} \
		--enable-tcprules-prog=${LOCALBASE}/bin/tcprules \
		--enable-tcpserver-file=${PREFIX}/vpopmail/etc/tcp.smtp \
		--enable-non-root-build

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
# WITH_LDAP     - allow authentication via LDAP
# WITH_VALIAS   - enable valias processing
# WITHOUT_ROAMING - disallow roaming users
# WITH_IP_ALIAS - enables IP aliasing
# WITH_QMAIL_EXT - enables qmail-like user-* address extesions processing
# WITHOUT_FILE_LOCKING - disable file locking
# WITH_FILE_SYNC - enables immediate synching (may decrease performance)
# WITHOUT_USERS_BIG_DIR - disables using big directories for users
# WITHOUT_SEEKABLE - disables vdelivermail's attempt to make its input seekable
# WITH_SPAMASSASSIN	- enable SpamAssassin checks before Maildir delivery
# WITH_SUID_VCHKPW	- set the setuid bit on the vchkpw program
# WITH_SMTP_AUTH_PATCH	- apply an SMTP authentcation fix
# WITH_ONCHANGE_SCRIPT	- enable the use of the $PREFIX/vpopmail/etc/onchange
#                         script, see README.onchange for more information.
# WITHOUT_FPIC		- do not add -fPIC to the C compiler flags
# WITH_MAILDROP		- enable maildrop as an MDA (see README.maildrop)
# MAILDROP_PORT		- the port that provides the bin/maildrop program
#
# Set these to the values you'd prefer
#
# RELAYCLEAR    - time in minutes before clearing relay hole (requires roaming)
# SPAM_THRESHOLD - minimum score required to delete spam messages (requires spamassassin)
# WITH_SPAMFOLDER - move spam messages into Junk folder (requires spamassassin)
# DEFAULT_DOMAIN - default domain for non-vhost lookups
# WITH_SINGLE_DOMAIN - optimize for a site with many users in a single domain
# LOGLEVEL	- n - no logging, y - log all,
#                 e - log errors, p - log passwords in errors,
#		  v - verbose success and errors with passwords
# WITHOUT_AUTH_LOG - disables authentication logging
# WITH_MYSQL_LOG - enable auth logging to a MySQL database [deprecateed]
# WITH_PGSQL_LOG - enable auth logging to a PostgreSQL database [deprecated]
# WITH_SQL_LOG  - enable auth logging to the selected SQL database
# WITH_SQL_LOG_REMOVE_DELETED - remove log entries for deleted users/domains
# QMAIL_PREFIX  - location of qmail directory
# PREFIX	- installation area for vpopmail (see comment below)
# VCHKPW_GID	- the group ID of the new vchkpw group (89)
# VPOPMAIL_UID	- the user ID of the new vpopmail user (89)
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
# Courier IMAP configuration options for authvchkpw
#
# WARNING: This is NOT TESTED, not in the least.
# Please report any success or failure to the port maintainer,
# Peter Pentchev <roam@FreeBSD.org>
#
# WITH_COURIER_IMAPLOGIN - the path to the imaplogin program
# WITH_COURIER_IMAPD - the path to the imapd program

RELAYCLEAR?=	30
SPAM_THRESHOLD?=15
LOGLEVEL?=	y
MAILDROP_PORT?=	mail/maildrop

.if defined(WITH_LDAP)
USE_OPENLDAP=	yes
.if defined(WITH_LDAP_SASL)
WANT_OPENLDAP_SASL=	yes
.endif
CONFIGURE_ARGS+=	--enable-auth-module=ldap
LDAP_FILES=		${WRKSRC}/README.ldap \
			${WRKSRC}/ldap/nsswitch.conf \
			${WRKSRC}/ldap/pam_ldap.conf \
			${WRKSRC}/ldap/pam_ldap.secret \
			${WRKSRC}/ldap/qmailUser.schema \
			${WRKSRC}/ldap/slapd.conf \
			${WRKSRC}/ldap/vpopmail.ldif
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-auth-module=mysql \
			--enable-incdir=${LOCALBASE}/include/mysql \
			--enable-libdir=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
.if defined(WITH_MYSQL_REPLICATION)
CONFIGURE_ARGS+=	--enable-mysql-replication
.endif
.if defined(WITH_MYSQL_LOG)
WITH_SQL_LOG=		yes
.endif
.if defined(WITH_MYSQL_LIMITS)
CONFIGURE_ARGS+=	--enable-mysql-limits
.endif

.if defined(WITH_MYSQL_USER) || defined(WITH_MYSQL_READ_USER) || defined(WITH_MYSQL_UPDATE_USER)
BROKEN_MYSQL_PARAMS=	true
.endif
.if defined(WITH_MYSQL_SERVER) || defined(WITH_MYSQL_READ_SERVER) || defined(WITH_MYSQL_UPDATE_SERVER)
BROKEN_MYSQL_PARAMS=	true
.endif
.if defined(WITH_MYSQL_PASSWD) || defined(WITH_MYSQL_READ_PASSWD) || defined(WITH_MYSQL_UPDATE_PASSWD)
BROKEN_MYSQL_PARAMS=	true
.endif
.if defined(WITH_MYSQL_DB)
BROKEN_MYSQL_PARAMS=	true
.endif
.if defined(BROKEN_MYSQL_PARAMS)
BROKEN=	The MySQL connection parameters are no longer setup at compile time - please edit the ${PREFIX}/vpopmail/etc/vpopmail.mysql file instead
.endif
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(DEFAULT_DOMAIN)
BROKEN=	The default vpopmail domain is no longer setup at compile time - please edit the ${PREFIX}/vpopmail/etc/defaultdomain file instead
.endif

.if defined(WITH_POSTGRESQL)
WITH_PGSQL=	yes
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--enable-auth-module=pgsql

.if defined(WITH_PGSQL_LOG)
WITH_SQL_LOG=		yes
.endif
.endif

.if defined(WITH_SQL_LOG)
CONFIGURE_ARGS+=	--enable-sql-logging
.if defined(WITH_SQL_LOG_REMOVE_DELETED)
EXTRA_PATCHES+=	${FILESDIR}/sql-remove-deleted.patch
.endif
.endif

.if defined(WITH_SMTP_AUTH_PATCH)
EXTRA_PATCHES+=	${FILESDIR}/vchkpw-smtp-auth.patch
.endif

.if defined(WITH_ONCHANGE_SCRIPT)
CONFIGURE_ARGS+=	--enable-onchange-script
.endif

.if defined(WITH_MAILDROP)
CONFIGURE_ARGS+=	--enable-maildrop=y \
			--enable-maildrop-prog=${LOCALBASE}/bin/maildrop
RUN_DEPENDS+=	maildrop:${PORTSDIR}/${MAILDROP_PORT}
MAILDROP_FILES=		${WRKSRC}/maildrop/maildroprc.v1 \
			${WRKSRC}/maildrop/maildroprc.v2
PLIST_SUB+=	MAILDROP=""
.else
CONFIGURE_ARGS+=	--enable-maildrop=n
PLIST_SUB+=	MAILDROP="@comment "
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/Makefile.in-noportdocs.patch
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FPIC) && ( ${ARCH} == "amd64" || ${ARCH} == "ia64" )
CFLAGS+=	-fPIC
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

CONFIGURE_ARGS+=	--enable-logging=${LOGLEVEL}

.if defined(WITH_PASSWD)
CONFIGURE_ARGS+=	--enable-passwd
.endif

.if defined(WITHOUT_MD5_PASSWORDS)
CONFIGURE_ARGS+=	--disable-md5-passwords
.endif

.if defined(WITH_APOP)
BROKEN=		The WITH_APOP option is deprecated; set WITH_CLEAR_PASSWD instead, APOP will just work
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

.if defined(WITH_SPAMASSASSIN)
BUILD_DEPENDS+=		spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
CONFIGURE_ARGS+=	--enable-spamassassin \
			--enable-spamc-prog=${LOCALBASE}/bin/spamc \
			--enable-spam-threshold=${SPAM_THRESHOLD}
.if defined(WITH_SPAMFOLDER)
CONFIGURE_ARGS+=	--enable-spam-junkfolder
.endif
.endif

WITH_COURIER_IMAPLOGIN?=	${LOCALBASE}/sbin/imaplogin
WITH_VPOPMAIL_AUTHVCHKPW?=	${PREFIX}/vpopmail/bin/authvchkpw
WITH_COURIER_IMAPD?=		${LOCALBASE}/bin/imapd

DOCS=		README README.activedirectory README.filelocking \
		README.ipaliasdomains README.ldap README.maildrop \
		README.mysql \
		README.onchange README.oracle README.pgsql \
		README.qmail-default README.quotas \
		README.roamingusers README.spamassassin README.sybase \
		README.vdelivermail README.vlimits \
		README.vpopmaild README.vpopmaild README.vqmaillocal \
		UPGRADE

#
# This port doesn't honour PREFIX, it honours vpopmail's home directory.
# Since we create vpopmail if it doesn't exist, we set it so that it
# does honour PREFIX. -- nbm
#

pre-configure:
	@PKG_PREFIX=${PREFIX} ${PERL5} ${PKGINSTALL}
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
	${REINPLACE_CMD} -E -e "s@(#define PATH_IMAPLOGIN.*)VPOPMAILDIR.*@\1\"${WITH_COURIER_IMAPLOGIN}\"@" ${WRKSRC}/authvchkpw.c
	${REINPLACE_CMD} -E -e "s@(#define PATH_AUTHVCHKPW.*)VPOPMAILDIR.*@\1\"${WITH_VPOPMAIL_AUTHVCHKPW}\"@" ${WRKSRC}/authvchkpw.c
	${REINPLACE_CMD} -E -e "s@(#define PATH_IMAPD.*)VPOPMAILDIR.*@\1\"${WITH_COURIER_IMAPD}\"@" ${WRKSRC}/authvchkpw.c
	${MKDIR} ${VCFGDIR}

post-install:
	${MKDIR} ${PREFIX}/vpopmail/etc
	if [ -e "${VCFGDIR}/tcp.smtp" ]; then \
		${INSTALL_DATA} ${VCFGDIR}/tcp.smtp ${PREFIX}/vpopmail/etc/tcp.smtp-dist; \
	else \
		${TOUCH} ${PREFIX}/vpopmail/etc/tcp.smtp-dist; \
	fi;
	if [ ! -f ${PREFIX}/vpopmail/etc/tcp.smtp ]; then \
		${INSTALL_DATA} ${PREFIX}/vpopmail/etc/tcp.smtp-dist ${PREFIX}/vpopmail/etc/tcp.smtp; \
	fi
	if [ ! -f ${PREFIX}/vpopmail/etc/vlimits.default ]; then \
		${INSTALL_DATA} ${PREFIX}/vpopmail/etc/vlimits.default-dist ${PREFIX}/vpopmail/etc/vlimits.default; \
	fi
.if defined(WITH_MYSQL)
	if [ ! -f ${PREFIX}/vpopmail/etc/vpopmail.mysql ]; then \
		${CP} ${PREFIX}/vpopmail/etc/vpopmail.mysql-dist ${PREFIX}/vpopmail/etc/vpopmail.mysql; \
	fi
.endif
	${TOUCH} ${PREFIX}/vpopmail/etc/defaultdomain
.if defined(WITH_LDAP)
	@${ECHO_CMD} "# LDAP CONNECTION SETTINGS FOR VPOPMAIL" > ${PREFIX}/vpopmail/etc/vpopmail.ldap-dist
	@${ECHO_CMD} "# Line format:" >> ${PREFIX}/vpopmail/etc/vpopmail.ldap-dist
	@${ECHO_CMD} "# host|port|user|password|basedn" >> ${PREFIX}/vpopmail/etc/vpopmail.ldap-dist
	@${ECHO_CMD} "localhost|389|cn=vpopmailuser, o=vpopmail|vpoppasswd|o=vpopmail" >> ${PREFIX}/vpopmail/etc/vpopmail.ldap-dist
	if [ ! -f ${PREFIX}/vpopmail/etc/vpopmail.ldap ]; then \
		${CP} ${PREFIX}/vpopmail/etc/vpopmail.ldap-dist ${PREFIX}/vpopmail/etc/vpopmail.ldap; \
	fi
	@${ECHO_CMD} "You need to specify the LDAP connection settings in the ${PREFIX}/vpopmail/etc/vpopmail.ldap file"
.endif
	${CHOWN} -R vpopmail:vchkpw ${PREFIX}/vpopmail/bin/ ${PREFIX}/vpopmail/etc/
.if defined(WITH_SPAMASSASSIN)
	${ECHO_CMD} "***********************************************************************"
	${ECHO_CMD} "Now you should add the following options to your spamd.sh startup file:"
	${ECHO_CMD} "-v -u vpopmail"
	${ECHO_CMD} "***********************************************************************"
.endif
.if defined(WITH_LDAP)
	${MKDIR} ${PREFIX}/vpopmail/ldap
	${INSTALL_DATA} ${LDAP_FILES} ${PREFIX}/vpopmail/ldap
.endif
.if defined(WITH_MAILDROP)
	${MKDIR} ${PREFIX}/vpopmail/maildrop
	${INSTALL_DATA} ${MAILDROP_FILES} ${PREFIX}/vpopmail/maildrop
.endif
.if defined(WITH_SUID_VCHKPW)
	${CHMOD} ug+s ${PREFIX}/vpopmail/bin/vchkpw
.endif
	@${TOUCH} ${QMAIL_PREFIX}/control/locals
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${PREFIX}/vpopmail/doc/
.endif

.include <bsd.port.post.mk>
