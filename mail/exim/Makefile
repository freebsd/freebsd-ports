# New ports collection makefile for:	exim
# Date created:		23 June 1996
# Whom:			markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	exim
PORTVERSION=	${EXIM_VERSION}+${EXISCAN_VERSION}
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_EXIM}
MASTER_SITE_SUBDIR=	exim4
DISTNAME=	${PORTNAME}-${EXIM_VERSION}
DIST_SUBDIR=	exim

MAINTAINER=	eik@FreeBSD.org
COMMENT?=	High performance MTA for Unix systems on the Internet

.include "options"

.if !defined(WITHOUT_EXISCAN)
PATCH_SITES=	http://duncanthrax.net/%SUBDIR%/
PATCH_SITE_SUBDIR=	exiscan-acl
PATCHFILES=	exiscan-acl-${EXIM_VERSION}-${EXISCAN_VERSION}.patch.bz2
PATCH_DIST_STRIP=	-p1
EXTRA_PATCHES+=	${PATCHDIR}/xpatch-exiscan2
.endif

EXIM_VERSION=	4.41
EXISCAN_VERSION=25

.if !defined(EXIMON_ONLY)
.if defined(PKGNAMESUFFIX)
CONFLICTS+=	${PKGNAMEPREFIX}${PORTNAME}-4.*
.endif
.for suffix in -ldap2 -mysql -postgresql
.if !defined(PKGNAMESUFFIX) || ${PKGNAMESUFFIX} != ${suffix}
CONFLICTS+=	${PKGNAMEPREFIX}${PORTNAME}${suffix}-4.*
.endif
.endfor
.if defined(WITH_EXIMON)
CONFLICTS+=	${PKGNAMEPREFIX}${PORTNAME}-monitor-4.*
.endif
.else
WITH_EXIMON=	yes
.endif

.if defined(WITH_EXIMON)
USE_XLIB=	yes
.endif

USE_BZIP2=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes

.if !defined(WITHOUT_PERL)
USE_PERL5=	yes
.endif

.if !defined(EXIMON_ONLY)
MAN8=		exim.8
.else
NO_INSTALL_MANPAGES=	yes
.endif

PORTDOC_BASE=	ACKNOWLEDGMENTS NOTICE README.UPDATING
PORTDOC_FILES=	ChangeLog Exim3.upgrade Exim4.upgrade NewStuff \
		OptionLists.txt README README.SIEVE dbm.discuss.txt \
		filter.txt pcrepattern.txt pcretest.txt spec.txt

PORT_EXAMPLES=	convert4r3 convert4r4 pcretest transport-filter.pl

DAILY_SCRIPTS=	150.exim-tidydb 460.exim-mail-rejects

PKGINSTALL=	${WRKDIR}/pkg-install

.if defined(NOPORTDOCS) && !defined(EXIMON_ONLY)
PKGMESSAGE=	${WRKDIR}/POST-INSTALL-NOTES
.else
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

MAKE_ENV+=	OSTYPE=${OPSYS} ARCHTYPE=${MACHINE_ARCH} LOCALBASE=${LOCALBASE}
.if defined(EXIMON_ONLY)
MAKE_ENV+=	INSTALL_ARG="eximon eximon.bin"
.endif

EXIM_USER?=	mailnull
EXIM_GROUP?=	mail

LOGDIR?=	/var/log/exim
LOG_FILE_PATH?=	${LOGDIR}/%slog

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%EXIM_USER%%,${EXIM_USER},g' \
		-e 's,%%EXIM_GROUP%%,${EXIM_GROUP},g' \
		-e 's,%%LOGDIR%%,${LOGDIR},g'

PLIST_SUB=	EXIM_VERSION="${EXIM_VERSION}-${PORTREVISION}" \
		EXIM_USER=${EXIM_USER} \
		EXIM_GROUP=${EXIM_GROUP}

# If WITH_EXIMON is defined, the eximon monitor, which requires X,
# will be made a dependency.  Note that using WITH_EXIMON will cause
# XFree86 to be installed if it is not present.
#WITH_EXIMON=	yes

