# Created by: markm@FreeBSD.org
# $FreeBSD$

PORTNAME=	exim
PORTVERSION?=	${EXIM_VERSION}
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_EXIM:S/$/:exim/}
MASTER_SITE_SUBDIR=	exim4/:exim
DISTNAME=	${PORTNAME}-${EXIM_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:exim
DIST_SUBDIR=	exim
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	rea@FreeBSD.org
COMMENT?=	High performance MTA for Unix systems on the Internet

LICENSE=	GPLv2

USE_BZIP2=	yes
WANT_GNOME=	yes
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
# One can tune the following "hidden" knobs:
# - EXIM_USER: user exim is running as;
# - EXIM_GROUP: ditto for the group;
# - LOGDIR: where Exim logs will be put;
# - LOG_FILE_PATH: path where '%s' will be substituted with
#                  the target name (main, reject, etc);
# - CONFIG_FILE_PATH: path to the default configuration file;
# - ALT_CONFIG_PREFIX: path to the default prefix for all
#                      configuration files, excluding the main one;
#                      will be effective only when WITH_ALT_CONFIG_PREFIX
#                      will be set via OPTIONS.

.if make(makesum) && !defined(FETCH_ALL)
.error "You forgot to define FETCH_ALL to create the sane distinfo"
.endif

.include "options"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSA_EXIM}
.if ${PORT_OPTIONS:MKAS}
IGNORE=		You cannot select both SA_EXIM and KAS options
.endif
.if ${PORT_OPTIONS:MSO_1024}
IGNORE=		You cannot select both SA_EXIM and SO_1024 options
.endif
.endif

.if ${PORT_OPTIONS:MKAS}
.if ${PORT_OPTIONS:MSO_1024}
IGNORE=		You cannot select both SA_KAS and SO_1024 options
.endif
.endif

.if ${PORT_OPTIONS:MSA_EXIM} || defined(FETCH_ALL)
MASTER_SITES+=	http://marc.merlins.org/linux/exim/files/:sa_exim \
		SF/sa-exim/sa-exim/${SA_EXIM_VERSION}:sa_exim
MASTER_SITE_SUBDIR+=	sa-exim/:sa_exim
DISTFILES+=	sa-exim-${SA_EXIM_VERSION}.tar.gz:sa_exim
.endif

.if ${PORT_OPTIONS:MSO_1024} || defined(FETCH_ALL)
MASTER_SITES+=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/:so_1024
DISTFILES+=	spamooborona1024-src-${SO_1024_VERSION}.tar.gz:so_1024
.endif

.if ${PORT_OPTIONS:MSO_1024}
LDFLAGS+=	-lz
PLIST_SUB+=	SO_1024=""
.else
PLIST_SUB+=	SO_1024="@comment "
.endif

EXIM_VERSION=	4.82
SA_EXIM_VERSION=4.2
SO_1024_VERSION=3.2

.if !defined(EXIMON_ONLY)
.if defined(PKGNAMESUFFIX)
CONFLICTS+=	${PKGNAMEPREFIX}${PORTNAME}-4.*
.endif
.for suffix in -ldap2 -mysql -postgresql -sa-exim -sqlite
.if !defined(PKGNAMESUFFIX) || ${PKGNAMESUFFIX} != ${suffix}
CONFLICTS+=	${PKGNAMEPREFIX}${PORTNAME}${suffix}-4.*
.endif
.endfor
.if ${PORT_OPTIONS:MEXIMON}
CONFLICTS+=	${PKGNAMEPREFIX}${PORTNAME}-monitor-4.*
.endif
.else # !EXIMON_ONLY
PORT_OPTIONS+=	EXIMON
.endif # !EXIMON_ONLY

.if ${PORT_OPTIONS:MEXIMON}
USE_XORG=	x11 xaw xt
.endif

.if !defined(EXIMON_ONLY)
MAN8=		exim.8
.else
NO_INSTALL_MANPAGES=	yes
.endif

PORTDOC_BASE=	ACKNOWLEDGMENTS NOTICE README.UPDATING
PORTDOC_FILES=	ChangeLog Exim3.upgrade Exim4.upgrade NewStuff \
		OptionLists.txt README README.SIEVE dbm.discuss.txt \
		experimental-spec.txt filter.txt spec.txt

