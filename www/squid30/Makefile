# New ports collection makefile for:	squid24
# Date created:		Tue Mar 27 14:56:08 CEST 2001
# Whom:			Adrian Chadd <adrian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	squid
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=  \
	ftp://ftp.squid-cache.org/pub/%SUBDIR%/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/%SUBDIR%/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/%SUBDIR%/ \
	ftp://ftp.net.lut.ac.uk/squid/%SUBDIR%/ \
	${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/squid/&,}
MASTER_SITE_SUBDIR=	squid-2/STABLE
DISTNAME=	squid-2.5.STABLE1
EXTRACT_SUFX=	.tar.gz

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE1-disable-ident-lookups.patch \
		squid-2.5.STABLE1-disable-http-violations.patch \
		squid-2.5.STABLE1-proxy_auth.patch \
		squid-2.5.STABLE1-max_user_ip.patch \
		squid-2.5.STABLE1-cache_dir_docs.patch \
		squid-2.5.STABLE1-load_icons.patch \
		squid-2.5.STABLE1-referer_log.patch \
		squid-2.5.STABLE1-ldap_auth.patch \
		squid-2.5.STABLE1-addlang.patch \
		squid-2.5.STABLE1-pthreads.patch \
		squid-2.5.STABLE1-strwordtok.patch \
		squid-2.5.STABLE1-wccp.patch \
		squid-2.5.STABLE1-memstat.patch \
		squid-2.5.STABLE1-aufs.patch \
		squid-2.5.STABLE1-acl_leak.patch \
		squid-2.5.STABLE1-ext_acl_comma.patch \
		squid-2.5.STABLE1-request_entity.patch \
		squid-2.5.STABLE1-ext_acl_exit.patch \
		squid-2.5.STABLE1-uninstall.patch \
		squid-2.5.STABLE1-cachemgr.patch \
		squid-2.5.STABLE1-auth-proxy.patch \
		squid-2.5.STABLE1-dnsserver.patch \
		squid-2.5.STABLE1-spaces.patch \
		squid-2.5.STABLE1-flags_open.patch \
		squid-2.5.STABLE1-ldap_group-compile.patch \
		squid-2.5.STABLE1-aufs_performance.patch \
		squid-2.5.STABLE1-RunCache.patch \
		squid-2.5.STABLE1-rebuild_assert.patch \
		squid-2.5.STABLE1-offline_mode.patch \
		squid-2.5.STABLE1-S.patch \
		squid-2.5.STABLE1-chroot.patch \
		squid-2.5.STABLE1-aufs_reentrant.patch\
		squid-2.5.STABLE1-relnote11.patch \
		squid-2.5.STABLE1-ldap_group.patch \
		squid-2.5.STABLE1-offline_toggle.patch \
		squid-2.5.STABLE1-failure_ratio.patch \
		squid-2.5.STABLE1-hostnames.patch \
		squid-2.5.STABLE1-sbrk.patch \
		squid-2.5.STABLE1-log_mime_hdrs.patch \
		squid-2.5.STABLE1-peer_select_alg.patch \
		squid-2.5.STABLE1-mempoolstat.patch \
		squid-2.5.STABLE1-copy_offset.patch \
		squid-2.5.STABLE1-select_fds_hist.patch \
		squid-2.5.STABLE1-select_stat.patch \
		squid-2.5.STABLE1-pidfile.patch \
		squid-2.5.STABLE1-http_reply_max_size.patch \
		squid-2.5.STABLE1-cachemgr_non_get.patch \
		squid-2.5.STABLE1-authsheme_realloc.patch \
		squid-2.5.STABLE1-ftp_abort.patch \
		squid-2.5.STABLE1-helper_stats.patch \
		squid-2.5.STABLE1-delay_pools_docs.patch \
		squid-2.5.STABLE1-auth_connection.patch \
		squid-2.5.STABLE1-authenticate_program_docs.patch \
		squid-2.5.STABLE1-with_aufs_threads_trap.patch \
		squid-2.5.STABLE1-shutdown_assert.patch \
		squid-2.5.STABLE1-cachemgr_passwd.patch \
		squid-2.5.STABLE1-etc_hosts_fdleak.patch \
		squid-2.5.STABLE1-openssl097.patch \
		squid-2.5.STABLE1-HEAD_bad_headers.patch \
		squid-2.5.STABLE1-time_acl_list.patch \
		squid-2.5.STABLE1-CONNECT_pipeline.patch \
		squid-2.5.STABLE1-winbind.patch \
		squid-2.5.STABLE1-mib.patch \
		squid-2.5.STABLE1-error-http-ident.patch \
		squid-2.5.STABLE1-distclean_icons.patch \
		squid-2.5.STABLE1-external_acl_auth_segfault.patch \
		squid-2.5.STABLE1-auth_digest.patch \
		squid-2.5.STABLE1-external_acl_user.patch

MAINTAINER=	adrian@freebsd.org
COMMENT=	The successful WWW proxy cache and accelerator

