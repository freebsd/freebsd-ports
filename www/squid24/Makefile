# New ports collection makefile for:	squid24
# Date created:		Tue Mar 27 14:56:08 CEST 2001
# Whom:			Adrian Chadd <adrian@FreeBSD.org>
#
# $FreeBSD$
#
# Tunables not (yet) configurable via 'make config':
# SQUID_{U,G}ID
#   Which user/group squid should run as (default: squid/squid).
#   The user and group will be created if they do not already exist.
#   NOTE: before version 2.4.7_11, these settings defaulted to
#   nobody/nogroup.
#   If you wish to keep these settings, please define SQUID_UID=nobody and
#
# SQUID_LANGUAGE
#   The set of error pages to be installed. Valid values are:
#    Bulgarian Czech Danish Dutch English Estonian Finnish
#    French German Hungarian Italian Japanese Korean Polish
#    Portuguese Romanian Russian-1251 Russian-koi8-r Serbian
#    Simplify_Chinese Slovak Spanish Swedish Traditional_Chinese
#    Turkish
#   (default: English)
#
# SQUID_CONFIGURE_ARGS
#   Additional configuration options, see below for a list

PORTNAME=	squid
PORTVERSION=	2.4
PORTREVISION=	11
CATEGORIES=	www
MASTER_SITES=	\
		ftp://ftp.squid-cache.org/pub/%SUBDIR%/ \
		ftp://ftp.unimelb.edu.au/pub/cwis/servers/unix/squid/%SUBDIR%/ \
		ftp://sunsite.auc.dk/pub/infosystems/squid/%SUBDIR%/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/servers/squid/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/squid/&,}
MASTER_SITE_SUBDIR=	squid-2/STABLE
DISTNAME=	squid-2.4.STABLE7
EXTRACT_SUFX=	-src.tar.gz
DIST_SUBDIR=	squid2.4

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.4/bugs/
PATCHFILES=	squid-2.4.STABLE7-url_port.patch \
		squid-2.4.STABLE7-url_escape.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tmseck@netcologne.de
COMMENT=	The successful WWW proxy cache and accelerator

CONFLICTS=	squid-*

GNU_CONFIGURE=	yes
STRIP=		# won't install scripts correctly otherwise.
MAKEFILE=	makefile
USE_PERL5=	yes
USE_REINPLACE=	yes

NO_LATEST_LINK=	yes
DEPRECATED=	This version of squid-2 is no longer officially supported
EXPIRATION_DATE=	when the next release of squid-2 is out

SQUID_UID?=	squid
SQUID_GID?=	squid
SQUID_LANGUAGE?=	English

docs=		QUICKSTART README doc/debug-sections.txt
sbin=		RunAccel RunCache client squid \
		getpwnam_auth ncsa_auth yp_auth
libexec=	cachemgr.cgi diskd unlinkd msnt_auth pam_auth \
		smb_auth smb_auth.sh

OPTIONS=	SQUID_LDAP_AUTH "Install LDAP authentication helpers" off \
		SQUID_DELAY_POOLS "Enable delay pools" off \
		SQUID_SNMP "Enable SNMP support" off \
		SQUID_CARP "Enable CARP support" off \
		SQUID_SSL "Enable SSL support for reverse proxies" off \
		SQUID_PINGER "Install the icmp helper" off \
		SQUID_DNS_HELPER "Use the old 'dnsserver' helper" off \
		SQUID_HTCP "Enable HTCP support" off \
		SQUID_VIA_DB "Enable forward/via database" off \
		SQUID_CACHE_DIGESTS "Enable cache digests" off \
		SQUID_WCCP "Enable Web Cache Coordination Protocol" on \
		SQUID_STRICT_HTTP "Be strictly HTTP compliant" off \
		SQUID_UNDERSCORES "Allow underscores in hostnames" on \
		SQUID_IDENT "Enable ident (RFC 931) lookups" on \
		SQUID_USERAGENT_LOG "Enable User-Agent-header logging" off

CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin  --sysconfdir=${PREFIX}/etc/squid \
		--datadir=${PREFIX}/etc/squid \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=${PREFIX}/squid \
		--enable-storeio="ufs diskd null" \
		--enable-removal-policies="lru heap" \
		--enable-err-language=${SQUID_LANGUAGE}

.include <bsd.port.pre.mk>

# Authentication methods and modules:

auth_modules=	MSNT NCSA PAM SMB YP getpwnam
.if defined(WITH_SQUID_LDAP_AUTH)
USE_OPENLDAP=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
auth_modules+=	LDAP
libexec+=	squid_ldap_auth
.endif