PORT_EXAMPLES=	convert4r3 convert4r4 transport-filter.pl

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
.elif ! ${PORT_OPTIONS:MSUID}
MAKE_ENV+=	INSTALL_ARG="-no_chown"
.endif

EXIM_USER?=	mailnull
EXIM_GROUP?=	mail

LOGDIR?=		/var/log/exim
LOG_FILE_PATH?=		${LOGDIR}/%slog
CONFIG_FILE_PATH?=	${PREFIX}/etc/exim/configure
ALT_CONFIG_PREFIX?=	${PREFIX}/etc/exim/

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%EXIM_USER%%,${EXIM_USER},g' \
		-e 's,%%EXIM_GROUP%%,${EXIM_GROUP},g' \
		-e 's,%%LOGDIR%%,${LOGDIR},g'

PLIST_SUB+=	EXIM_VERSION="${EXIM_VERSION}-${PORTREVISION}" \
		EXIM_USER=${EXIM_USER} \
		EXIM_GROUP=${EXIM_GROUP} \
		LOGDIR="${LOGDIR}"

# Exim refuses to run local deliveries as root by default.  You can
# add other users to this colon-separated list that cannot be
# overridden at runtime below, but are advised not to remove "root".
#WITH_FIXED_NEVER_USERS=	root:daemon:bin

# When Exim is decoding MIME "words" in header lines it converts any foreign
# character sets to the one that is set in the headers_charset option.
# The default setting is defined by this setting:
WITH_DEFAULT_CHARSET?=	ISO-8859-1

# You should not need to fiddle with anything below this point.

LIB_DEPENDS+=	pcre.3:${PORTSDIR}/devel/pcre

.if ! ${PORT_OPTIONS:MDKIM}
SEDLIST+=	-e 's,^\# (DISABLE_DKIM=),\1,'
.endif

.if ${PORT_OPTIONS:MLISTMATCH_RHS}
SEDLIST+=	-e 's,^\# (EXPAND_LISTMATCH_RHS=),\1,'
.endif

.if ${PORT_OPTIONS:MDCC}
SEDLIST+=	-e 's,^\# (EXPERIMENTAL_DCC=),\1,'
.endif

.if ${PORT_OPTIONS:MXCLIENT}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-xclient
.endif

.if ${PORT_OPTIONS:MKAS}
BUILD_DEPENDS+=	libspamtest>=0:${PORTSDIR}/mail/libspamtest
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-kas
.endif

.if ${PORT_OPTIONS:MWISHLIST}
EXTRA_PATCHES+=	`${FIND} ${PATCHDIR} -name 'wishlist-*.patch'`
.endif

SEDLIST+=	-e 's,XX_CFLAGS_XX,${CFLAGS:S/,/\\,/g},' \
		-e 's,XX_PREFIX_XX,${PREFIX:S/,/\\,/g},' \
		-e 's,XX_LOCALBASE_XX,${LOCALBASE:S/,/\\,/g},' \
		-e 's,XX_LOG_FILE_PATH_XX,${LOG_FILE_PATH:S/,/\\,/g},' \
		-e 's,XX_CONFIG_FILE_PATH_XX,${CONFIG_FILE_PATH:S/,/\\,/g},' \
		-e 's,XX_ALT_CONFIG_PREFIX_XX,${ALT_CONFIG_PREFIX:S/,/\\,/g},' \
		-e 's,XX_EXIM_USER_XX,${EXIM_USER:S/,/\\,/g},' \
		-e 's,XX_EXIM_GROUP_XX,${EXIM_GROUP:S/,/\\,/g},' \
		-e 's,XX_DEFAULT_CHARSET_XX,${WITH_DEFAULT_CHARSET:S/,/\\,/g},'

.if ${PORT_OPTIONS:MFIXED_NEVER_USERS}
SEDLIST+=	-e 's,^(FIXED_NEVER_USERS=).*,\1${WITH_FIXED_NEVER_USERS:S/,/\\,/g},'
.endif

.if ${PORT_OPTIONS:MEXIMON}
SEDLIST+=	-e 's,^\# (EXIM_MONITOR=),\1,'
PLIST_SUB+=	EXIMON=""
.else
PLIST_SUB+=	EXIMON="@comment "
.endif

