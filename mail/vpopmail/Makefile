# Created by: Neil Blakey-Milner
# $FreeBSD$

PORTNAME=	vpopmail
PORTVERSION=	5.4.33
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy virtual domain and authentication package for use with qmail

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/bin/tcprules:sysutils/ucspi-tcp
RUN_DEPENDS=	${LOCALBASE}/bin/tcprules:sysutils/ucspi-tcp

PATCH_STRIP=	-p1

USES=		qmail gmake fakeroot

CONFLICTS=	vpopmail-devel-5.*

GNU_CONFIGURE=	YES
OPTIONS_SUB=	yes

USERS=		vpopmail
GROUPS=		vchkpw

VCFGDIR?=	${WRKDIR}/vcfg
VCFGFILES?=	inc_deps lib_deps tcp.smtp

CONFIGURE_ENV+=	VCFGDIR="${VCFGDIR}" \
		AUTOCONF=true ACLOCAL=true AUTOMAKE=true AUTOHEADER=true
CONFIGURE_ARGS=	--enable-qmaildir=${QMAIL_PREFIX} \
		--enable-tcprules-prog=${LOCALBASE}/bin/tcprules \
		--enable-tcpserver-file=${VPOPMAIL_DIR}/etc/tcp.smtp \
		--enable-non-root-build \
		--enable-logging=${LOGLEVEL} \
		--enable-vpopuser=nobody \
		--enable-vpopgroup=nobody

OPTIONS_DEFINE=	DOCS \
		PASSWD \
		MD5_PASSWORDS \
		CLEAR_PASSWD \
		LEARN_PASSWORDS \
		MYSQL_REPLICATION \
		MYSQL_LIMITS \
		VALIAS \
		ROAMING \
		IP_ALIAS \
		QMAIL_EXT \
		FILE_LOCKING \
		FILE_SYNC \
		USERS_BIG_DIR \
		SEEKABLE \
		SPAMASSASSIN \
		SUID_VCHKPW \
		SMTP_AUTH_PATCH \
		ONCHANGE_SCRIPT \
		FPIC \
		MAILDROP \
		DOMAIN_QUOTAS \
		SPAMFOLDER \
		SINGLE_DOMAIN \
		AUTH_LOG \
		SQL_LOG \
		SQL_LOG_TRIM
OPTIONS_SINGLE=	AUTH
OPTIONS_SINGLE_AUTH=	CDB MYSQL PGSQL LDAP LDAP_SASL ORACLE SYBASE

OPTIONS_DEFAULT=MD5_PASSWORDS \
		CDB \
		ROAMING \
		FILE_LOCKING \
		USERS_BIG_DIR \
		SEEKABLE \
		FPIC \
		AUTH_LOG

CDB_DESC=			Auth via CDB
PASSWD_DESC=			/etc/passwd account support
MYSQL_DESC=			Auth via MySQL
PGSQL_DESC=			Auth via PostgreSQL
SYBASE_DESC=			Auth via Sybase
MD5_PASSWORDS_DESC=		Store passwords in MD5 format
CLEAR_PASSWD_DESC=		Store passwords in plaintext
LEARN_PASSWORDS_DESC=		Learn passwords during POP auth
MYSQL_REPLICATION_DESC=		MySQL database replication support
MYSQL_LIMITS_DESC=		MySQL mailbox limitations support
ORACLE_DESC=			Auth via Oracle
LDAP_DESC=			Auth via LDAP
LDAP_SASL_DESC=			Auth via LDAP SASL
VALIAS_DESC=			Store aliases in DB instead of .qmail files
ROAMING_DESC=			roaming users support
IP_ALIAS_DESC=			IP alias support
QMAIL_EXT_DESC=			qmail-like user-* address support
FILE_LOCKING_DESC=		file locking support
FILE_SYNC_DESC=			fsync support (decreases performance)
USERS_BIG_DIR_DESC=		Hashing user directories (BIGDIR)
SEEKABLE_DESC=			Make input to vdelivermail seekable
SPAMASSASSIN_DESC=		SpamAssassin support
SUID_VCHKPW_DESC=		Set vchkpw setugid vpopmail:vchkpw
SMTP_AUTH_PATCH_DESC=		Swap Challenge/Response for CRAM-MD5
ONCHANGE_SCRIPT_DESC=		vpopmail/etc/onchange script support
FPIC_DESC=			Compile with -fPIC
MAILDROP_DESC=			Maildrop MDA support
DOMAIN_QUOTAS_DESC=		Domain quotas support
SPAMFOLDER_DESC=		Move spam to Junk (requires SA)
SINGLE_DOMAIN_DESC=		Optimize for a single domain setup
AUTH_LOG_DESC=			Log auth attempts when using a DB
SQL_LOG_DESC=			Log to selected SQL database
SQL_LOG_TRIM_DESC=		Trim logs of deleted users/domains

