# New ports collection makefile for:	squid
# Version required:	1.2-beta10
# Date created:		Thu Nov  7 00:53:18 WST 1996
# Whom:			Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.35 1997/12/06 12:27:32 peter Exp $
#

DISTNAME=	squid-1.2.beta10
PKGNAME=	squid-1.2b10
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-1.2.beta/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-1.2.beta/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-1.2.beta/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-1.2.beta/
EXTRACT_SUFX=	-src.tar.gz

PATCH_SITES+=   http://squid.nlanr.net/Squid/1.2.beta/
PATCHFILES+=    1.2.beta10.patches

MAINTAINER=	peter@freebsd.org

DIST_SUBDIR=	squid1.2b10
GNU_CONFIGURE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/squid --bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/sbin --localstatedir=${PREFIX}/squid
STRIP=		# won't install scripts correctly othervise.
MAKEFILE=	makefile

# To turn on SNMP, uncomment these three.  I'm not sure how this works,
# I think you need some sort of snmp multiplexor if you run another snmp
# server as well.
#MAKE_ENV+=	SQUID_SNMP="-DSQUID_SNMP=1"
#MAKE_ENV+=	SQUID_MIB="mib.txt"
#MAKE_ENV+=	SQUID_SNMP_LIBS="-L../snmplib -lsnmp"

# Some other configure options..
# - Use hash function as store index, instead of URL (trades CPU for memory)
#CONFIGURE_ARGS+= --enable-hashkey=sha
#CONFIGURE_ARGS+= --enable-hashkey=md5
#  - Use ASYNC disk I/O (Requires pthreads, probably doesn't work yet)
#CONFIGURE_ARGS+= --enable-async-io

# There are several other configurable options in ${WRKSRC}/src/options.h[.in]
# CACHEMGR_HOSTNAME	- alternate method for cachemgr.cgi to get hostname
# USE_ICMP 1		- enable ICMP pings (using pinger) for selecting hosts.
# DELAY_HACK 1		- see code.
# USE_USERAGENT_LOG 1	- log user agents
# KILL_PARENT_OPT 1	- kill parent (such as runcache) on SIGTERM etc.
# USE_SPLAY_TREE 1	- use splay or binary trees for storing and searching
# USE_BIN_TREE 1	  the in-memory cache contents table.
# ALARM_UPDATES_TIME 1	- optimize gettimeofday calls (default on)
# USE_ARP_ACL 1		- enable ethernet hardware address ACL's

post-install:
	cd ${WRKSRC}/src; make install-pinger
.for file in cachemgr.cgi client dnsserver pinger squid
	if [ -f ${PREFIX}/sbin/${file} ] ; then \
		strip ${PREFIX}/sbin/${file} ; \
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