.if ${PORT_OPTIONS:MTLS}
SEDLIST+=	-e 's,^\# (SUPPORT_TLS=),\1,'
.if ! ${PORT_OPTIONS:MGNUTLS}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
SEDLIST+=	-e 's,^\# (TLS_LIBS=.*-lssl[[:space:]]),\1,'
.else
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
SEDLIST+=	-e 's,^\# (USE_GNUTLS=),\1,'
SEDLIST+=	-e 's,^\# (TLS_LIBS=.*-lgnutls[[:space:]]),\1,'
.endif
.endif

.if ${PORT_OPTIONS:MEMBEDDED_PERL}
USES+=		perl5
SEDLIST+=	-e 's,^\# (EXIM_PERL=),\1,'
.endif

.if ${PORT_OPTIONS:MTCP_WRAPPERS}
SEDLIST+=	-e 's,XX_TCP_WRAPPERS_LIBS_XX,-lwrap,' \
		-e 's,^\# (USE_TCP_WRAPPERS=),\1,'
.else
SEDLIST+=	-e 's,XX_TCP_WRAPPERS_LIBS_XX,,'
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
SEDLIST+=	-e 's,XX_ICONV_LIBS_XX,-L${LOCALBASE:S/,/\\,/g}/lib ${ICONV_LIB},' \
		-e 's,^\# (HAVE_ICONV=),\1,'
.if exists(/usr/include/iconv.h) && exists(${LOCALBASE}/include/iconv.h)
IGNORE=		You have iconv support in base system, but ${LOCALBASE}/include/iconv.h is present too.  It will hiccup the build.
.endif
.else
SEDLIST+=	-e 's,XX_ICONV_LIBS_XX,,'
.endif

.if ${PORT_OPTIONS:MLDAP} || defined(LDAP_LIB_TYPE) \
	|| ${PORT_OPTIONS:MOPENLDAP1} || defined(WITH_OPENLDAP2) \
	|| ${PORT_OPTIONS:MOPENLDAP20} || defined(WITH_OPENLDAP21)
BROKEN=		deprecated LDAP option defined, use WITH_OPENLDAP or WITH_OPENLDAP_VER
.endif

.if ${PORT_OPTIONS:MOPENLDAP_VER} && ${WITH_OPENLDAP_VER:L} != "auto"
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif

.if ${PORT_OPTIONS:MOPENLDAP}
USE_OPENLDAP=	yes
LDAP_LIB_TYPE=	OPENLDAP2
SEDLIST+=	-e 's,XX_LDAP_LIBS_XX,-L${LOCALBASE:S/,/\\,/g}/lib -llber -lldap,' \
		-e 's,XX_LDAP_INCLUDE_XX,-I${LOCALBASE:S/,/\\,/g}/include,' \
		-e 's,XX_LDAP_TYPE_XX,${LDAP_LIB_TYPE:S/,/\\,/g},' \
		-e 's,^\# (LOOKUP_LDAP=),\1,'
.else
SEDLIST+=	-e 's,XX_LDAP_[^ ]*_XX,,' \
		-e 's,^(LDAP_LIB_TYPE=),\# \1,'
.endif

.if defined(DB_LIB_VERSION)
BROKEN=		deprecated option DB_LIB_VERSION used, use WITH_BDB_VER
.endif

.if ${PORT_OPTIONS:MBDB_VER}
.if ${WITH_BDB_VER} > 1
WITH_BDB=	yes
.endif
.endif

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	yes
INVALID_BDB_VER=	2 3
DB_LIBS=	-L${BDB_LIB_DIR} -l${BDB_LIB_NAME}
DB_INCLUDES=	-I${BDB_INCLUDE_DIR}
.else
DB_LIBS=
DB_INCLUDES=
SEDLIST+=	-e 's,^(DBMLIB=),\# \1,'
.endif
SEDLIST+=	-e 's,XX_DB_LIBS_XX,${DB_LIBS:S/,/\\,/g},' \
		-e 's,XX_DB_INCLUDES_XX,${DB_INCLUDES:S/,/\\,/g},'

.if ${PORT_OPTIONS:MMYSQL}
.if defined(WITH_MYSQL_VER) && ${WITH_MYSQL_VER:L} == "auto"
IGNORE=		WITH_MYSQL_VER set to "${WITH_MYSQL_VER}" is no longer supported.
IGNORE+=	Just don't set WITH_MYSQL_VER if you want to use system-default version
.else
USE_MYSQL=	yes
.endif
SEDLIST+=	-e 's,XX_MYSQL_LIBS_XX,-L${LOCALBASE:S/,/\\,/g}/lib/mysql -lmysqlclient,' \
		-e 's,XX_MYSQL_INCLUDE_XX,-I${LOCALBASE:S/,/\\,/g}/include/mysql,' \
		-e 's,^\# (LOOKUP_MYSQL=),\1,'