# If WITHOUT_EXISCAN is defined, exim will be built without exiscan
# email content scanner support.
#WITHOUT_EXISCAN=	yes

# Define WITH_TCP_WRAPPERS, WITH_MYSQL, and WITH_PGSQL to link against
# libwrap, libmysqlclient and libpq respectively.  Define
# WITH_SASLAUTHD to enable use of the Cyrus SASL authentication daemon.
# Define WITH_MYSQL_VER to specify a particular version of MySQL to
# use.  Valid values are currently 323, 40 and 41.  Defining WITH_MYSQL_VER
# implies WITH_MYSQL.
#WITH_TCP_WRAPPERS=	yes
#WITH_MYSQL=		yes
#WITH_MYSQL_VER=	40
#WITH_PGSQL=		yes
#WITH_SASLAUTHD=	yes

# As an alternative to WITH_SASLAUTHD, you can define WITH_PWCHECK to
# link against libsasl for SMTP AUTH authentication via the Cyrus SASL
# pwcheck daemon.
################################
# THIS MECHANISM IS DEPRECATED #
################################
#WITH_PWCHECK=		yes

# Define WITHOUT_IPV6 to exclude IPv6 support from the compiled exim
# binary.  Exim compiled with IPv6 support will still operate on
# systems that do not have IPv6 kernel support, so this should not
# be necessary.
#WITHOUT_IPV6=		yes

# Define WITH_OPENLDAP or WITH_OPENLDAP_VER to link against libldap.
# Define WITH_OPENLDAP_VER to specify a particular version of
# OpenLDAP to use. Valid values are currently 21 and 22.
# Defining WITH_OPENLDAP_VER implies WITH_OPENLDAP.
# Exim also supports NETSCAPE and SOLARIS7 lookup types, but no
# client libraries exist for these in the ports tree.
#WITH_OPENLDAP=		yes
#WITH_OPENLDAP_VER=	21

# WITH_BDB_VER is the version of the Berkeley DB library to use, and
# may be 1, which corresponds to version 1.85 in the base system, 4,
# 41 or 42 which depends on the databases/db4[12] ports.
WITH_BDB_VER?=1

# When Exim is decoding MIME "words" in header lines it converts any foreign
# character sets to the one that is set in the headers_charset option.
# The default setting is defined by this setting:
WITH_DEFAULT_CHARSET?=	ISO-8859-1

# The following options may be defined to turn off support for various
# features that this port enables by default.
#
# Do not link against OpenSSL; disables STARTTLS.
#WITHOUT_TLS=	yes
#
# Disable the embedded Perl interpreter, which allows Perl subroutines to
# be called during string expansion.
#WITHOUT_PERL=	yes
#
# Disable built-in Exim support for the PAM, RFC 2195, RFC 2595 and
# Microsoft "Secure Password Authentication" authentication mechanisms,
# used for SMTP AUTH.
#WITHOUT_PAM=			yes
#WITHOUT_AUTH_CRAM_MD5=		yes
#WITHOUT_AUTH_PLAINTEXT=	yes
#WITHOUT_AUTH_SPA=		yes
#
# Enable built-in Exim support for radius (RFC 2865) authentication
#WITH_AUTH_RADIUS=		yes
#
# Disable built-in Exim support for additional mailbox formats.
#WITHOUT_MAILDIR=	yes
#WITHOUT_MAILSTORE=	yes
#WITHOUT_MBX=		yes
#
# Define WITHOUT_CDB, WITHOUT_DNSDB, WITHOUT_DSEARCH, WITHOUT_LSEARCH,
# WITHOUT_NIS and WITHOUT_PASSWD to disable support for CDB-style, DNS-style,
# directory-list, wildcarded-file, NIS and /etc/passwd lookups respectively.
#WITHOUT_CDB=		yes
#WITHOUT_DNSDB=		yes
#WITHOUT_DSEARCH=	yes
#WITHOUT_LSEARCH=	yes
#WITHOUT_NIS=		yes
#WITHOUT_PASSWD=	yes
#
# Disable support for the LMTP (RFC 2033 "SMTP over command pipe")
# transport.
#WITHOUT_LMTP=		yes
#
# Allow alternate configuration files not only in ${PREFIX}/etc/exim
#WITHOUT_ALT_CONFIG_PREFIX=	yes
#
# Include the unsupported patches in ${PATCHDIR}/wishlist-*.patch
#WITH_WISHLIST=		yes
#
# Enable Sender Policy Framework (SPF) checking in exiscan-acl
#
#WITH_SPF=		yes
#
# Enable Sender Rewriting Scheme (SRS)
#
#WITH_SRS=		yes

