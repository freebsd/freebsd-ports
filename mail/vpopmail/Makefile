PORTNAME=	vpopmail
PORTVERSION=	5.4.33
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy virtual domain and authentication package for use with qmail
WWW=		https://inter7.com/vpopmail/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/bin/tcprules:sysutils/ucspi-tcp
RUN_DEPENDS=	${LOCALBASE}/bin/tcprules:sysutils/ucspi-tcp

USES=		dos2unix fakeroot gmake qmail
DOS2UNIX_FILES=	doc/README.vpopmaild

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-logging=${LOGLEVEL} \
		--enable-non-root-build \
		--enable-qmaildir=${QMAIL_PREFIX} \
		--enable-tcprules-prog=${LOCALBASE}/bin/tcprules \
		--enable-tcpserver-file=${VPOPMAIL_DIR}/etc/tcp.smtp \
		--enable-vpopgroup=nobody \
		--enable-vpopuser=nobody
CONFIGURE_ENV+=	ACLOCAL=true \
		AUTOCONF=true \
		AUTOHEADER=true \
		AUTOMAKE=true \
		VCFGDIR="${VCFGDIR}"

INSTALL_TARGET=	install-strip

CONFLICTS=	vpopmail-devel-5.*

PATCH_STRIP=	-p1

USERS=		vpopmail
GROUPS=		vchkpw

OPTIONS_DEFINE=		AUTH_LOG CLEAR_PASSWD DOCS DOMAIN_QUOTAS FILE_LOCKING \
			FILE_SYNC IP_ALIAS LEARN_PASSWORDS MAILDROP \
			MD5_PASSWORDS MYSQL_LIMITS MYSQL_REPLICATION \
			ONCHANGE_SCRIPT PASSWD QMAIL_EXT ROAMING SEEKABLE \
			SINGLE_DOMAIN SMTP_AUTH_PATCH SPAMASSASSIN SPAMFOLDER \
			SQL_LOG SQL_LOG_TRIM SUID_VCHKPW USERS_BIG_DIR VALIAS
OPTIONS_DEFAULT=	AUTH_LOG CDB FILE_LOCKING MD5_PASSWORDS ROAMING \
			SEEKABLE USERS_BIG_DIR
OPTIONS_SINGLE=		AUTH
OPTIONS_SINGLE_AUTH=	CDB LDAP MYSQL ORACLE PGSQL SYBASE
OPTIONS_SUB=		yes

AUTH_LOG_DESC=		Log auth attempts when using a DB
CDB_DESC=		Auth via CDB
CLEAR_PASSWD_DESC=	Store passwords in plaintext
DOMAIN_QUOTAS_DESC=	Domain quotas support
FILE_LOCKING_DESC=	file locking support
FILE_SYNC_DESC=		fsync support (decreases performance)
IP_ALIAS_DESC=		IP alias support
LDAP_DESC=		Auth via LDAP
LEARN_PASSWORDS_DESC=	Learn passwords during POP auth
MAILDROP_DESC=		Maildrop MDA support
MD5_PASSWORDS_DESC=	Store passwords in MD5 format
MYSQL_DESC=		Auth via MySQL
MYSQL_LIMITS_DESC=	MySQL mailbox limitations support
MYSQL_REPLICATION_DESC=	MySQL database replication support
ONCHANGE_SCRIPT_DESC=	vpopmail/etc/onchange script support
ORACLE_DESC=		Auth via Oracle
PASSWD_DESC=		/etc/passwd account support
PGSQL_DESC=		Auth via PostgreSQL
QMAIL_EXT_DESC=		qmail-like user-* address support
ROAMING_DESC=		roaming users support
SEEKABLE_DESC=		Make input to vdelivermail seekable
SINGLE_DOMAIN_DESC=	Optimize for a single domain setup
SMTP_AUTH_PATCH_DESC=	Swap Challenge/Response for CRAM-MD5
SPAMASSASSIN_DESC=	SpamAssassin support
SPAMFOLDER_DESC=	Move spam to Junk (requires SA)
SQL_LOG_DESC=		Log to selected SQL database
SQL_LOG_TRIM_DESC=	Trim logs of deleted users/domains
SUID_VCHKPW_DESC=	Set vchkpw setugid vpopmail:vchkpw
SYBASE_DESC=		Auth via Sybase
USERS_BIG_DIR_DESC=	Hashing user directories (BIGDIR)
VALIAS_DESC=		Store aliases in DB instead of .qmail files

