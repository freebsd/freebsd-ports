# New ports collection makefile for:	squid
# Version required:	1.1.5
# Date created:		Thu Nov  7 00:53:18 WST 1996
# Whom:			Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.19 1997/01/24 10:30:38 asami Exp $
#

DISTNAME=	squid-1.1.5
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-1.1/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-1.1/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-1.1/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-1.1/
EXTRACT_SUFX=	-src.tar.gz

PATCH_SITES+=   http://squid.nlanr.net/Squid/1.1/1.1.5/
PATCHFILES+=    acl.c.patch main.c.patch redirect.c.patch

MAINTAINER=	peter@freebsd.org

DIST_SUBDIR=	squid
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
#MAKE_ENV+=	ANON_OPT="-DUSE_ANONYMIZER"

post-install:
.for file in cachemgr.cgi client dnsserver ftpget pinger squid
	strip ${PREFIX}/sbin/${file}
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