# You should not need to fiddle with anything below this point.

.if defined(WITH_WISHLIST)
EXTRA_PATCHES+=	`${FIND} ${PATCHDIR} -name 'wishlist-*.patch'`
.endif

.if !defined(WITHOUT_EXISCAN)
PORTDOC_FILES+=	exiscan-acl-examples.txt exiscan-acl-spec.txt
PLIST_SUB+=	EXISCAN_ACL=""
.else
PLIST_SUB+=	EXISCAN_ACL="@comment "
.endif

SEDLIST=	-e 's,XX_PREFIX_XX,${PREFIX},' \
		-e 's,XX_EXIM_USER_XX,${EXIM_USER},' \
		-e 's,XX_EXIM_GROUP_XX,${EXIM_GROUP},' \
		-e 's,XX_LOCALBASE_XX,${LOCALBASE},' \
		-e 's,XX_LOG_FILE_PATH_XX,${LOG_FILE_PATH},' \
		-e 's,XX_DEFAULT_CHARSET_XX,${WITH_DEFAULT_CHARSET},'

.if defined(WITH_EXIMON)
SEDLIST+=	-e 's,^\# EXIM_MONITOR=,EXIM_MONITOR=,'
PLIST_SUB+=	EXIMON=""
.else
PLIST_SUB+=	EXIMON="@comment "
.endif

.if !defined(WITHOUT_TLS)
SEDLIST+=	-e 's,^\# SUPPORT_TLS=,SUPPORT_TLS=,'
USE_OPENSSL=	yes
.else
SEDLIST+=	-e 's,^TLS_LIBS=,\#TLS_LIBS=,'
.endif

.if !defined(WITHOUT_PERL)
SEDLIST+=	-e 's,^\# EXIM_PERL=,EXIM_PERL=,'
.endif

.if defined(WITH_TCP_WRAPPERS)
SEDLIST+=	-e 's,XX_TCP_WRAPPERS_LIBS_XX,-lwrap,' \
		-e 's,^\# USE_TCP_WRAPPERS=,USE_TCP_WRAPPERS=,'
.else
SEDLIST+=	-e 's,XX_TCP_WRAPPERS_LIBS_XX,,'
.endif

.if defined(WITH_LDAP) || defined(LDAP_LIB_TYPE) \
	|| defined(WITH_OPENLDAP1) || defined(WITH_OPENLDAP2) \
	|| defined(WITH_OPENLDAP20) || defined(WITH_OPENLDAP21)
BROKEN=		deprecated LDAP option defined, use WITH_OPENLDAP or WITH_OPENLDAP_VER
.endif

.if defined(WITH_OPENLDAP_VER) && ${WITH_OPENLDAP_VER:L} != "auto"
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=	yes
LDAP_LIB_TYPE=	OPENLDAP2
SEDLIST+=	-e 's,XX_LDAP_LIBS_XX,-L${LOCALBASE}/lib -llber -lldap,' \
		-e 's,XX_LDAP_INCLUDE_XX,-I${LOCALBASE}/include,' \
		-e 's,XX_LDAP_TYPE_XX,${LDAP_LIB_TYPE},' \
		-e 's,^\# LOOKUP_LDAP=,LOOKUP_LDAP=,'
.else
SEDLIST+=	-e 's,XX_LDAP_[^ ]*_XX,,' \
		-e 's,^LDAP_LIB_TYPE=,\#LDAP_LIB_TYPE=,'
.endif

.if defined(DB_LIB_VERSION)
BROKEN=		deprecated option DB_LIB_VERSION used, use WITH_BDB_VER
.endif