# Compatibility with older KNOB, correctly will enable if set,
# but be unset if unselected in the 'config' dialog
.if defined(WITH_MYSQL_LOG)
PORT_OPTIONS+=	SQL_LOG
.endif
.if defined(WITH_PGSQL_LOG)
PORT_OPTIONS+=	SQL_LOG
.endif
.if defined(WITH_POSTGRESQL)
PORT_OPTIONS+=	PGSQL
.endif
.if defined(WITH_SQL_LOG_REMOVE_DELETED)
PORT_OPTIONS+=	SQL_LOG_TRIM
.endif

AUTH_LOG_CONFIGURE_OFF=		--disable-auth-logging
CLEAR_PASSWD_CONFIGURE_OFF=	--disable-clear-passwd
DOMAIN_QUOTAS_CONFIGURE_ON=	--enable-domainquotas=y
DOMAIN_QUOTAS_CONFIGURE_OFF=	--enable-domainquotas=n
FILE_LOCKING_CONFIGURE_OFF=	--disable-file-locking
FILE_SYNC_CONFIGURE_ON=		--enable-file-sync
IP_ALIAS_CONFIGURE_ON=		--enable-ip-alias-domains
LDAP_CONFIGURE_ON=		--enable-auth-module=ldap
LEARN_PASSWORDS_CONFIGURE_ON=	--enable-learn-passwords
MAILDROP_BUILD_DEPENDS=		maildrop:${MAILDROP_PORT}
MAILDROP_RUN_DEPENDS=		maildrop:${MAILDROP_PORT}
MAILDROP_CONFIGURE_ON=		--enable-maildrop-prog=${LOCALBASE}/bin/maildrop \
				--enable-maildrop=y
MAILDROP_CONFIGURE_OFF=		--enable-maildrop=n
MD5_PASSWORDS_CONFIGURE_OFF=	--disable-md5-passwords
MYSQL_CONFIGURE_ON=		--enable-auth-module=mysql \
				--enable-incdir=${LOCALBASE}/include/mysql \
				--enable-libdir=${LOCALBASE}/lib/mysql
MYSQL_CFLAGS=			-fcommon
MYSQL_VARS=			IGNORE_WITH_MYSQL="105m 106m 1011m 81"
MYSQL_LIMITS_CONFIGURE_ON=	--enable-mysql-limits
MYSQL_REPLICATION_CONFIGURE_ON=	--enable-mysql-replication
ONCHANGE_SCRIPT_CONFIGURE_ON=	--enable-onchange-script
ORACLE_CONFIGURE_ON=		--enable-auth-module=oracle
PASSWD_CONFIGURE_ON=		--enable-passwd
PGSQL_CONFIGURE_ON=		--enable-auth-module=pgsql
QMAIL_EXT_CONFIGURE_ON=		--enable-qmail-ext
ROAMING_CONFIGURE_ON=		--enable-relay-clear-minutes=${RELAYCLEAR} \
				--enable-roaming-users
SEEKABLE_CONFIGURE_OFF=		--disable-make-seekable
SINGLE_DOMAIN_CONFIGURE_ON=	--disable-many-domains
SPAMASSASSIN_BUILD_DEPENDS=	spamc:mail/spamassassin
SPAMASSASSIN_RUN_DEPENDS=	spamc:mail/spamassassin
SPAMASSASSIN_CONFIGURE_ON=	--enable-spam-threshold=${SPAM_THRESHOLD} \
				--enable-spamassassin \
				--enable-spamc-prog=${LOCALBASE}/bin/spamc
SPAMFOLDER_CONFIGURE_ON=	--enable-spam-junkfolder
SQL_LOG_CONFIGURE_ON=		--enable-sql-logging
SYBASE_CONFIGURE_ON=		--enable-auth-module=sybase
USERS_BIG_DIR_CONFIGURE_OFF=	--disable-users-big-dir
VALIAS_CONFIGURE_ON=		--enable-valias

VCFGDIR?=	${WRKDIR}/vcfg
VCFGFILES?=	inc_deps lib_deps tcp.smtp

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUID_VCHKPW}
VCHKPW_MODE=	"6711"
.endif
PLIST_SUB+=	VCHKPW_MODE="${VCHKPW_MODE}"

