# New ports collection makefile for:	squid
# Version required:	1.2-beta8
# Date created:		Thu Nov  7 00:53:18 WST 1996
# Whom:			Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.34 1997/11/01 11:10:35 peter Exp $
#

DISTNAME=	squid-1.2.beta8
PKGNAME=	squid-1.2b8
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-1.2.beta/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-1.2.beta/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-1.2.beta/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-1.2.beta/
EXTRACT_SUFX=	-src.tar.gz

PATCH_SITES+=   http://squid.nlanr.net/Squid/1.2.beta/
PATCHFILES+=    1.2.beta8.patches

MAINTAINER=	peter@freebsd.org

DIST_SUBDIR=	squid1.2b8
GNU_CONFIGURE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/squid --bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/sbin --localstatedir=${PREFIX}/squid
STRIP=		# won't install scripts correctly othervise.
MAKEFILE=	makefile

# If you need to set any of these options, read the source and uncomment
# these if appropriate.
#MAKE_ENV+=	HOST_OPT="-DCACHEMGR_HOSTNAME=\"getfullhostname()\""
#MAKE_ENV+=	ICMP_OPT="-DUSE_ICMP=1"
#MAKE_ENV+=	DELAY_HACK="-DDELAY_HACK=1"
#MAKE_ENV+=	USERAGENT_OPT="-DUSE_USERAGENT_LOG=1"
#MAKE_ENV+=	KILL_PARENT_OPT="-DKILL_PARENT_OPT"
# do NOT define both USE_SPLAY_TREE and USE_BIN_TREE at the same time!
#MAKE_ENV+=	USE_SPLAY_TREE="-DUSE_SPLAY_TREE"
#MAKE_ENV+=	USE_BIN_TREE="-DUSE_BIN_TREE"
#MAKE_ENV+=	ALARM_UPDATES_TIME="-DALARM_UPDATES_TIME=1"
#MAKE_ENV+=	STORE_KEY_SHA="-DSTORE_KEY_SHA=1"
#MAKE_ENV+=	STORE_KEY_MD5="-DSTORE_KEY_MD5=1"
#MAKE_ENV+=	USE_ASYNC_IO="-DUSE_ASYNC_IO=1"

# To turn on SNMP, uncomment these three.  I'm not sure how this works,
# I think you need some sort of snmp multiplexor if you run another snmp
# server as well.
#MAKE_ENV+=	SQUID_SNMP="-DSQUID_SNMP=1"
#MAKE_ENV+=	SQUID_MIB="mib.txt"
#MAKE_ENV+=	SQUID_SNMP_LIBS="-L../snmplib -lsnmp"


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