# Compatibility with older KNOB, correctly will enable if set,
# but be unset if unselected in the 'config' dialog
.if defined(WITH_POSTGRESQL)
PORT_OPTIONS+=	PGSQL
.endif
.if defined(WITH_MYSQL_LOG)
PORT_OPTIONS+=	SQL_LOG
.endif
.if defined(WITH_PGSQL_LOG)
PORT_OPTIONS+=	SQL_LOG
.endif
.if defined(WITH_SQL_LOG_REMOVE_DELETED)
PORT_OPTIONS+=	SQL_LOG_TRIM
.endif

DOMAIN_QUOTAS_CONFIGURE_ON=	--enable-domainquotas=y
DOMAIN_QUOTAS_CONFIGURE_OFF=	--enable-domainquotas=n
PASSWD_CONFIGURE_ON=		--enable-passwd
MD5_PASSWORDS_CONFIGURE_OFF=	--disable-md5-passwords
VALIAS_CONFIGURE_ON=		--enable-valias
CLEAR_PASSWD_CONFIGURE_OFF=	--disable-clear-passwd
LEARN_PASSWORDS_CONFIGURE_ON=	--enable-learn-passwords
LDAP_CONFIGURE_ON=		--enable-auth-module=ldap
ORACLE_CONFIGURE_ON=		--enable-auth-module=oracle
SYBASE_CONFIGURE_ON=		--enable-auth-module=sybase
SINGLE_DOMAIN_CONFIGURE_ON=	--disable-many-domains
IP_ALIAS_CONFIGURE_ON=		--enable-ip-alias-domains
QMAIL_EXT_CONFIGURE_ON=		--enable-qmail-ext
FILE_LOCKING_CONFIGURE_OFF=	--disable-file-locking
FILE_SYNC_CONFIGURE_ON=		--enable-file-sync
AUTH_LOG_CONFIGURE_OFF=		--disable-auth-logging
USERS_BIG_DIR_CONFIGURE_OFF=	--disable-users-big-dir
SEEKABLE_CONFIGURE_OFF=		--disable-make-seekable
ROAMING_CONFIGURE_ON=		--enable-roaming-users \
				--enable-relay-clear-minutes=${RELAYCLEAR}

MYSQL_CONFIGURE_ON=		--enable-auth-module=mysql \
				--enable-incdir=${LOCALBASE}/include/mysql \
				--enable-libdir=${LOCALBASE}/lib/mysql
MYSQL_REPLICATION_CONFIGURE_ON=	--enable-mysql-replication
MYSQL_LIMITS_CONFIGURE_ON=	--enable-mysql-limits

PGSQL_CONFIGURE_ON=		--enable-auth-module=pgsql
SQL_LOG_CONFIGURE_ON=		--enable-sql-logging
ONCHANGE_SCRIPT_CONFIGURE_ON=	--enable-onchange-script
MAILDROP_CONFIGURE_ON=		--enable-maildrop=y \
				--enable-maildrop-prog=${LOCALBASE}/bin/maildrop