.if ${WITH_BDB_VER} == 1
DB_LIBS=
DB_INCLUDES=
SEDLIST+=	-e 's,^DBMLIB=,\#DBMLIB=,'
.elif (${WITH_BDB_VER} == 4)
DB_LIBS=	-L${LOCALBASE}/lib -ldb4
DB_INCLUDES=	-I${LOCALBASE}/include/db4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.elif (${WITH_BDB_VER} == 41)
DB_LIBS=	-L${LOCALBASE}/lib -ldb41
DB_INCLUDES=	-I${LOCALBASE}/include/db41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
.elif (${WITH_BDB_VER} == 42)
DB_LIBS=	-L${LOCALBASE}/lib -ldb-4.2
DB_INCLUDES=	-I${LOCALBASE}/include/db42
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
.else
BROKEN=		WITH_BDB_VER must be either 1, 4, 41 or 42
.endif
SEDLIST+=	-e 's,XX_DB_LIBS_XX,${DB_LIBS},' \
		-e 's,XX_DB_INCLUDES_XX,${DB_INCLUDES},'

.if defined(WITH_MYSQL_VER) && ${WITH_MYSQL_VER:L} != "auto"
WANT_MYSQL_VER=	${WITH_MYSQL_VER}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
SEDLIST+=	-e 's,XX_MYSQL_LIBS_XX,-L${LOCALBASE}/lib/mysql -lmysqlclient,' \
		-e 's,XX_MYSQL_INCLUDE_XX,-I${LOCALBASE}/include/mysql,' \
		-e 's,^\# LOOKUP_MYSQL=,LOOKUP_MYSQL=,'
.else
SEDLIST+=	-e 's,XX_MYSQL_[^ ]*_XX,,'
.endif