DIST_SUBDIR=	squid2.5
PATCH_DIST_STRIP= -p1
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin  --sysconfdir=${PREFIX}/etc/squid \
		--datadir=${PREFIX}/etc/squid/ \
		--localstatedir=${PREFIX}/squid \
		--enable-storeio="ufs diskd null" \
		--enable-removal-policies="lru heap" \
		--enable-auth=basic --enable-basic-auth-helpers="NCSA PAM YP" \
		--enable-external-acl-helpers="ip_user unix_group" \
		--enable-underscores

STRIP=		# won't install scripts correctly otherwise.
MAKEFILE=	Makefile

# Some other configure options..
#  - Compile and use the malloc package from Doug Lea
#CONFIGURE_ARGS+= --enable-dlmalloc
#  - Compile and use the supplied GNUregex routines instead of BSD regex.
#CONFIGURE_ARGS+= --enable-gnuregex
#  - Enable simple malloc debugging
#CONFIGURE_ARGS+= --enable-xmalloc-debug
#  - Detailed trace of memory allocations
#CONFIGURE_ARGS+= --enable-xmalloc-debug-count
#  - Show malloc statistics in cachemgr status pages
#CONFIGURE_ARGS+= --enable-xmalloc-statistics
#  - Enable CARP support
#CONFIGURE_ARGS+= --enable-carp
#  - Enable ICMP pinging for heirarchy stats and selection
#CONFIGURE_ARGS+= --enable-icmp
#  - Enable delay pools to limit bandwidth usage
#CONFIGURE_ARGS+= --enable-delay-pools
#  - Enable generic memory use tracing
#CONFIGURE_ARGS+= --enable-mem-gen-trace
#  - Enable logging of the User-Agent header
#CONFIGURE_ARGS+= --enable-useragent-log
#  - Disable Web Cache Coordination Protocol
#CONFIGURE_ARGS+= --disable-wccp
#  - Kill parent (eg: RunCache) on shutdown (use with great care!!)
#CONFIGURE_ARGS+= --enable-kill-parent-hack
#  - Turn on SNMP server support
#CONFIGURE_ARGS+= --enable-snmp
#  - Turn on SSL server support for reverse proxies
#CONFIGURE_ARGS+= --enable-ssl
#  - Optimize time updates to one per second rather than calling gettimeofday()
#CONFIGURE_ARGS+= --enable-time-hack
#  - Set an explicit hostname in cachemgr.cgi
#CONFIGURE_ARGS+= --enable-cachemgr-hostname=some.hostname
#  - Enable ACL based on ethernet address (eg: for machines with dynamic DHCP
#    assigned IP addresses)
#CONFIGURE_ARGS+= --enable-arp-acl
#  - Enable HTCP protocol
#CONFIGURE_ARGS+= --enable-htcp
#  - Enable Forw/Via database
#CONFIGURE_ARGS+= --enable-forw-via-db
#  - Use Cache Digests - see http://squid.nlanr.net/Squid/FAQ/FAQ-16.html
#CONFIGURE_ARGS+= --enable-cache-digests
#  - Select language for Error pages (see errors dir)
#CONFIGURE_ARGS+= --enable-err-language=lang
#  (--enable-poll is not needed, it's detected correctly on 3.0)
#  - Strict HTTP compliance
#CONFIGURE_ARGS+= --disable-http-violations
#  - Enable Transparent Proxy support for IP-Filter systems (incl 3.0)
#CONFIGURE_ARGS+= --enable-ipf-transparent
# (--enable-leakfinder is a developer support tool only)
#  - Compile out code that does optional Ident (RFC931) lookups
#CONFIGURE_ARGS+= --disable-ident-lookups
#  - Disable squid's internal async DNS lookup code.
#CONFIGURE_ARGS+= --disable-internal-dns
#  - Use truncate() rather than unlink()
#CONFIGURE_ARGS+= --enable-truncate
#  - accept the illegal '_' character in hostnames.
#CONFIGURE_ARGS+= --enable-underscores
#  - Enable control of different heap replacement algorithms at runtime.
#CONFIGURE_ARGS+= --enable-heap-replacement

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
#	I don't think many people use the pinger nowadays, and if you
#	do you'll want squid in its own group so as to restrict access
#	to it.
#	cd ${WRKSRC}/src; make install-pinger
.for file in client squid
	if [ -f ${PREFIX}/sbin/${file} ] ; then \
		strip ${PREFIX}/sbin/${file} ; \
	fi
.endfor
.for file in cachemgr.cgi dnsserver pinger unlinkd
	if [ -f ${PREFIX}/libexec/${file} ] ; then \
		strip ${PREFIX}/libexec/${file} ; \
	fi
.endfor
	@if [ ! -d ${PREFIX}/squid/logs ]; then			\
		${MKDIR} ${PREFIX}/squid/logs;		  	\
		${CHOWN} nobody:nogroup ${PREFIX}/squid/logs;   \
	fi
	@if [ ! -d ${PREFIX}/squid/cache ]; then		\
		${MKDIR} ${PREFIX}/squid/cache;			\
		${CHOWN} nobody:nogroup ${PREFIX}/squid/cache;  \
	fi
	@if [ ! -f ${PREFIX}/etc/rc.d/squid.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/squid.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/squid.sh ${PREFIX}/etc/rc.d/squid.sh; \
	fi

.include <bsd.port.mk>
