# New ports collection makefile for:	squid
# Version required:	1.1.beta19
# Date created:		Thu Nov  7 00:53:18 WST 1996
# Whom:			Peter Wemm <peter@freebsd.org>
#
# $Id: Makefile,v 1.7 1996/11/15 12:41:53 peter Exp $
#

DISTNAME=	squid-1.1.beta19
PKGNAME=	squid-1.1b19
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-1.1.beta/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-1.1.beta/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-1.1.beta/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-1.1.beta/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	peter@freebsd.org

GNU_CONFIGURE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/squid --bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/sbin --localstatedir=${PREFIX}/squid
STRIP=		# won't install scripts correctly othervise.
MAKEFILE=	makefile

post-install:
.for file in cachemgr.cgi client dnsserver ftpget pinger squid
	strip ${PREFIX}/sbin/${file}
.endfor
	${MKDIR} -p ${PREFIX}/squid/logs
	${MKDIR} -p ${PREFIX}/squid/cache
	@if [ ! -f ${PREFIX}/etc/rc.d/squid.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/squid.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/squid.sh; \
		echo "if [ -x /usr/local/sbin/RunCache -a -f /usr/local/etc/squid/squid.conf ]; then" >> ${PREFIX}/etc/rc.d/squid.sh; \
		echo "	(cd /tmp; /usr/local/sbin/RunCache >/dev/null 2>&1 &) ; echo -n ' squid'" >> ${PREFIX}/etc/rc.d/squid.sh; \
		echo "fi" >> ${PREFIX}/etc/rc.d/squid.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/squid.sh; \
	fi

.include <bsd.port.mk>