.if defined(WITH_SASLAUTHD)
RUN_DEPENDS+=	${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
SEDLIST+=	-e 's,^\# CYRUS_SASLAUTHD_SOCKET=,CYRUS_SASLAUTHD_SOCKET=,'
.endif

.if defined(WITH_PWCHECK)
RUN_DEPENDS+=	${LOCALBASE}/sbin/pwcheck:${PORTSDIR}/security/cyrus-sasl
SEDLIST+=	-e 's,^\# SUPPORT_CYRUS_PWCHECK=,SUPPORT_CYRUS_PWCHECK=,' \
		-e 's,^\# CYRUS_PWCHECK_SOCKET=,CYRUS_PWCHECK_SOCKET=,'
.endif

.if !defined(WITHOUT_PAM)
SEDLIST+=	-e 's,XX_PAM_LIBS_XX,-lpam,' \
		-e 's,^\# SUPPORT_PAM=,SUPPORT_PAM=,'
.else
SEDLIST+=	-e 's,XX_PAM_LIBS_XX,,'
.endif

.if !defined(WITHOUT_AUTH_CRAM_MD5)
SEDLIST+=	-e 's,^\# AUTH_CRAM_MD5=,AUTH_CRAM_MD5=,'
.endif

.if !defined(WITHOUT_AUTH_PLAINTEXT)
SEDLIST+=	-e 's,^\# AUTH_PLAINTEXT=,AUTH_PLAINTEXT=,'
.endif

.if !defined(WITHOUT_AUTH_SPA)
SEDLIST+=	-e 's,^\# AUTH_SPA=,AUTH_SPA=,'
.endif

.if defined(WITH_AUTH_RADIUS)
LIB_DEPENDS+=	radiusclient.0:${PORTSDIR}/net/radiusclient
SEDLIST+=	-e 's,XX_RADIUS_LIBS_XX,-L${LOCALBASE}/lib -lradiusclient,' \
		-e 's,^\# RADIUS_CONFIG_FILE=,RADIUS_CONFIG_FILE=${LOCALBASE},'
.else
SEDLIST+=	-e 's,XX_RADIUS_LIBS_XX,,'
.endif

.if defined(WITH_POSTGRESQL_PORT) && ${WITH_POSTGRESQL_PORT:L} != "auto"
POSTGRESQL_PORT=	${WITH_POSTGRESQL_PORT}
.else
POSTGRESQL_PORT?=	databases/postgresql7
.endif

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
SEDLIST+=	-e 's,XX_PGSQL_LIBS_XX,-L${LOCALBASE}/lib -lpq,' \
		-e 's,XX_PGSQL_INCLUDE_XX,-I${LOCALBASE}/include/pgsql,' \
		-e 's,^\# LOOKUP_PGSQL=,LOOKUP_PGSQL=,'
.else
SEDLIST+=	-e 's,XX_PGSQL_[^ ]*_XX,,'
.endif

.if !defined(WITH_PGSQL) && !defined(WITH_MYSQL) && !defined(LDAP_LIB_TYPE) && \
    ${WITH_BDB_VER} == 1
SEDLIST+=	-e 's,^LOOKUP_LIBS=,\#LOOKUP_LIBS=,' \
		-e 's,^LOOKUP_INCLUDE=,\#LOOKUP_INCLUDE=,'
.endif

.if !defined(WITHOUT_DNSDB)
SEDLIST+=	-e 's,^\# LOOKUP_DNSDB=,LOOKUP_DNSDB=,'
.endif

.if !defined(WITHOUT_MAILDIR)
SEDLIST+=	-e 's,^\# SUPPORT_MAILDIR=,SUPPORT_MAILDIR=,'
.endif

.if !defined(WITHOUT_MAILSTORE)
SEDLIST+=	-e 's,^\# SUPPORT_MAILSTORE=,SUPPORT_MAILSTORE=,'
.endif

.if !defined(WITHOUT_MBX)
SEDLIST+=	-e 's,^\# SUPPORT_MBX=,SUPPORT_MBX=,'
.endif

.if !defined(WITHOUT_CDB)
SEDLIST+=	-e 's,^\# LOOKUP_CDB=,LOOKUP_CDB=,'
.endif

.if !defined(WITHOUT_DSEARCH)
SEDLIST+=	-e 's,^\# LOOKUP_DSEARCH=,LOOKUP_DSEARCH=,'
.endif

.if defined(WITHOUT_LSEARCH)
SEDLIST+=	-e 's,^LOOKUP_LSEARCH=,\#LOOKUP_LSEARCH=,'
.endif

.if !defined(WITHOUT_NIS)
SEDLIST+=	-e 's,^\# LOOKUP_NIS=,LOOKUP_NIS=,'
.endif

.if !defined(WITHOUT_PASSWD)
SEDLIST+=	-e 's,^\# LOOKUP_PASSWD=,LOOKUP_PASSWD=,'
.endif

.if !defined(WITHOUT_LMTP)
SEDLIST+=	-e 's,^\# TRANSPORT_LMTP=,TRANSPORT_LMTP=,'
.endif

.if defined(WITHOUT_ALT_CONFIG_PREFIX)
SEDLIST+=	-e 's,^ALT_CONFIG_PREFIX=,\# ALT_CONFIG_PREFIX=,'
.endif

.if defined(WITH_SPF) && !defined(WITHOUT_EXISCAN)
LIB_DEPENDS+=	spf2.1:${PORTSDIR}/mail/libspf2
CFLAGS+=	-DSPF
SEDLIST+=	-e 's,XX_SPF_LIBS_XX,-lspf2,'
.else
SEDLIST+=	-e 's,XX_SPF_LIBS_XX,,'
.endif

.if defined(WITH_SRS) && !defined(WITHOUT_EXISCAN)
LIB_DEPENDS+=	srs2.0:${PORTSDIR}/mail/libsrs2
CFLAGS+=	-DSRS
SEDLIST+=	-e 's,XX_SRS_LIBS_XX,-lsrs2,'
.else
SEDLIST+=	-e 's,XX_SRS_LIBS_XX,,'
.endif

.include <bsd.port.pre.mk>

.if defined(EXIMON_ONLY) && ${MASTERDIR} == ${PKGDIR}
.error EXIMON_ONLY is not user settable
.endif

.if !defined(EXIMON_ONLY)
USE_RC_SUBR=	yes
.if defined(WITH_RCORDER) && ${OSVERSION} >= 500037
RC_DIR=		/etc/rc.d
RC_SUFX=
PLIST_SUB+=	RCORDER="" \
		RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}
