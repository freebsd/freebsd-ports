# New ports collection makefile for:	exim
# Date created:		23 June 1996
# Whom:			markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	exim
PORTVERSION?=	${EXIM_VERSION}
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_EXIM:S/$/:exim/}
MASTER_SITE_SUBDIR=	exim4/:exim
DISTNAME=	${PORTNAME}-${EXIM_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:exim FAQ.txt.bz2:exim
DIST_SUBDIR=	exim
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	krion@FreeBSD.org
COMMENT?=	High performance MTA for Unix systems on the Internet

.include "options"

.if defined(WITH_SA_EXIM)
MASTER_SITES+=	http://marc.merlins.org/linux/exim/files/:sa_exim \
		${MASTER_SITE_SOURCEFORGE_EXTENDED:S/$/:sa_exim/}
MASTER_SITE_SUBDIR+=	sa-exim/:sa_exim
DISTFILES+=	sa-exim-${SA_EXIM_VERSION}.tar.gz:sa_exim
.endif

EXIM_VERSION=	4.52
SA_EXIM_VERSION=4.2

IGNOREFILES=	FAQ.txt.bz2

.if !defined(EXIMON_ONLY)
.if defined(PKGNAMESUFFIX)
CONFLICTS+=	${PKGNAMEPREFIX}${PORTNAME}-4.*
.endif
.for suffix in -ldap2 -mysql -postgresql -sa-exim
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
USE_REINPLACE=	yes

.if !defined(EXIMON_ONLY)
MAN8=		exim.8
.else
NO_INSTALL_MANPAGES=	yes
.endif

PORTDOC_BASE=	ACKNOWLEDGMENTS FAQ NOTICE README.UPDATING
PORTDOC_FILES=	ChangeLog Exim3.upgrade Exim4.upgrade NewStuff \
		OptionLists.txt README README.SIEVE dbm.discuss.txt \
		experimental-spec.txt filter.txt pcrepattern.txt \
		pcretest.txt spec.txt

PORT_EXAMPLES=	convert4r3 convert4r4 pcretest transport-filter.pl

DAILY_SCRIPTS=	150.exim-tidydb 460.exim-mail-rejects

PKGINSTALL=	${WRKDIR}/pkg-install

.if defined(NOPORTDOCS) && !defined(EXIMON_ONLY)
PKGMESSAGE=	${WRKDIR}/POST-INSTALL-NOTES
.else
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif

MAKE_ENV+=	OSTYPE="${OPSYS}" ARCHTYPE="${ARCH}" DUMMY_LDFLAGS="${DUMMY_LDFLAGS}"
.if defined(EXIMON_ONLY)
MAKE_ENV+=	INSTALL_ARG="eximon eximon.bin"
.elif defined(WITHOUT_SUID)
MAKE_ENV+=	INSTALL_ARG="-no_chown"
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
		EXIM_GROUP=${EXIM_GROUP} \
		LOGDIR="${LOGDIR}"

# Define it to enabale malware and spam scanning in the DATA ACL,
# and the MIME ACL.
#WITH_CONTENT_SCAN=	yes

# Enable old, deprecated "demime" ACL condition, in addition
# to all the other content-scanning features.
#WITHOUT_OLD_DEMIME=	yes

# If WITH_EXIMON is defined, the eximon monitor, which requires X,
# will be made a dependency.  Note that using WITH_EXIMON will cause
# XFree86 to be installed if it is not present.
#WITH_EXIMON=	yes

# If WITH_SA_EXIM is defined, exim will be built with the SA-Exim
# local_scan function (<http://marc.merlins.org/linux/exim/sa.html>)
#WITH_SA_EXIM=		yes

# Exim refuses to run local deliveries as root by default.  You can
# add other users to this colon-separated list that cannot be
# overridden at runtime below, but are advised not to remove "root".
#WITH_FIXED_NEVER_USERS=	root:daemon:bin

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
# OpenLDAP to use. Valid values are currently 21, 22 and 23.
# Defining WITH_OPENLDAP_VER implies WITH_OPENLDAP.
# Exim also supports NETSCAPE and SOLARIS7 lookup types, but no
# client libraries exist for these in the ports tree.
#WITH_OPENLDAP=		yes
#WITH_OPENLDAP_VER=	22

# WITH_BDB_VER is the version of the Berkeley DB library to use, and
# may be 1, which corresponds to version 1.85 in the base system, 4,
# 41, 42 or 43 which depends on the databases/db4[123] ports.
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
# Enable support for authenticating via the Cyrus SASL library
#WITH_AUTH_SASL=		yes
#
# Enable built-in Exim support for radius (RFC 2865) authentication
# RADIUS_TYPE can either be RADLIB (to use the radius library supplied
# with FreeBSD) or RADIUSCLIENT (to use port net/radiusclient)
#WITH_AUTH_RADIUS=		yes
#WITH_RADIUS_TYPE=		RADLIB
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
#WITH_SPF=		yes
#
# Enable Sender Rewriting Scheme (SRS)
#WITH_SRS=		yes
#
# Use the readline(3) library for the test expansion option
#WITH_READLINE=		yes
#
# Don't install the exim binary suid root
#WITHOUT_SUID=		yes
#
# Don't install scripts to run exim as a daemon
# (for example when using option mua_wrapper)
#WITHOUT_DAEMON=	yes

# You should not need to fiddle with anything below this point.

.if defined(WITH_WISHLIST)
EXTRA_PATCHES+=	`${FIND} ${PATCHDIR} -name 'wishlist-*.patch'`
.endif

SEDLIST+=	-e 's,XX_CFLAGS_XX,${CFLAGS},' \
		-e 's,XX_PREFIX_XX,${PREFIX},' \
		-e 's,XX_LOCALBASE_XX,${LOCALBASE},' \
		-e 's,XX_LOG_FILE_PATH_XX,${LOG_FILE_PATH},' \
		-e 's,XX_EXIM_USER_XX,${EXIM_USER},' \
		-e 's,XX_EXIM_GROUP_XX,${EXIM_GROUP},' \
		-e 's,XX_DEFAULT_CHARSET_XX,${WITH_DEFAULT_CHARSET},'

.if defined(WITH_FIXED_NEVER_USERS)
SEDLIST+=	-e 's,^(FIXED_NEVER_USERS=).*,\1${WITH_FIXED_NEVER_USERS},'
.endif

.if defined(WITH_EXIMON)
SEDLIST+=	-e 's,^\# (EXIM_MONITOR=),\1,'
PLIST_SUB+=	EXIMON=""
.else
PLIST_SUB+=	EXIMON="@comment "
.endif

.if !defined(WITHOUT_TLS)
USE_OPENSSL=	yes
SEDLIST+=	-e 's,^\# (SUPPORT_TLS=),\1,'
.else
SEDLIST+=	-e 's,^(TLS_LIBS=),\# \1,'
.endif

.if !defined(WITHOUT_PERL)
USE_PERL5=	yes
SEDLIST+=	-e 's,^\# (EXIM_PERL=),\1,'
.endif

.if defined(WITH_TCP_WRAPPERS)
SEDLIST+=	-e 's,XX_TCP_WRAPPERS_LIBS_XX,-lwrap,' \
		-e 's,^\# (USE_TCP_WRAPPERS=),\1,'
.else
SEDLIST+=	-e 's,XX_TCP_WRAPPERS_LIBS_XX,,'
.endif

.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
SEDLIST+=	-e 's,XX_ICONV_LIBS_XX,-L${LOCALBASE}/lib -liconv,' \
		-e 's,^\# (HAVE_ICONV=),\1,'
.else
SEDLIST+=	-e 's,XX_ICONV_LIBS_XX,,'
.endif

.if defined(WITH_LDAP) || defined(LDAP_LIB_TYPE) \
	|| defined(WITH_OPENLDAP1) || defined(WITH_OPENLDAP2) \
	|| defined(WITH_OPENLDAP20) || defined(WITH_OPENLDAP21)
BROKEN=		"deprecated LDAP option defined, use WITH_OPENLDAP or WITH_OPENLDAP_VER"
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
		-e 's,^\# (LOOKUP_LDAP=),\1,'
.else
SEDLIST+=	-e 's,XX_LDAP_[^ ]*_XX,,' \
		-e 's,^(LDAP_LIB_TYPE=),\# \1,'
.endif

.if defined(DB_LIB_VERSION)
BROKEN=		"deprecated option DB_LIB_VERSION used, use WITH_BDB_VER"
.endif

.if ${WITH_BDB_VER} == 1
DB_LIBS=
DB_INCLUDES=
SEDLIST+=	-e 's,^(DBMLIB=),\# \1,'
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
.elif (${WITH_BDB_VER} == 43)
DB_LIBS=	-L${LOCALBASE}/lib -ldb-4.3
DB_INCLUDES=	-I${LOCALBASE}/include/db43
LIB_DEPENDS+=	db-4.3.0:${PORTSDIR}/databases/db43
.else
BROKEN=		"WITH_BDB_VER must be either 1, 4, 41, 42 or 43"
.endif
SEDLIST+=	-e 's,XX_DB_LIBS_XX,${DB_LIBS},' \
		-e 's,XX_DB_INCLUDES_XX,${DB_INCLUDES},'

.if defined(WITH_MYSQL_VER) && ${WITH_MYSQL_VER:L} != "auto"
WANT_MYSQL_VER=	${WITH_MYSQL_VER}
.else
.undef WITH_MYSQL_VER
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
SEDLIST+=	-e 's,XX_MYSQL_LIBS_XX,-L${LOCALBASE}/lib/mysql -lmysqlclient,' \
		-e 's,XX_MYSQL_INCLUDE_XX,-I${LOCALBASE}/include/mysql,' \
		-e 's,^\# (LOOKUP_MYSQL=),\1,'
.else
SEDLIST+=	-e 's,XX_MYSQL_[^ ]*_XX,,'
.endif

.if defined(WITH_SASLAUTHD)
RUN_DEPENDS+=	${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
SEDLIST+=	-e 's,^\# (CYRUS_SASLAUTHD_SOCKET=),\1,'
.endif

.if defined(WITH_PWCHECK)
RUN_DEPENDS+=	${LOCALBASE}/sbin/pwcheck:${PORTSDIR}/security/cyrus-sasl
SEDLIST+=	-e 's,^\# (SUPPORT_CYRUS_PWCHECK=),\1,' \
		-e 's,^\# (CYRUS_PWCHECK_SOCKET=),\1,'
.endif

.if !defined(WITHOUT_PAM)
SEDLIST+=	-e 's,XX_PAM_LIBS_XX,-lpam,' \
		-e 's,^\# (SUPPORT_PAM=),\1,'
.else
SEDLIST+=	-e 's,XX_PAM_LIBS_XX,,'
.endif

.if !defined(WITHOUT_AUTH_CRAM_MD5)
SEDLIST+=	-e 's,^\# (AUTH_CRAM_MD5=),\1,'
.endif

.if !defined(WITHOUT_AUTH_PLAINTEXT)
SEDLIST+=	-e 's,^\# (AUTH_PLAINTEXT=),\1,'
.endif

.if !defined(WITHOUT_AUTH_SPA)
SEDLIST+=	-e 's,^\# (AUTH_SPA=),\1,'
.endif

.if defined(WITH_AUTH_SASL)
LIB_DEPENDS=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
SEDLIST+=	-e 's,^\# (AUTH_CYRUS_SASL=),\1,' \
		-e 's,^\# (AUTH_LIBS=),\1,'
.endif

.if defined(WITH_AUTH_RADIUS)
WITH_RADIUS_TYPE?=	RADLIB
.if ${WITH_RADIUS_TYPE:L} == radlib
SEDLIST+=	-e 's,XX_RADIUS_LIBS_XX,-lradius,' \
		-e 's,^\# (RADIUS_CONFIG_FILE=).*,\1/etc/radius.conf,' \
		-e 's,^\# (RADIUS_LIB_TYPE=).*,\1RADLIB,'
.elif ${WITH_RADIUS_TYPE:L} == radiusclient
LIB_DEPENDS+=	radiusclient.0:${PORTSDIR}/net/radiusclient
SEDLIST+=	-e 's,XX_RADIUS_LIBS_XX,-L${LOCALBASE}/lib -lradiusclient,' \
		-e 's,^\# (RADIUS_CONFIG_FILE=).*,\1${LOCALBASE}/etc/radiusclient.conf,' \
		-e 's,^\# (RADIUS_LIB_TYPE=).*,\1RADIUSCLIENT,'
.else
IGNORE=		WITH_RADIUS_TYPE must be either RADLIB or RADIUSCLIENT
.endif
.else
SEDLIST+=	-e 's,XX_RADIUS_LIBS_XX,,'
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
SEDLIST+=	-e 's,XX_PGSQL_LIBS_XX,-L${LOCALBASE}/lib -lpq,' \
		-e 's,XX_PGSQL_INCLUDE_XX,-I${LOCALBASE}/include/pgsql,' \
		-e 's,^\# (LOOKUP_PGSQL=),\1,'
.else
SEDLIST+=	-e 's,XX_PGSQL_[^ ]*_XX,,'
.endif

.if !defined(WITH_PGSQL) && !defined(WITH_MYSQL) && !defined(LDAP_LIB_TYPE) && \
    ${WITH_BDB_VER} == 1
SEDLIST+=	-e 's,^(LOOKUP_LIBS=),\# \1,' \
		-e 's,^(LOOKUP_INCLUDE=),\# \1,'
.endif

.if !defined(WITHOUT_DNSDB)
SEDLIST+=	-e 's,^\# (LOOKUP_DNSDB=),\1,'
.endif

.if !defined(WITHOUT_MAILDIR)
SEDLIST+=	-e 's,^\# (SUPPORT_MAILDIR=),\1,'
.endif

.if !defined(WITHOUT_MAILSTORE)
SEDLIST+=	-e 's,^\# (SUPPORT_MAILSTORE=),\1,'
.endif

.if !defined(WITHOUT_MBX)
SEDLIST+=	-e 's,^\# (SUPPORT_MBX=),\1,'
.endif

.if !defined(WITHOUT_CDB)
SEDLIST+=	-e 's,^\# (LOOKUP_CDB=),\1,'
.endif

.if !defined(WITHOUT_DSEARCH)
SEDLIST+=	-e 's,^\# (LOOKUP_DSEARCH=),\1,'
.endif

.if defined(WITHOUT_LSEARCH)
SEDLIST+=	-e 's,^(LOOKUP_LSEARCH=),\# \1,'
.endif

.if !defined(WITHOUT_NIS)
SEDLIST+=	-e 's,^\# (LOOKUP_NIS=),\1,'
.endif

.if !defined(WITHOUT_PASSWD)
SEDLIST+=	-e 's,^\# (LOOKUP_PASSWD=),\1,'
.endif

.if !defined(WITHOUT_LMTP)
SEDLIST+=	-e 's,^\# (TRANSPORT_LMTP=),\1,'
.endif

.if defined(WITHOUT_ALT_CONFIG_PREFIX)
SEDLIST+=	-e 's,^(ALT_CONFIG_PREFIX=),\# \1,'
.endif

.if defined(WITH_SPF)
LIB_DEPENDS+=	spf2.1:${PORTSDIR}/mail/libspf2
SEDLIST+=	-e 's,XX_SPF_FLAGS_XX,-DSPF,' \
		-e 's,XX_SPF_LIBS_XX,-lspf2,' \
		-e 's,^\# (EXPERIMENTAL_SPF=),\1,'
.else
SEDLIST+=	-e 's,XX_SPF_FLAGS_XX,,' \
		-e 's,XX_SPF_LIBS_XX,,'
.endif

.if defined(WITH_SRS)
LIB_DEPENDS+=	srs2.0:${PORTSDIR}/mail/libsrs2
SEDLIST+=	-e 's,XX_SRS_FLAGS_XX,-DSRS,' \
		-e 's,XX_SRS_LIBS_XX,-lsrs2,'
.else
SEDLIST+=	-e 's,XX_SRS_FLAGS_XX,,' \
		-e 's,XX_SRS_LIBS_XX,,'
.endif

.if defined(WITH_SA_EXIM)
RUN_DEPENDS+=	${LOCALBASE}/bin/spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
PLIST_SUB+=	SA_EXIM=""
.else
PLIST_SUB+=	SA_EXIM="@comment "
.endif

.if defined(WITH_READLINE)
SEDLIST+=	-e 's,^\# (USE_READLINE=),\1,'
.endif

.if defined(WITH_CONTENT_SCAN)
SEDLIST+=	-e 's,^\# (WITH_CONTENT_SCAN=),\1,'
.endif

.if !defined(WITHOUT_OLD_DEMIME)
SEDLIST+=	-e 's,^\# (WITH_OLD_DEMIME=),\1,'
.endif

.include <bsd.port.pre.mk>

.if defined(EXIMON_ONLY) && ${MASTERDIR} == ${PKGDIR}
.error EXIMON_ONLY is not user settable
.endif

.if !defined(EXIMON_ONLY) && !defined(WITHOUT_DAEMON)
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
PLIST_SUB+=	DAEMON=""
.else
PLIST_SUB+=	DAEMON="@comment "
.endif

.if ${OSVERSION} < 400014
WITHOUT_IPV6=	yes
.endif

.if !defined(WITHOUT_IPV6)
SEDLIST+=	-e 's,^\# (HAVE_IPV6=),\1,'
.endif

DUMMY_LDFLAGS!=	${ECHO_CMD} ${LDFLAGS} | ${SED} -e 's|-Wl,-rpath|-Wl,-DUMMYrpath|g; s|-rpath|-Wl,-rpath|g; s|-DUMMYrpath|-rpath|g'

pre-everything::
.if empty(.MAKEFLAGS:M-s) && defined(WITH_WISHLIST)
	@${ECHO} ''
	@${ECHO} 'Included extra patches:'
	@${FIND} ${PATCHDIR} -name 'wishlist-*.patch' \
	    -exec ${SED} -ne 's,^# , ,p' {} \;
	@${ECHO} ''
.endif

post-extract:
	@${BZCAT} ${_DISTDIR}/FAQ.txt.bz2 > ${WRKSRC}/FAQ
.if defined(WITH_SA_EXIM)
	@cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/sa-exim-${SA_EXIM_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS}
.endif

do-configure:
	@${MKDIR} ${WRKSRC}/Local
	@${SED} -E ${SEDLIST} ${WRKSRC}/src/EDITME > ${WRKSRC}/Local/Makefile
.if defined(WITH_EXIMON)
	@${CP} ${WRKSRC}/exim_monitor/EDITME ${WRKSRC}/Local/eximon.conf
.endif
	@[ ! -f ${PKGDIR}/pkg-install ] || ${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-install > ${PKGINSTALL}
	@${REINPLACE_CMD} -E ${SEDLIST} ${WRKSRC}/src/configure.default
	@${REINPLACE_CMD} -e 's/$$(LDFLAGS)/$$(DUMMY_LDFLAGS)/' ${WRKSRC}/OS/Makefile-Base
	@${REINPLACE_CMD} -e 's/"(Exim $$version_number)\\n\\t"/"(Exim $$version_number (${OPSYS}))\\n\\t"/' \
		${WRKSRC}/src/globals.c
	@${REINPLACE_CMD} -e 's/Exim version %s \(#%s \)\{0,1\}/&(${OPSYS} ${OSREL}) /' ${WRKSRC}/src/exim.c
	@${REINPLACE_CMD} -e 's/^#include "cnumber\.h"$$/${PORTREVISION}/' ${WRKSRC}/src/version.c
	@${REINPLACE_CMD} -E -e 's/^(PERL_COMMAND=).*/\1${PERL:S,/,\/,g}/' \
		-e 's/^(CC=).*/\1${CC:S,/,\/,g}/' ${WRKSRC}/OS/Makefile-Default
.if defined(WITH_SA_EXIM)
	@${REINPLACE_CMD} -E -e 's/^(LOCAL_SCAN_SOURCE=).*/\1Local\/sa-exim.c/' \
		${WRKSRC}/OS/Makefile-Default
	@${CP} ${WRKDIR}/sa-exim-${SA_EXIM_VERSION}/sa-exim.c ${WRKSRC}/Local
	@{ \
	    ${ECHO_CMD} "char *version=\"${SA_EXIM_VERSION}\";"; \
	    ${ECHO_CMD} "#define SPAMC_LOCATION		\"${LOCALBASE}/bin/spamc\""; \
	    ${ECHO_CMD} "#define SPAMASSASSIN_CONF	\"${PREFIX}/etc/exim/sa-exim.conf\""; \
	} > ${WRKSRC}/Local/sa-exim.h
	@${REINPLACE_CMD} -e 's,/usr/bin/spamc,${LOCALBASE}/bin/spamc,' \
	    ${WRKDIR}/sa-exim-${SA_EXIM_VERSION}/sa-exim.conf
.endif
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} configure)

post-build:
.for script in exim ${DAILY_SCRIPTS}
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${script}.sh > ${WRKDIR}/${script}.sh
.endfor
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES > \
		${WRKDIR}/POST-INSTALL-NOTES
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES.clamd > ${WRKDIR}/POST-INSTALL-NOTES.clamd
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES > ${WRKDIR}/POST-INSTALL-NOTES
	@[ ! -f ${PKGDIR}/pkg-message ] || ${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-message > ${WRKDIR}/pkg-message

.if !defined(EXIMON_ONLY)

pre-install:
	@[ -d "${DESTDIR}/etc" ] || ${MKDIR} "${DESTDIR}/etc"
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(WITHOUT_DAEMON)
	@${INSTALL_SCRIPT} ${WRKDIR}/exim.sh ${DESTDIR}${RC_DIR}/exim${RC_SUFX}
	@${MKDIR} ${DESTDIR}${PREFIX}/etc/periodic/daily
.for script in ${DAILY_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKDIR}/${script}.sh ${DESTDIR}${PREFIX}/etc/periodic/daily/${script}
.endfor
.endif
	@[ -f ${DESTDIR}${PREFIX}/etc/exim/configure ] || \
		${CP} ${DESTDIR}${PREFIX}/etc/exim/configure.default ${DESTDIR}${PREFIX}/etc/exim/configure
.for manfile in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/doc/${manfile} ${DESTDIR}${MAN8PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DESTDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/POST-INSTALL-NOTES ${DESTDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/POST-INSTALL-NOTES.clamd ${DESTDIR}${DOCSDIR}
.for docfile in ${PORTDOC_BASE}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor
.for docfile in ${PORTDOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DESTDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${DESTDIR}${EXAMPLESDIR}
.for example in ${PORT_EXAMPLES}
	@${INSTALL_SCRIPT} ${WRKSRC}/build-${OPSYS}-${ARCH}/${example} ${DESTDIR}${EXAMPLESDIR}
.endfor
.endif
.if defined(WITH_SA_EXIM)
	@${INSTALL_DATA} ${WRKDIR}/sa-exim-${SA_EXIM_VERSION}/sa-exim.conf \
		${DESTDIR}${PREFIX}/etc/exim/sa-exim.conf.default
	@[ -f ${DESTDIR}${PREFIX}/etc/exim/sa-exim.conf ] || \
	    ${CP} ${DESTDIR}${PREFIX}/etc/exim/sa-exim.conf.default \
	    ${DESTDIR}${PREFIX}/etc/exim/sa-exim.conf
.endif
	@${CAT} ${PKGMESSAGE}
	@${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.else

post-install:
	@${CAT} ${PKGMESSAGE}

.endif

.include <bsd.port.post.mk>