# PostgreSQL database configuration options
#
# WITH_PGSQL_USER - the username for connecting to the PostgreSQL server (postgres)
# WITH_PGSQL_DB - the name of the PostgreSQL database to use (vpopmail)
#
# Oracle database configuration options
#
# WARNING: This is NOT TESTED, not in the least.
# Please report any success or failure to the port maintainer
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
# Please report any success or failure to the port maintainer
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
# Please report any success or failure to the port maintainer
#
# WITH_COURIER_IMAPLOGIN - the path to the imaplogin program
# WITH_COURIER_IMAPD - the path to the imapd program

# User-configurable variables
#
# ONCHANGE_SCRIPT	- see README.onchange
# MAILDROP		- see README.maildrop
#
# Define these to change from the default behaviour
#
# MAILDROP_PORT		- the port that provides the bin/maildrop program
#
# Set these to the values you'd prefer
#
# RELAYCLEAR    - time in minutes before clearing relay hole (requires roaming)
# SPAM_THRESHOLD - minimum score required to delete spam messages (requires spamassassin)
# LOGLEVEL	- n - no logging, y - log all,
#                 e - log errors, p - log passwords in errors,
#		  v - verbose success and errors with passwords
# QMAIL_PREFIX  - location of qmail directory
# VPOPMAIL_DIR	- installation area for vpopmail (see comment below)
#
#
RELAYCLEAR?=			30
SPAM_THRESHOLD?=		15
LOGLEVEL?=			y
MAILDROP_PORT?=			mail/maildrop
WITH_COURIER_IMAPLOGIN?=	${LOCALBASE}/sbin/imaplogin
WITH_VPOPMAIL_AUTHVCHKPW?=	${VPOPMAIL_DIR}/bin/authvchkpw
WITH_COURIER_IMAPD?=		${LOCALBASE}/bin/imapd
WITH_ORACLE_PROC?=		proc
VPOPMAIL_DIR?=			${PREFIX}/vpopmail

# Uncomment this, or set PREFIX to /home if you have an existing
# vpopmail install with the vpopmail users' home directory set to
# /home/vpopmail - package rules dictate we default to LOCALBASE/vpopmail
#
#PREFIX?=	/home

# End of user-configurable variables

.if ${PORT_OPTIONS:MLDAP}
USES+=		ldap
LDAP_FILES=	${WRKSRC}/doc/README.ldap ${WRKSRC}/ldap/nsswitch.conf \
		${WRKSRC}/ldap/pam_ldap.conf ${WRKSRC}/ldap/pam_ldap.secret \
		${WRKSRC}/ldap/qmailUser.schema ${WRKSRC}/ldap/slapd.conf \
		${WRKSRC}/ldap/vpopmail.ldif
.endif

.if ${PORT_OPTIONS:MMYSQL}
USES+=		mysql

.if defined(WITH_MYSQL_USER) || defined(WITH_MYSQL_READ_USER) || \
	defined(WITH_MYSQL_UPDATE_USER)
BROKEN_MYSQL_PARAMS=	true
.endif
.if defined(WITH_MYSQL_SERVER) || defined(WITH_MYSQL_READ_SERVER) || \
	defined(WITH_MYSQL_UPDATE_SERVER)
BROKEN_MYSQL_PARAMS=	true
.endif
.if defined(WITH_MYSQL_PASSWD) || defined(WITH_MYSQL_READ_PASSWD) || \
	defined(WITH_MYSQL_UPDATE_PASSWD)
BROKEN_MYSQL_PARAMS=	true
.endif
.if defined(WITH_MYSQL_DB)
BROKEN_MYSQL_PARAMS=	true
.endif
.if defined(BROKEN_MYSQL_PARAMS)
BROKEN=			The MySQL connection parameters are no longer setup at compile time - please edit the ${VPOPMAIL_DIR}/etc/vpopmail.mysql file instead
.endif
.endif

.if defined(DEFAULT_DOMAIN)
BROKEN=		The default vpopmail domain is no longer setup at compile time - please edit the ${VPOPMAIL_DIR}/etc/defaultdomain file instead
.endif

.if defined(WITH_APOP)
BROKEN=		The WITH_APOP option is deprecated; set WITH_CLEAR_PASSWD instead, APOP will just work
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
.endif

.if ${PORT_OPTIONS:MSQL_LOG_TRIM}
EXTRA_PATCHES+=	${FILESDIR}/sql-remove-deleted.patch
.endif