.else
SEDLIST+=	-e 's,XX_MYSQL_[^ ]*_XX,,'
.endif

.if ${PORT_OPTIONS:MSASLAUTHD}
RUN_DEPENDS+=	${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
SASLAUTHD_SOCKET?=	/var/run/saslauthd/mux
SEDLIST+=	-e 's,^\# (CYRUS_SASLAUTHD_SOCKET=).*,\1${SASLAUTHD_SOCKET:S/,/\\,/g},'
.endif

.if ${PORT_OPTIONS:MPAM}
SEDLIST+=	-e 's,XX_PAM_LIBS_XX,-lpam,' \
		-e 's,^\# (SUPPORT_PAM=),\1,'
.else
SEDLIST+=	-e 's,XX_PAM_LIBS_XX,,'
.endif

.if ${PORT_OPTIONS:MAUTH_CRAM_MD5}
SEDLIST+=	-e 's,^\# (AUTH_CRAM_MD5=),\1,'
.endif

.if ${PORT_OPTIONS:MAUTH_PLAINTEXT}
SEDLIST+=	-e 's,^\# (AUTH_PLAINTEXT=),\1,'
.endif

.if ${PORT_OPTIONS:MAUTH_DOVECOT}
SEDLIST+=	-e 's,^\# (AUTH_DOVECOT=),\1,'
.endif

.if ${PORT_OPTIONS:MAUTH_SPA}
SEDLIST+=	-e 's,^\# (AUTH_SPA=),\1,'
.endif

.if ${PORT_OPTIONS:MAUTH_SASL}
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
SEDLIST+=	-e 's,^\# (AUTH_CYRUS_SASL=),\1,' \
		-e 's,^\# (AUTH_LIBS=.*-lsasl2),\1,'
.endif

.if ${PORT_OPTIONS:MAUTH_RADIUS}
WITH_RADIUS_TYPE?=	RADLIB
.if ${WITH_RADIUS_TYPE:L} == radlib
SEDLIST+=	-e 's,XX_RADIUS_LIBS_XX,-lradius,' \
		-e 's,^\# (RADIUS_CONFIG_FILE=).*,\1/etc/radius.conf,' \
		-e 's,^\# (RADIUS_LIB_TYPE=).*,\1RADLIB,'
.elif ${WITH_RADIUS_TYPE:L} == radiusclient
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
SEDLIST+=	-e 's,XX_RADIUS_LIBS_XX,-L${LOCALBASE:S/,/\\,/g}/lib -lradiusclient-ng,' \
		-e 's,^\# (RADIUS_CONFIG_FILE=).*,\1${LOCALBASE:S/,/\\,/g}/etc/radiusclient-ng/radiusclient.conf,' \
		-e 's,^\# (RADIUS_LIB_TYPE=).*,\1RADIUSCLIENTNEW,'
.else
IGNORE=		the variable WITH_RADIUS_TYPE must be either RADLIB or RADIUSCLIENT
.endif
.else
SEDLIST+=	-e 's,XX_RADIUS_LIBS_XX,,'
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
SEDLIST+=	-e 's,XX_PGSQL_LIBS_XX,-L${LOCALBASE:S/,/\\,/g}/lib -lpq,' \
		-e 's,XX_PGSQL_INCLUDE_XX,-I${LOCALBASE:S/,/\\,/g}/include/pgsql,' \
		-e 's,^\# (LOOKUP_PGSQL=),\1,'
.else
SEDLIST+=	-e 's,XX_PGSQL_[^ ]*_XX,,'
.endif

.if ! ${PORT_OPTIONS:MPGSQL} && ! ${PORT_OPTIONS:MMYSQL} && !defined(LDAP_LIB_TYPE) && \
    ! ${PORT_OPTIONS:MBDB}
SEDLIST+=	-e 's,^(LOOKUP_LIBS=),\# \1,' \
		-e 's,^(LOOKUP_INCLUDE=),\# \1,'
.endif

.if ! ${PORT_OPTIONS:MDNSDB}
SEDLIST+=	-e 's,^(LOOKUP_DNSDB=),\# \1,'
.endif

.if ${PORT_OPTIONS:MMAILDIR}
SEDLIST+=	-e 's,^\# (SUPPORT_MAILDIR=),\1,'
.endif

.if ${PORT_OPTIONS:MMAILSTORE}
SEDLIST+=	-e 's,^\# (SUPPORT_MAILSTORE=),\1,'
.endif

.if ${PORT_OPTIONS:MMBX}
SEDLIST+=	-e 's,^\# (SUPPORT_MBX=),\1,'
.endif

.if ${PORT_OPTIONS:MCDB}
SEDLIST+=	-e 's,^\# (LOOKUP_CDB=),\1,'
.endif

.if ${PORT_OPTIONS:MDSEARCH}
SEDLIST+=	-e 's,^\# (LOOKUP_DSEARCH=),\1,'
.endif

.if ! ${PORT_OPTIONS:MLSEARCH}
SEDLIST+=	-e 's,^(LOOKUP_LSEARCH=),\# \1,'
.endif

.if ${PORT_OPTIONS:MNIS}
SEDLIST+=	-e 's,^\# (LOOKUP_NIS=),\1,'
.endif

.if ${PORT_OPTIONS:MPASSWD}
SEDLIST+=	-e 's,^\# (LOOKUP_PASSWD=),\1,'
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
USES+=		pkgconfig
SEDLIST+=	-e 's,XX_SQLITE_LIBS_XX,`pkg-config --static --libs sqlite3`,' \
		-e 's,XX_SQLITE_FLAGS_XX,`pkg-config --cflags sqlite3`,' \
		-e 's,^\# (LOOKUP_SQLITE=),\1,'
.else
SEDLIST+=	-e 's,XX_SQLITE_LIBS_XX,,' \
		-e 's,XX_SQLITE_FLAGS_XX,,'
.endif

.if ${PORT_OPTIONS:MLMTP}
SEDLIST+=	-e 's,^\# (TRANSPORT_LMTP=),\1,'
.endif

.if ! ${PORT_OPTIONS:MALT_CONFIG_PREFIX}
SEDLIST+=	-e 's,^(ALT_CONFIG_PREFIX=),\# \1,'
.endif

.if ${PORT_OPTIONS:MSPF}
LIB_DEPENDS+=	spf2.3:${PORTSDIR}/mail/libspf2
SEDLIST+=	-e 's,XX_SPF_FLAGS_XX,-DSPF,' \
		-e 's,XX_SPF_LIBS_XX,-lspf2 ${PTHREAD_LIBS:S/,/\\,/g},' \
		-e 's,^\# (EXPERIMENTAL_SPF=),\1,'
.else
SEDLIST+=	-e 's,XX_SPF_FLAGS_XX,,' \
		-e 's,XX_SPF_LIBS_XX,,'
.endif

.if ${PORT_OPTIONS:MSRS}
LIB_DEPENDS+=	srs2.0:${PORTSDIR}/mail/libsrs2
SEDLIST+=	-e 's,XX_SRS_FLAGS_XX,-DSRS,' \
		-e 's,XX_SRS_LIBS_XX,-lsrs2,'
.elif ${PORT_OPTIONS:MSRS_ALT}
LIB_DEPENDS+=	srs_alt.1:${PORTSDIR}/mail/libsrs_alt
SEDLIST+=	-e 's,XX_SRS_FLAGS_XX,-DEXPERIMENTAL_SRS,' \
		-e 's,XX_SRS_LIBS_XX,-lsrs_alt,'
.else
SEDLIST+=	-e 's,XX_SRS_FLAGS_XX,,' \
		-e 's,XX_SRS_LIBS_XX,,'
.endif

.if ${PORT_OPTIONS:MSA_EXIM}
RUN_DEPENDS+=	${LOCALBASE}/bin/spamc:${PORTSDIR}/mail/spamassassin
PLIST_SUB+=	SA_EXIM=""
.else
PLIST_SUB+=	SA_EXIM="@comment "
.endif

.if ${PORT_OPTIONS:MREADLINE}
SEDLIST+=	-e 's,^\# (USE_READLINE=),\1,'
.endif

.if ${PORT_OPTIONS:MCONTENT_SCAN}
SEDLIST+=	-e 's,^\# (WITH_CONTENT_SCAN=),\1,'
.endif

.if ${PORT_OPTIONS:MOLD_DEMIME}
SEDLIST+=	-e 's,^\# (WITH_OLD_DEMIME=),\1,'
.endif

.if !defined(EXIMON_ONLY) && ${PORT_OPTIONS:MDAEMON}
USE_RC_SUBR=	exim
PLIST_SUB+=	DAEMON=""
SUB_LIST+=	LOGDIR="${LOGDIR}"
.else
PLIST_SUB+=	DAEMON="@comment "
.endif

.if defined(EXIMON_ONLY) && ${MASTERDIR} == ${PKGDIR}
.error EXIMON_ONLY is not user settable
.endif

.if ${PORT_OPTIONS:MIPV6}
SEDLIST+=	-e 's,^\# (HAVE_IPV6=),\1,'
.endif

.if ${PORT_OPTIONS:MDISABLE_D_OPT}
SEDLIST+=	-e 's,^\# (DISABLE_D_OPTION=),\1,'
.else
.if defined(WHITELIST_D_MACROS)
SEDLIST+=	-e 's,^\# (WHITELIST_D_MACROS=).*$$,\1${WHITELIST_D_MACROS:S/,/\\,/g},'
.endif
.endif

.if defined(TRUSTED_CONFIG_LIST)
SEDLIST+=	-e 's,^\# (TRUSTED_CONFIG_LIST=).*$$,\1${TRUSTED_CONFIG_LIST:S/,/\\,/g},'
.endif

DUMMY_LDFLAGS!=	${ECHO_CMD} ${LDFLAGS} | ${SED} -e 's|-Wl,-rpath|-Wl,-DUMMYrpath|g; s|-rpath|-Wl,-rpath|g; s|-DUMMYrpath|-rpath|g'

pre-everything::
	@${ECHO} 'Exim now drops privileges when alternate configuration'
	@${ECHO} 'files are used.  You can set make variable TRUSTED_CONFIG_LIST'
	@${ECHO} 'to specify the list of configuration files for which'
	@${ECHO} 'root privileges will be retained.'
	@${ECHO} ''
	@${ECHO} 'You can whitelist some macros using the make variable'
	@${ECHO} 'WHITELIST_D_MACROS.  This is useful if you are running'
	@${ECHO} 'with DISABLE_D_OPT set, but macros whitelisting will be'
	@${ECHO} 'removed in some future Exim release, so it is better'
	@${ECHO} 'to use TRUSTED_CONFIG_LIST to set the list of trusted'
	@${ECHO} 'configuration files.'
.if empty(.MAKEFLAGS:M-s) && ${PORT_OPTIONS:MWISHLIST}
	@${ECHO} ''
	@${ECHO} 'Included extra patches:'
	@${FIND} ${PATCHDIR} -name 'wishlist-*.patch' \
	    -exec ${SED} -ne 's,^# , ,p' {} \;
	@${ECHO} ''
.endif

post-extract:
.if ${PORT_OPTIONS:MSA_EXIM}
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/sa-exim-${SA_EXIM_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS}
.endif
.if ${PORT_OPTIONS:MSO_1024}
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/spamooborona1024-src-${SO_1024_VERSION}.tar.gz ${EXTRACT_AFTER_ARGS}
	@cd ${WRKDIR} && ${PATCH} --quiet < ${FILESDIR}/extra-patch-so_1024-delimiter
.endif

do-configure:
	@${MKDIR} ${WRKSRC}/Local
	@${SED} -E ${SEDLIST} ${WRKSRC}/src/EDITME > ${WRKSRC}/Local/Makefile
.if ${PORT_OPTIONS:MEXIMON}
	@${CP} ${WRKSRC}/exim_monitor/EDITME ${WRKSRC}/Local/eximon.conf
.endif
	@[ ! -f ${PKGDIR}/pkg-install ] || ${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-install > ${PKGINSTALL}
	@${REINPLACE_CMD} -E ${SEDLIST} ${WRKSRC}/src/configure.default
	@${REINPLACE_CMD} -e 's!$$(LDFLAGS)!$$(DUMMY_LDFLAGS) -L$${LOCALBASE}/lib!' ${WRKSRC}/OS/Makefile-Base
	@${REINPLACE_CMD} -e 's/"(Exim $$version_number)\\n\\t"/"(Exim $$version_number (${OPSYS}))\\n\\t"/' \
		${WRKSRC}/src/globals.c
	@${REINPLACE_CMD} -e 's/Exim version %s \(#%s \)\{0,1\}/&(${OPSYS} ${OSREL}) /' ${WRKSRC}/src/exim.c
	@${REINPLACE_CMD} -e 's/^#include "cnumber\.h"$$/${PORTREVISION}/' ${WRKSRC}/src/version.c
	@${REINPLACE_CMD} -E -e 's/^(PERL_COMMAND=).*/\1${PERL:S,/,\/,g}/' \
		-e 's/^(CC=).*/\1${CC:S,/,\/,g}/' ${WRKSRC}/OS/Makefile-Default
.if ${PORT_OPTIONS:MSA_EXIM}
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
.if ${PORT_OPTIONS:MSO_1024}
	@${REINPLACE_CMD} -E -e 's/^(LOCAL_SCAN_SOURCE=).*/\1Local\/local_scan_1024.c/' \
		${WRKSRC}/OS/Makefile-Default
	@${CP} ${WRKDIR}/local_scan_1024.c ${WRKSRC}/Local
.endif
	@${REINPLACE_CMD} -E -e 's/XX_STRIPCMD_XX/${STRIP_CMD:S,/,\/,g}/' \
		${WRKSRC}/OS/Makefile-FreeBSD
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} configure)