.else
RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
PLIST_SUB+=	RCORDER="@comment " \
		RC_DIR="%D/etc/rc.d" \
		RC_SUFX=${RC_SUFX}
.endif
SED_SCRIPT+=	-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%RC_DIR%%,${RC_DIR},g' \
		-e 's,%%RC_SUFX%%,${RC_SUFX},g'
.endif

.if ${OSVERSION} < 400014
WITHOUT_IPV6=	yes
.endif

.if !defined(WITHOUT_IPV6)
SEDLIST+=	-e 's,^\# HAVE_IPV6=,HAVE_IPV6=,'
.endif

pre-everything::
.if empty(.MAKEFLAGS:M-s) && defined(WITH_WISHLIST)
	@${ECHO} ''
	@${ECHO} 'Included extra patches:'
	@${FIND} ${PATCHDIR} -name 'wishlist-*.patch' \
	    -exec ${SED} -ne 's,^# , ,p' {} \;
	@${ECHO} ''
.endif

do-configure:
	@${MKDIR} ${WRKSRC}/Local
	@${SED} ${SEDLIST} ${WRKSRC}/src/EDITME > ${WRKSRC}/Local/Makefile
.if defined(WITH_EXIMON)
	@${CP} ${WRKSRC}/exim_monitor/EDITME ${WRKSRC}/Local/eximon.conf
.endif
	@[ ! -f ${PKGDIR}/pkg-install ] || ${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-install > ${PKGINSTALL}
	@${REINPLACE_CMD} ${SEDLIST} ${WRKSRC}/src/configure.default
	@${REINPLACE_CMD} -e 's/"(Exim $$version_number)\\n\\t"/"(Exim $$version_number (${OPSYS}))\\n\\t"/' \
		${WRKSRC}/src/globals.c
	@${REINPLACE_CMD} -e 's/^#include "cnumber\.h"$$/${PORTREVISION}/' ${WRKSRC}/src/version.c
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} configure)

post-build:
.for script in exim ${DAILY_SCRIPTS}
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${script}.sh > ${WRKDIR}/${script}.sh
.endfor
.if !defined(WITHOUT_EXISCAN)
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES.exiscan-acl \
	    ${FILESDIR}/POST-INSTALL-NOTES > ${WRKDIR}/POST-INSTALL-NOTES
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES.clamd > ${WRKDIR}/POST-INSTALL-NOTES.clamd
.else
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES > ${WRKDIR}/POST-INSTALL-NOTES
.endif
	@[ ! -f ${PKGDIR}/pkg-message ] || ${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-message > ${WRKDIR}/pkg-message

.if !defined(EXIMON_ONLY)

pre-install:
	@[ -d "${DESTDIR}/etc" ] || ${MKDIR} "${DESTDIR}/etc"
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/exim.sh ${DESTDIR}${RC_DIR}/exim${RC_SUFX}
	@${MKDIR} ${DESTDIR}${PREFIX}/etc/periodic/daily
.for script in ${DAILY_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKDIR}/${script}.sh ${DESTDIR}${PREFIX}/etc/periodic/daily/${script}
.endfor
	@[ -f ${DESTDIR}${PREFIX}/etc/exim/configure ] || \
		${CP} ${DESTDIR}${PREFIX}/etc/exim/configure.default ${DESTDIR}${PREFIX}/etc/exim/configure
.for manfile in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/doc/${manfile} ${DESTDIR}${MAN8PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DESTDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/POST-INSTALL-NOTES ${DESTDIR}${DOCSDIR}
.if !defined(WITHOUT_EXISCAN)
	@${INSTALL_DATA} ${WRKDIR}/POST-INSTALL-NOTES.clamd ${DESTDIR}${DOCSDIR}
.endif
.for docfile in ${PORTDOC_BASE}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor
.for docfile in ${PORTDOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DESTDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${DESTDIR}${EXAMPLESDIR}
.for example in ${PORT_EXAMPLES}
	@${INSTALL_SCRIPT} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/${example} ${DESTDIR}${EXAMPLESDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.else

post-install:
	@${CAT} ${PKGMESSAGE}

.endif

.include <bsd.port.post.mk>
