# New ports collection makefile for:	squid24
# Date created:		Tue Mar 27 14:56:08 CEST 2001
# Whom:			Adrian Chadd <adrian@FreeBSD.org>
#
# $FreeBSD$
#
# Tunables not (yet) configurable via 'make config':
# SQUID_{U,G}ID
#   Which user/group squid should run as (default: squid/squid).
#   The user and group will be created if they do not already exist using
#   a uid:gid of 100:100.
#   NOTE: before version 2.4.7_11, these settings defaulted to
#   nobody/nogroup.
#   If you wish to keep these settings, please define SQUID_UID=nobody and
#   SQUID_GID=nogroup in your make environment before you start the update.
#   NOTE2:
#   Before version 2.4_12 the numerical id chosen for SQUID_UID (and
#   SQUID_GID respectively) was the first free id greater than or equal 3128.
#   If you wish to move your squid user to id 100:100, run "make changeuser",
#   please see the changeuser target's definition for further information.
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
PORTREVISION=	13
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

DEPRECATED=	This version no longer supported and contains vulnerabilities
EXPIRATION_DATE=2004-11-31

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.4/bugs/
PATCHFILES=	squid-2.4.STABLE7-url_port.patch \
		squid-2.4.STABLE7-url_escape.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tmseck@netcologne.de
COMMENT=	The successful WWW proxy cache and accelerator

CONFLICTS=	squid-2.[^4]*

GNU_CONFIGURE=	yes
STRIP=		# we need to strip the binaries manually
MAKEFILE=	makefile
USE_PERL5=	yes
USE_REINPLACE=	yes

LATEST_LINK=	squid24

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
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
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
.if !defined(WITHOUT_SQUID_UNDERSCORES)
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
# --enable-truncate
#  Use truncate() rather than unlink()
#
# This option does not yet work on FreeBSD:
#
# --enable-ipf-transparent
#  Enable Transparent Proxy support for IP-Filter systems (incl 3.0)
#  (IPFilter headers are not currently installed to the base system,
#  PRs ports/60700 and misc/44148 describe the problem; see
#  http://www.squid-cache.org/Doc/FAQ/FAQ-17.html for information
#  about how to do transparent proxying with ipfw)
#
# --enable-ssl
#  This does not build anymore with recent OpenSSL versions

CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"
post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

pre-configure:
	@${REINPLACE_CMD} -e 's|%%SQUID_UID%%|${SQUID_UID}|g' \
	    -e 's|%%SQUID_GID%%|${SQUID_GID}|g' ${WRKSRC}/src/cf.data.pre

pre-install:
# Prevent installation of .orig files by deleting them.
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    -e 's|%%SQUID_UID%%|${SQUID_UID}|g' ${FILESDIR}/squid.sh \
	    >${WRKDIR}/squid.sh

pre-su-install:
	@${SETENV} squid_user=${SQUID_UID} squid_group=${SQUID_GID} \
	    PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if defined(WITH_SQUID_PINGER)
	cd ${WRKSRC}/src && make install-pinger
	${CHMOD} 4510 ${PREFIX}/libexec/squid/pinger
	${CHGRP} ${SQUID_GID} ${PREFIX}/libexec/squid/pinger
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${docs} ${DOCSDIR}
.endif
	-cd ${PREFIX}/libexec/squid && ${STRIP_CMD} ${libexec}
	-cd ${PREFIX}/sbin && ${STRIP_CMD} ${sbin}
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

changeuser:
# Recover from the problem that earlier versions of this port created the
# squid pseudo-user with an id greater than 999 which is not allowed in
# FreeBSD's ports system. The port now uses id 100:100.
# NOTE:
# This target assumes that SQUID_GID is the primary group of SQUID_UID. If you
# have a different setup, do not run this target!
.if ${SQUID_UID:L} == nobody
	@${ECHO_CMD} "'nobody' is a system user, you do not need to execute"; \
	${ECHO_CMD} "this target!"
	exit 1
.endif
	@if [ `${ID} -u` -ne 0 ]; \
	then ${ECHO_CMD} "Sorry, you must be root to use this target."; exit 1; fi; \
	current_uid=`id -u ${SQUID_UID}`; \
	current_gid=`pw groupshow ${SQUID_GID}|cut -f 3 -d :`; \
	${ECHO_CMD} "I will remove this user:"; \
	${ID} -P $${current_uid}; \
	${ECHO_CMD} "and this group:"; \
	pw groupshow ${SQUID_GID}; \
	${ECHO_CMD} "I will then re-create them with a user and group id of 100."; \
	${ECHO_CMD} "Then all files and directories under ${PREFIX} and /var that"; \
	${ECHO_CMD} "are owned by uid $${current_uid} will be chown(1)'ed."; \
	${ECHO_CMD} "After that, all files and directories that were accessible"; \
	${ECHO_CMD} "by group $${current_gid} will chgrp(1)'ed respectively."; \
	${ECHO_CMD} "Note that this assumes group '${SQUID_GID}' to be the primary"; \
	${ECHO_CMD} "group of user '${SQUID_UID}'. If you have a different setup"; \
	${ECHO_CMD} "please abort this target now."; \
	read -p "Press RETURN to continue or CTRL-C to abort:" dummy ; \
	${ECHO_CMD} "OK, here we go:"; \
	${ECHO_CMD} "deleting user $${current_uid} and his primary group..."; \
	pw userdel -u $${current_uid}; \
	${ECHO_CMD} "adding user ${SQUID_UID} with id 100..."; \
	pw groupadd -n ${SQUID_GID} -g 100; \
	pw useradd -n ${SQUID_UID} -u 100 -c "squid caching-proxy pseudo user" \
	    -d ${PREFIX}/squid -s /sbin/nologin -h - ; \
	${ECHO_CMD} "chown(1)'ing everything under ${PREFIX} from $${current_uid} to 100..."; \
	${FIND} -H ${PREFIX} -user $${current_uid} -exec ${CHOWN} 100 {} \; ; \
	${ECHO_CMD} "chgrp(1)'ing everything under ${PREFIX} from $${current_gid} to 100..."; \
	${FIND} -H ${PREFIX} -group $${current_gid} -exec ${CHOWN} :100 {} \; ; \
	${ECHO_CMD} "chown(1)'ing everything under /var from $${current_uid} to 100..."; \
	${FIND} -H /var -user $${current_uid} -exec ${CHOWN} 100 {} \; ; \
	${ECHO_CMD} "chgrp(1)'ing everything under /var from $${current_gid} to 100..."; \
	${FIND} -H /var -group $${current_gid} -exec ${CHOWN} :100 {} \; ; \
	${ECHO_CMD} "Finished."

.include <bsd.port.post.mk>
