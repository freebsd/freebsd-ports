# New ports collection makefile for:	squid
# Version required:	1.2-beta22
# Date created:		Thu Nov  7 00:53:18 WST 1996
# Whom:			Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.50 1998/04/26 07:57:20 peter Exp $
#

DISTNAME=	squid-1.2.beta22
PKGNAME=	squid-1.2b22
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-1.2.beta/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-1.2.beta/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-1.2.beta/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-1.2.beta/
EXTRACT_SUFX=	-src.tar.gz

#PATCH_SITES+=   http://squid.nlanr.net/Squid/1.2.beta/
#PATCHFILES+=    1.2.beta21-1.patches

MAINTAINER=	peter@freebsd.org

DIST_SUBDIR=	squid1.2b22
GNU_CONFIGURE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin  --sysconfdir=${PREFIX}/etc/squid \
		--localstatedir=${PREFIX}/squid
STRIP=		# won't install scripts correctly othervise.
MAKEFILE=	makefile
NO_LATEST_LINK=	yes

# Some other configure options..
#  - Compile and use the malloc package from Doug Lea
#CONFIGURE_ARGS+= --enable-dlmalloc
#  - Compile and use the supplied GNUregex routines instead of BSD regex.
#CONFIGURE_ARGS+= --enable-gnuregex
#  - Use tree function to store ACL lists
#CONFIGURE_ARGS+= --enable-splaytree
#  - Enable simple malloc debugging
#CONFIGURE_ARGS+= --enable-xmalloc-debug
#  - Detailed trace of memory allocations
#CONFIGURE_ARGS+= --enable-xmalloc-debug-count
#  - Show malloc statistics in cachemgr status pages
#CONFIGURE_ARGS+= --enable-xmalloc-statistics
#  - Use ASYNC disk I/O (Requires real pthreads)
#CONFIGURE_ARGS+= --enable-async-io
#  - Enable ICMP pinging for heirarchy stats and selection
#CONFIGURE_ARGS+= --enable-icmp
#  - Enable delay hack to limit bandwidth usage
#CONFIGURE_ARGS+= --enable-delay-hack
#  - Enable generic memory use tracing
#CONFIGURE+ARGS+= --enable-mem-gen-trace
#  - Enable logging of the User-Agent header
#CONFIGURE_ARGS+= --enable-useragent-log
#  - Kill parent (eg: RunCache) on shutdown (use with great care!!)
#CONFIGURE_ARGS+= --enable-kill-parent
#  - Turn on SNMP server support
#CONFIGURE_ARGS+= --enable-snmp
#  - Optimize time updates to one per second rather than calling gettimeofday()
#CONFIGURE_ARGS+= --enable-time-hack
#  - Set an explicit hostname in cachemgr.cgi
#CONFIGURE_ARGS+= --enable-cachemgr-hostname=some.hostname
#  - Enable ACL based on ethernet address (eg: for machines with dynamic DHCP 
#    assigned IP addresses)
#CONFIGURE_ARGS+= --enable-arp-acl

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
		echo "Installing ${PREFIX}/etc/rc.d/squid.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/squid.sh; \
		echo "if [ -x /usr/local/sbin/RunCache -a -f /usr/local/etc/squid/squid.conf ]; then" >> ${PREFIX}/etc/rc.d/squid.sh; \
		echo "	(cd /tmp; /usr/local/sbin/RunCache >/dev/null 2>&1 &) ; echo -n ' squid'" >> ${PREFIX}/etc/rc.d/squid.sh; \
		echo "fi" >> ${PREFIX}/etc/rc.d/squid.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/squid.sh; \
	fi

.include <bsd.port.mk>

# Put on peril sensitive sunglasses in case of stupid GNU make v2.5!
PATCH:=         env POSIXLY_CORRECT=yes ${PATCH}
