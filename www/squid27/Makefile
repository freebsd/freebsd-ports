# New ports collection makefile for:	squid
# Version required:	1.1.11
# Date created:		Thu Nov  7 00:53:18 WST 1996
# Whom:			Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.28 1997/05/17 19:54:45 peter Exp $
#

DISTNAME=	squid-1.1.11
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-1.1/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-1.1/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-1.1/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-1.1/
EXTRACT_SUFX=	-src.tar.gz

PATCH_SITES+=   http://squid.nlanr.net/Squid/1.1/1.1.11/
PATCHFILES+=    config.h.in.patch long-dns-coredump.patch

MAINTAINER=	peter@freebsd.org

DIST_SUBDIR=	squid1111
GNU_CONFIGURE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/squid --bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/sbin --localstatedir=${PREFIX}/squid
STRIP=		# won't install scripts correctly othervise.
MAKEFILE=	makefile

# If you need to set any of these options, read the source and uncomment
# these if appropriate.
#MAKE_ENV+=	HOST_OPT="-DCACHEMGR_HOSTNAME=\"getfullhostname()\""
#MAKE_ENV+=	AUTH_OPT="-DUSE_PROXY_AUTH=1"
#MAKE_ENV+=	LOG_HDRS_OPT="-DLOG_FULL_HEADERS=1"
#MAKE_ENV+=	ICMP_OPT="-DUSE_ICMP=1"
#MAKE_ENV+=	DELAY_HACK="-DDELAY_HACK=1"
#MAKE_ENV+=	USERAGENT_OPT="-DUSE_USERAGENT_LOG=1"
#MAKE_ENV+=	KILL_PARENT_OPT="-DKILL_PARENT_OPT"
#MAKE_ENV+=	USE_POLL_OPT="-DUSE_POLL"
# do NOT define both USE_SPLAY_TREE and USE_BIN_TREE at the same time!
#MAKE_ENV+=	USE_SPLAY_TREE="-DUSE_SPLAY_TREE"
#MAKE_ENV+=	USE_BIN_TREE="-DUSE_BIN_TREE"

post-install:
	cd ${WRKSRC}/src; make install-pinger
.for file in cachemgr.cgi client dnsserver ftpget pinger squid
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