CONFIGURE_ARGS+=	--enable-auth-modules="${auth_modules}"

# Other options set via 'make config':

.if defined(WITH_SQUID_DELAY_POOLS)
CONFIGURE_ARGS+=	--enable-delay-pools
.endif
.if defined(WITH_SQUID_SNMP)
CONFIGURE_ARGS+=	--enable-snmp
.endif
.if defined(WITH_SQUID_CARP)
CONFIGURE_ARGS+=	--enable-carp
.endif
.if defined(WITH_SQUID_SSL)
CONFIGURE_ARGS+=	--enable-ssl
.endif
.if defined(WITH_SQUID_PINGER)
CONFIGURE_ARGS+=	--enable-icmp
libexec+=	pinger
.endif
.if defined(WITH_SQUID_DNS_HELPER)
CONFIGURE_ARGS+=	--disable-internal-dns
libexec+=	dnsserver
.endif
.if defined(WITH_SQUID_HTCP)
CONFIGURE_ARGS+=	--enable-htcp
.endif
.if defined(WITH_SQUID_VIA_DB)
CONFIGURE_ARGS+=	--enable-forw-via-db
.endif
.if defined(WITH_SQUID_CACHE_DIGESTS)
CONFIGURE_ARGS+=	--enable-cache-digests
.endif
.if defined(WITHOUT_SQUID_WCCP)
CONFIGURE_ARGS+=	--disable-wccp
.endif
.if defined(WITH_SQUID_UNDERSCORES)
CONFIGURE_ARGS+=	--enable-underscores
.endif
.if defined(WITH_SQUID_STRICT_HTTP)
CONFIGURE_ARGS+=	--disable-http-violations
.endif
.if defined(WITHOUT_SQUID_IDENT)
CONFIGURE_ARGS+=	--disable-ident-lookups
.endif
.if defined(WITH_SQUID_USERAGENT_LOG)
CONFIGURE_ARGS+=	--enable-useragent-log
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	${docs:T}
.endif
PLIST_DIRS=	libexec/squid
PLIST_FILES=	etc/rc.d/squid.sh etc/squid/mib.txt \
		etc/squid/mime.conf.default etc/squid/squid.conf.default
PLIST_FILES+=	${libexec:S/^/libexec\/squid\//} ${sbin:S/^/sbin\//}

# Other not so common configure options you can set via SQUID_CONFIGURE_ARGS:
#
# Please see the configure script in the squid source distribution for a
# complete list.
#
# --enable-dlmalloc
#  Compile and use the malloc package from Doug Lea
# --enable-gnuregex
#  Compile and use the supplied GNUregex routines instead of BSD regex.
# --enable-xmalloc-debug
#  Enable simple malloc debugging
# --enable-xmalloc-debug-count
#  Detailed trace of memory allocations
# --enable-xmalloc-statistics
#  Show malloc statistics in cachemgr status pages
# --enable-mem-gen-trace
#  Enable generic memory use tracing
# --enable-kill-parent-hack
#  Kill parent (eg: RunCache) on shutdown (use with great care!!)
# --enable-time-hack
#  Optimize time updates to one per second rather than calling gettimeofday()
# --enable-cachemgr-hostname=some.hostname
#  Set an explicit hostname in cachemgr.cgi
# --enable-ipf-transparent
#  Enable Transparent Proxy support for IP-Filter systems (incl 3.0)
# --enable-truncate
#  Use truncate() rather than unlink()

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

pre-configure:
	@${REINPLACE_CMD} -e 's|%%SQUID_UID%%|${SQUID_UID}|g' \
	    -e 's|%%SQUID_GID%%|${SQUID_GID}|g' ${WRKSRC}/src/cf.data.pre

pre-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    -e 's|%%SQUID_UID%%|${SQUID_UID}|g' ${FILESDIR}/squid.sh \
	    >${WRKDIR}/squid.sh

pre-su-install:
	@${SETENV} SQUID_USER=${SQUID_UID} SQUID_GROUP=${SQUID_GID} \
	    PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if defined(WITH_SQUID_PINGER)
	cd ${WRKSRC}/src && make install-pinger
	${CHMOD} 4510 ${PREFIX}/libexec/squid/pinger
	${CHGRP} ${SQUID_GID} ${PREFIX}/libexec/squid/pinger
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d/squid.sh
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${docs} ${DOCSDIR}
.endif
	-cd ${PREFIX}/libexec/squid && ${STRIP_CMD} ${libexec}
	-cd ${PREFIX}/sbin && ${STRIP_CMD} ${sbin}
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
