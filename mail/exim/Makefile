# New ports collection makefile for:	exim
# Date created:		23 June 1996
# Whom:			markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	exim
PORTVERSION=	${EXIM_VERSION}
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_EXIM} \
		http://duncanthrax.net/%SUBDIR%/:exiscan,exiscan_acl
MASTER_SITE_SUBDIR=	exim4 exiscan/:exiscan exiscan-acl/:exiscan_acl
DISTFILES=	exim-${EXIM_VERSION}${EXTRACT_SUFX} \
		exim-texinfo-${EXIM_DOCVERSION}${EXTRACT_SUFX}
.if defined(WITH_EXISCAN_ACL)
DISTFILES+=	exiscan-acl-${EXISCAN_ACL_VERSION}.patch.bz2:exiscan_acl
.elif !defined(WITHOUT_EXISCAN)
DISTFILES+=	exiscan-${EXISCAN_VERSION}${EXTRACT_SUFX}:exiscan
.endif
DIST_SUBDIR=	exim

EXTRACT_ONLY=	exim-${EXIM_VERSION}${EXTRACT_SUFX} \
		exim-texinfo-${EXIM_DOCVERSION}${EXTRACT_SUFX}
.if !defined(WITH_EXISCAN_ACL) && !defined(WITHOUT_EXISCAN)
EXTRACT_ONLY+=	exiscan-${EXISCAN_VERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	sheldonh@FreeBSD.org
COMMENT=	High performance MTA for Unix systems on the Internet

USE_BZIP2=	yes
USE_PERL5=	yes
MAN8=		exim.8

EXIM_VERSION=		4.20
EXIM_DOCVERSION=	4.20
EXISCAN_ACL_VERSION=	${EXIM_VERSION}-10
EXISCAN_VERSION=	${EXIM_VERSION}-26

PLIST_SUB+=     EXIM_VERSION="${EXIM_VERSION}"

.if defined(NOPORTDOCS)
PKGMESSAGE=	${WRKDIR}/POST-INSTALL-NOTES
.endif

MAKE_ENV+=	OSTYPE=${OPSYS} ARCHTYPE=${MACHINE_ARCH}

POSTGRESQL_PORT?=	databases/postgresql7

# If WITH_EXIMON is defined, the eximon monitor, which requires X,
# will be made a dependency.  Note that using WITH_EXIMON will cause
# XFree86 to be installed if it is not present.
#WITH_EXIMON=	yes

# If WITH_EXISCAN_ACL is defined, exim will be build with the newer
# exiscan acl support. Otherwise if WITHOUT_EXISCAN is defined,
# exim will be built without exiscan email content scanner support.
#WITH_EXISCAN_ACL=	yes
#WITHOUT_EXISCAN=	yes

# Define WITH_TCP_WRAPPERS, WITH_MYSQL, and WITH_PGSQL to link against
# libwrap, liblibmysqlclient and libpq respectively.  Define
# WITH_PWCHECK to link against libsasl for SMTP AUTH authentication
# via the Cyrus SASL pwcheck daemon.
#WITH_TCP_WRAPPERS=	yes
#WITH_MYSQL=		yes
#WITH_PGSQL=		yes
#WITH_PWCHECK=		yes

# Define WITHOUT_IPV6 to exclude IPv6 support from the compiled exim
# binary.  Exim compiled with IPv6 support will still operate on
# systems that do not have IPv6 kernel support, so this should not
# be necessary.
#WITHOUT_IPV6=		yes

# Define WITH_OPENLDAP1, WITH_OPENLDAP20 or WITH_OPENLDAP21 to link
# against the respective OpenLDAP library.
# Exim also supports NETSCAPE and SOLARIS7 lookup types, but no
# client libraries exist for these in the ports tree.
#WITH_OPENLDAP1=	yes
#WITH_OPENLDAP20=	yes
#WITH_OPENLDAP21=	yes

# DB_LIB_VERSION is the version of the Berkeley DB library to use, and
# may be 1, which corresponds to version 1.85 in the base system, 4 or
# 41 which depends on the databases/db4 or databases/db41 port.
DB_LIB_VERSION?=1

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
# Disable built-in Exim support for additional mailbox formats.
#WITHOUT_MAILDIR=	yes
#WITHOUT_MAILSTORE=	yes
#WITHOUT_MBX=		yes
#
# Define WITHOUT_CDB, WITHOUT_DSEARCH, WILD_LSEARCH and WITHOUT_NIS to
# disable support for CDB-style, directory-list, wildcarded-file and NIS
# lookups respectively.
#WITHOUT_CDB=		yes
#WITHOUT_DSEARCH=	yes
#WITHOUT_WILDLSEARCH=	yes
#WITHOUT_NIS=		yes
#
# Disable support for the LMTP (RFC 2033 "SMTP over command pipe")
# transport.
#WITHOUT_LMTP=		yes
#
# Include the unsupported patches in ${PATCHDIR}/wishlist-*.patch
#WITH_WISHLIST=		yes

# You should not need to fiddle with anything below this point.

.if defined(WITH_EXIMON)
RUN_DEPENDS=	${LOCALBASE}/sbin/eximon:${PORTSDIR}/mail/exim-monitor
.endif

.if defined(WITH_WISHLIST)
EXTRA_PATCHES+=	`${FIND} ${PATCHDIR} -name 'wishlist-*.patch'`
.endif

.include <bsd.port.pre.mk>

PORTDOC_FILES=	Exim3.upgrade Exim4.upgrade OptionLists.txt README \
		dbm.discuss.txt filter.txt pcrepattern.txt pcretest.txt \
		spec.txt
.if defined(WITH_EXISCAN_ACL)
PORTDOC_FILES+=	exiscan-acl-examples.txt exiscan-acl-spec.txt
PLIST_SUB+=             EXISCAN_ACL=""
PLIST_SUB+=             EXISCAN="@comment "
.elif !defined(WITHOUT_EXISCAN)
PORTDOC_FILES+=	exiscan-readme.txt
PLIST_SUB+=             EXISCAN_ACL="@comment "
PLIST_SUB+=             EXISCAN=""
.else
PLIST_SUB+=             EXISCAN_ACL="@comment "
PLIST_SUB+=             EXISCAN="@comment "
.endif

.if ${OSVERSION} < 400014
WITHOUT_IPV6=	yes
.endif

SEDLIST=	-e 's,XX_PREFIX_XX,${PREFIX},'

.if !defined(WITHOUT_TLS)
SEDLIST+=	-e 's,^\# SUPPORT_TLS=,SUPPORT_TLS=,'
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

.if defined(WITH_LDAP)
LDAP_LIB_TYPE?=OPENLDAP1
.if (${LDAP_LIB_TYPE} == OPENLDAP1) || (${LDAP_LIB_TYPE} == UMICHIGAN)
WITH_OPENLDAP1=	yes
.elif ${LDAP_LIB_TYPE} == OPENLDAP2
WITH_OPENLDAP2=	yes
.else
.error LDAP_LIB_TYPE must be either OPENLDAP1 or OPENLDAP2
.endif
.endif

.if defined(WITH_OPENLDAP1) && ( defined(WITH_OPENLDAP2) || \
	defined(WITH_OPENLDAP20) || defined(WITH_OPENLDAP21) )
.error please select only one OpenLDAP version
.elif defined(WITH_OPENLDAP20) && defined(WITH_OPENLDAP21)
.error OpenLDAP 2.0 and 2.1 are mutually exclusive
.endif

.if defined(WITH_OPENLDAP21)
LDAP_LIB_TYPE=	OPENLDAP2
LIB_DEPENDS+=	lber.2:${PORTSDIR}/net/openldap21
.elif defined(WITH_OPENLDAP2) || defined(WITH_OPENLDAP20)
LDAP_LIB_TYPE=	OPENLDAP2
LIB_DEPENDS+=	lber.2:${PORTSDIR}/net/openldap20
.elif defined(WITH_OPENLDAP1)
LDAP_LIB_TYPE=	OPENLDAP1
LIB_DEPENDS+=	lber.1:${PORTSDIR}/net/openldap12
.elif defined(LDAP_LIB_TYPE)
.error please choose the OpenLDAP version you want to use
.endif

.if defined(LDAP_LIB_TYPE)
SEDLIST+=	-e 's,XX_LDAP_LIBS_XX,-L${LOCALBASE}/lib -llber -lldap,' \
		-e 's,XX_LDAP_INCLUDE_XX,-I${LOCALBASE}/include,' \
		-e 's,XX_LDAP_TYPE_XX,${LDAP_LIB_TYPE},' \
		-e 's,^\# LOOKUP_LDAP=,LOOKUP_LDAP=,'
.else
SEDLIST+=	-e 's,XX_LDAP_[^ ]*_XX,,' \
		-e 's,^LDAP_LIB_TYPE=,\#LDAP_LIB_TYPE=,'
.endif

.if (${DB_LIB_VERSION} == 1)
DB_LIBS=
DB_INCLUDES=
SEDLIST+=	-e 's,^DBMLIB=,\#DBMLIB=,'
.elif (${DB_LIB_VERSION} == 4)
DB_LIBS=	-L${LOCALBASE}/lib -ldb4
DB_INCLUDES=	-I${LOCALBASE}/include/db4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.elif (${DB_LIB_VERSION} == 41)
DB_LIBS=	-L${LOCALBASE}/lib -ldb41
DB_INCLUDES=	-I${LOCALBASE}/include/db41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
.else
.error DB_LIB_VERSION must be either 1, 4 or 41
.endif
SEDLIST+=	-e 's,XX_DB_LIBS_XX,${DB_LIBS},' \
		-e 's,XX_DB_INCLUDES_XX,${DB_INCLUDES},'

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
SEDLIST+=	-e 's,XX_MYSQL_LIBS_XX,-L${LOCALBASE}/lib/mysql -lmysqlclient,' \
		-e 's,XX_MYSQL_INCLUDE_XX,-I${LOCALBASE}/include/mysql,' \
		-e 's,^\# LOOKUP_MYSQL=,LOOKUP_MYSQL=,'
.else
SEDLIST+=	-e 's,XX_MYSQL_[^ ]*_XX,,'
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

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
SEDLIST+=	-e 's,XX_PGSQL_LIBS_XX,-L${LOCALBASE}/lib -lpq,' \
		-e 's,XX_PGSQL_INCLUDE_XX,-I${LOCALBASE}/include/pgsql,' \
		-e 's,^\# LOOKUP_PGSQL=,LOOKUP_PGSQL=,'
.else
SEDLIST+=	-e 's,XX_PGSQL_[^ ]*_XX,,'
.endif

.if !defined(WITHOUT_IPV6)
SEDLIST+=	-e 's,^\# HAVE_IPV6=,HAVE_IPV6=,'
.endif

.if !defined(WITH_PGSQL) && !defined(WITH_MYSQL) && !defined(LDAP_LIB_TYPE) && \
    ${DB_LIB_VERSION} == 1
SEDLIST+=	-e 's,^LOOKUP_LIBS=,\#LOOKUP_LIBS=,' \
		-e 's,^LOOKUP_INCLUDE=,\#LOOKUP_INCLUDE=,'
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

.if !defined(WITHOUT_WILDLSEARCH)
SEDLIST+=	-e 's,^\# LOOKUP_WILDLSEARCH=,LOOKUP_WILDLSEARCH=,'
.endif

.if !defined(WITHOUT_NIS)
SEDLIST+=	-e 's,^\# LOOKUP_NIS=,LOOKUP_NIS=,'
.endif

.if !defined(WITHOUT_LMTP)
SEDLIST+=	-e 's,^\# TRANSPORT_LMTP=,TRANSPORT_LMTP=,'
.endif

pre-everything::
.if empty(.MAKEFLAGS:M-s) && defined(WITH_WISHLIST)
	@${ECHO} ''
	@${ECHO} 'Included extra patches:'
	@${FIND} ${PATCHDIR} -name 'wishlist-*.patch' \
	    -exec ${SED} -ne 's,^# , ,p' {} \;
	@${ECHO} ''
.endif

post-patch:
.if defined(WITH_EXISCAN_ACL)
	${BZCAT} ${DISTDIR}/${DIST_SUBDIR}/exiscan-acl-${EXISCAN_ACL_VERSION}.patch.bz2 \
	    | ${PATCH} -d ${WRKSRC} -p1 > ${WRKDIR}/patch-exiscan-acl.log 2>&1
	@${CAT} ${FILESDIR}/POST-INSTALL-NOTES.exiscan-acl \
	    ${FILESDIR}/POST-INSTALL-NOTES > ${WRKDIR}/POST-INSTALL-NOTES
.elif !defined(WITHOUT_EXISCAN)
	cd ${WRKSRC} && ${PATCH} -p1 \
	    < ../exiscan-${EXISCAN_VERSION}/exiscan-${EXISCAN_VERSION}.patch \
	    > ${WRKDIR}/patch-exiscan.log 2>&1
	@${CAT} ${FILESDIR}/POST-INSTALL-NOTES.exiscan \
	    ${FILESDIR}/POST-INSTALL-NOTES > ${WRKDIR}/POST-INSTALL-NOTES
.else
	@${CAT} ${FILESDIR}/POST-INSTALL-NOTES > ${WRKDIR}/POST-INSTALL-NOTES
.endif

do-configure:
	${MKDIR} ${WRKSRC}/Local
	${SED} ${SEDLIST} < ${WRKSRC}/src/EDITME > ${WRKSRC}/Local/Makefile
	cd ${WRKSRC}/doc && \
	for i in ../../exim-texinfo-${EXIM_DOCVERSION}/doc/* ; do \
		${LN} -sf $$i ; \
	done

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/exim.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/exim
	${INSTALL_DATA} ${WRKDIR}/POST-INSTALL-NOTES ${PREFIX}/share/doc/exim
.for file in ${PORTDOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/exim
.endfor
.for file in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/doc/${file} ${PREFIX}/man/man8
.endfor
.endif
	@${CAT} ${PKGMESSAGE}
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
