# New ports collection makefile for:	squid
# Date created:		Thu Nov  7 00:53:18 WST 1996
# Whom:			Peter Wemm <peter@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	squid
PORTVERSION=	2.3
CATEGORIES=	www
MASTER_SITES=  \
	ftp://ftp.squid-cache.org/pub/squid-2/STABLE/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-2/STABLE/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-2/STABLE/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-2/STABLE/
DISTNAME=	squid-2.3.STABLE4
EXTRACT_SUFX=	-src.tar.gz

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.3/bugs/
PATCHFILES=	squid-2.3.stable4-ftp_icon_not_found.patch \
		squid-2.3.stable4-internal_dns_rcode_table_formatting.patch \
		squid-2.3.stable4-ipfw_configure.patch \
		squid-2.3.stable4-invalid_ip_acl_entry.patch \
		squid-2.3.stable4-accel_only_access.patch \
		squid-2.3.stable4-html_quoting.patch \
		squid-2.3.stable4-carp-assertion.patch

MAINTAINER=	adrian@freebsd.org

DIST_SUBDIR=	squid2.3
PATCH_DIST_STRIP= -p0
GNU_CONFIGURE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin  --sysconfdir=${PREFIX}/etc/squid \
		--localstatedir=${PREFIX}/squid
STRIP=		# won't install scripts correctly otherwise.
MAKEFILE=	makefile

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
#  - Use ASYNC disk I/O (Requires real threads, apparently runs on 3.0 libc_r)
#CONFIGURE_ARGS+= --enable-async-io
#  - Enable ICMP pinging for heirarchy stats and selection
#CONFIGURE_ARGS+= --enable-icmp
#  - Enable delay pools to limit bandwidth usage
#CONFIGURE_ARGS+= --enable-delay-pools
#  - Enable generic memory use tracing
#CONFIGURE+ARGS+= --enable-mem-gen-trace
#  - Enable logging of the User-Agent header
#CONFIGURE_ARGS+= --enable-useragent-log
#  - Disable Web Cache Coordination Protocol
#CONFIGURE_ARGS+= --disable-wccp
#  - Kill parent (eg: RunCache) on shutdown (use with great care!!)
#CONFIGURE_ARGS+= --enable-kill-parent-hack
#  - Turn on SNMP server support
#CONFIGURE_ARGS+= --enable-snmp
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

post-extract:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
	cd ${WRKSRC}/src; make install-pinger
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
	${MKDIR} ${PREFIX}/squid/logs
	${MKDIR} ${PREFIX}/squid/cache
	@if [ ! -f ${PREFIX}/etc/rc.d/squid.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/squid.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/squid.sh ${PREFIX}/etc/rc.d/squid.sh; \
	fi

.include <bsd.port.mk>