.if ${PORT_OPTIONS:MSMTP_AUTH_PATCH}
EXTRA_PATCHES+=	${FILESDIR}/vchkpw-smtp-auth.patch
.endif

.if ${PORT_OPTIONS:MMAILDROP}
MAILDROP_FILES=	${WRKSRC}/maildrop/maildroprc.v1 \
		${WRKSRC}/maildrop/maildroprc.v2
.endif

.if empty(PORT_OPTIONS:MDOCS)
EXTRA_PATCHES+=	${FILESDIR}/Makefile.in-noportdocs.patch
.endif

#
# Some suggestions from Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#
#
DOCS=		README README.activedirectory README.filelocking \
		README.ipaliasdomains README.ldap README.maildrop README.mysql \
		README.onchange README.oracle README.pgsql README.qmail-default \
		README.quotas README.roamingusers README.spamassassin \
		README.sybase README.vdelivermail README.vlimits \
		README.vpopmaild README.vpopmaild README.vqmaillocal UPGRADE

#
# This port doesn't honour PREFIX, it honours vpopmail's home directory.
# Since we create vpopmail if it doesn't exist, we set it so that it
# does honour PREFIX. -- nbm
#

pre-configure:
	${AWK} -F: '/^${USERS}:/ { print $$3 }' ${UID_FILES} > ${WRKSRC}/vpopmail.uid
	${AWK} -F: '/^${USERS}:/ { sub(/\/usr\/local/, "${PREFIX}", $$9); print $$9 }' ${UID_FILES} > ${WRKSRC}/vpopmail.dir
	${AWK} -F: '/^${GROUPS}:/ { print $$3 }' ${GID_FILES} > ${WRKSRC}/vpopmail.gid
.if ${PORT_OPTIONS:MPGSQL}
.if defined(WITH_PGSQL_DB)
	${REINPLACE_CMD} -E -e "s/(#define DB.*)vpopmail(.*)/\1${WITH_PGSQL_DB}\2/" ${WRKSRC}/vpgsql.h
.endif
.if defined(WITH_PGSQL_USER)
	${REINPLACE_CMD} -E -e "s/(#define PG_CONNECT.*)postgres(.*)/\1${WITH_PGSQL_USER}\2/" ${WRKSRC}/vpgsql.h
.endif
.endif
.if ${PORT_OPTIONS:MORACLE}
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
.if ${PORT_OPTIONS:MSYBASE}
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
	${MKDIR} ${STAGEDIR}${VPOPMAIL_DIR}/etc
	if [ -e "${VCFGDIR}/tcp.smtp" ]; then \
	        ${INSTALL_DATA} ${VCFGDIR}/tcp.smtp ${STAGEDIR}${VPOPMAIL_DIR}/etc/tcp.smtp-dist; \
	else \
	        ${TOUCH} ${STAGEDIR}${VPOPMAIL_DIR}/etc/tcp.smtp-dist; \
	fi;
.if ${PORT_OPTIONS:MLDAP}
	@${ECHO_CMD} "# LDAP CONNECTION SETTINGS FOR VPOPMAIL" > ${STAGEDIR}${VPOPMAIL_DIR}/etc/vpopmail.ldap-dist
	@${ECHO_CMD} "# Line format:" >> ${STAGEDIR}${VPOPMAIL_DIR}/etc/vpopmail.ldap-dist
	@${ECHO_CMD} "# host|port|user|password|basedn" >> ${STAGEDIR}${VPOPMAIL_DIR}/etc/vpopmail.ldap-dist
	@${ECHO_CMD} "localhost|389|cn=vpopmailuser, o=vpopmail|vpoppasswd|o=vpopmail" >> ${STAGEDIR}${VPOPMAIL_DIR}/etc/vpopmail.ldap-dist
.endif
.if ${PORT_OPTIONS:MLDAP}
	${MKDIR} ${STAGEDIR}${VPOPMAIL_DIR}/ldap
	${INSTALL_DATA} ${LDAP_FILES} ${STAGEDIR}${VPOPMAIL_DIR}/ldap
.endif
.if ${PORT_OPTIONS:MMAILDROP}
	${MKDIR} ${STAGEDIR}${VPOPMAIL_DIR}/maildrop
	${INSTALL_DATA} ${MAILDROP_FILES} ${STAGEDIR}${VPOPMAIL_DIR}/maildrop
.endif
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${VPOPMAIL_DIR}/doc/
.endif

.include <bsd.port.mk>