post-build:
.for script in ${DAILY_SCRIPTS}
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${script}.sh > ${WRKDIR}/${script}.sh
.endfor
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES > \
		${WRKDIR}/POST-INSTALL-NOTES
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES.clamd > ${WRKDIR}/POST-INSTALL-NOTES.clamd
	@${SED} ${SED_SCRIPT} ${FILESDIR}/POST-INSTALL-NOTES > ${WRKDIR}/POST-INSTALL-NOTES
	@[ ! -f ${PKGDIR}/pkg-message ] || ${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-message > ${WRKDIR}/pkg-message

.if !defined(EXIMON_ONLY)

pre-install:
	if ! /usr/sbin/pw groupshow ${EXIM_GROUP}; then /usr/sbin/pw groupadd ${EXIM_GROUP} -g 125; fi
	if ! /usr/sbin/pw usershow ${EXIM_USER}; then /usr/sbin/pw useradd ${EXIM_USER} -g ${EXIM_GROUP} -u 125 \
	-h - -d /var/spool/exim -s /nonexistent -c "Exim User"; fi
	@[ -d "/etc" ] || ${MKDIR} "/etc"
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if ${PORT_OPTIONS:MDAEMON}
	@${MKDIR} ${PREFIX}/etc/periodic/daily
.for script in ${DAILY_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKDIR}/${script}.sh ${PREFIX}/etc/periodic/daily/${script}
.endfor
.endif
	@[ -f ${PREFIX}/etc/exim/configure ] || \
		${CP} ${PREFIX}/etc/exim/configure.default ${PREFIX}/etc/exim/configure
.for manfile in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/doc/${manfile} ${MAN8PREFIX}/man/man8
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/POST-INSTALL-NOTES ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/POST-INSTALL-NOTES.clamd ${DOCSDIR}
.for docfile in ${PORTDOC_BASE}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.for docfile in ${PORTDOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${docfile} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for example in ${PORT_EXAMPLES}
	@${INSTALL_SCRIPT} ${WRKSRC}/build-${OPSYS}-${ARCH}/${example} ${EXAMPLESDIR}
.endfor
.endif
.if ${PORT_OPTIONS:MSA_EXIM}
	@${INSTALL_DATA} ${WRKDIR}/sa-exim-${SA_EXIM_VERSION}/sa-exim.conf \
		${PREFIX}/etc/exim/sa-exim.conf.default
	@[ -f ${PREFIX}/etc/exim/sa-exim.conf ] || \
	    ${CP} ${PREFIX}/etc/exim/sa-exim.conf.default \
	    ${PREFIX}/etc/exim/sa-exim.conf
.endif
.if ${PORT_OPTIONS:MSO_1024}
.if !exists(/var/spool/spamooborona)
		@${MKDIR} -m 750 /var/spool/spamooborona
		@${CHOWN} ${EXIM_USER}:${EXIM_GROUP} /var/spool/spamooborona
.endif
.endif
	@${CAT} ${PKGMESSAGE}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.else

post-install:
	@${CAT} ${PKGMESSAGE}

.endif

.include <bsd.port.mk>