MAILDROP_CONFIGURE_OFF=		--enable-maildrop=n

MAILDROP_RUN_DEPENDS=		maildrop:${MAILDROP_PORT}
MAILDROP_BUILD_DEPENDS=		maildrop:${MAILDROP_PORT}

SPAMASSASSIN_CONFIGURE_ON=	--enable-spamassassin \
				--enable-spamc-prog=${LOCALBASE}/bin/spamc \
				--enable-spam-threshold=${SPAM_THRESHOLD}
SPAMASSASSIN_BUILD_DEPENDS=	spamc:mail/spamassassin
SPAMASSASSIN_RUN_DEPENDS=	spamc:mail/spamassassin
SPAMFOLDER_CONFIGURE_ON=	--enable-spam-junkfolder

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUID_VCHKPW}
VCHKPW_MODE="6711"
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
# MAILDROP 		- see README.maildrop
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
RELAYCLEAR?=	30
SPAM_THRESHOLD?=15
LOGLEVEL?=	y
MAILDROP_PORT?=	mail/maildrop
WITH_COURIER_IMAPLOGIN?=	${LOCALBASE}/sbin/imaplogin
WITH_VPOPMAIL_AUTHVCHKPW?=	${VPOPMAIL_DIR}/bin/authvchkpw
WITH_COURIER_IMAPD?=		${LOCALBASE}/bin/imapd
WITH_ORACLE_PROC?=	proc
VPOPMAIL_DIR?=			${PREFIX}/vpopmail

# Uncomment this, or set PREFIX to /home if you have an existing
# vpopmail install with the vpopmail users' home directory set to
# /home/vpopmail - package rules dictate we default to LOCALBASE/vpopmail
#
#PREFIX?=	/home

# End of user-configurable variables

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
.if ${PORT_OPTIONS:MLDAP_SASL}
WANT_OPENLDAP_SASL=	yes
.endif
LDAP_FILES=		${WRKSRC}/doc/README.ldap \
			${WRKSRC}/ldap/nsswitch.conf \
			${WRKSRC}/ldap/pam_ldap.conf \
			${WRKSRC}/ldap/pam_ldap.secret \
			${WRKSRC}/ldap/qmailUser.schema \
			${WRKSRC}/ldap/slapd.conf \
			${WRKSRC}/ldap/vpopmail.ldif
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes

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
BROKEN=	The MySQL connection parameters are no longer setup at compile time - please edit the ${VPOPMAIL_DIR}/etc/vpopmail.mysql file instead
.endif
.endif

.if defined(DEFAULT_DOMAIN)
BROKEN=	The default vpopmail domain is no longer setup at compile time - please edit the ${VPOPMAIL_DIR}/etc/defaultdomain file instead
.endif

.if defined(WITH_APOP)
BROKEN=		The WITH_APOP option is deprecated; set WITH_CLEAR_PASSWD instead, APOP will just work
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES=	pgsql
.endif

.if ${PORT_OPTIONS:MSQL_LOG_TRIM}
EXTRA_PATCHES+=	${FILESDIR}/sql-remove-deleted.patch
.endif

.if ${PORT_OPTIONS:MSMTP_AUTH_PATCH}
EXTRA_PATCHES+=	${FILESDIR}/vchkpw-smtp-auth.patch
.endif

.if ${PORT_OPTIONS:MMAILDROP}
MAILDROP_FILES=		${WRKSRC}/maildrop/maildroprc.v1 \
			${WRKSRC}/maildrop/maildroprc.v2
.endif

.if empty(PORT_OPTIONS:MDOCS)
EXTRA_PATCHES+=	${FILESDIR}/Makefile.in-noportdocs.patch
.endif

.if ${PORT_OPTIONS:MFPIC} && ( ${ARCH} == "amd64" || ${ARCH} == "ia64" )
CFLAGS+=	-fPIC
.endif

#
# Some suggestions from Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#
#
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
