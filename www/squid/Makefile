# New ports collection makefile for:	squid
# Version required:	1.0.20
# Date created:		Fri May 17 04:02:53 EET DST 1996
# Whom:			Andrew Stesin <stesin@elvisti.kiev.ua>
#
# $Id: Makefile,v 1.2 1996/07/10 21:48:58 asami Exp $
#

DISTNAME=	squid-1.0.20
CATEGORIES+=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-1.0/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-1.0/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-1.0/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-1.0/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	stesin@elvisti.kiev.ua

GNU_CONFIGURE=	yes
# Follow the apache port's lead...
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/squid --bindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/sbin --localstatedir=${PREFIX}/squid
STRIP=		# won't install scripts correctly othervise.
MAKEFILE=	makefile

post-install:
.for file in cachemgr.cgi client dnsserver ftpget squid
	strip ${PREFIX}/sbin/${file}
.endfor
	${MKDIR} ${PREFIX}/squid/logs
	${MKDIR} ${PREFIX}/squid/cache
	@if [ ! -f ${PREFIX}/etc/rc.d/squid.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/squid.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/squid.sh; \
		echo "if [ -x /usr/local/sbin/RunCache -a -f /usr/local/etc/squid/squid.conf ]; then" >> ${PREFIX}/etc/rc.d/squid.sh; \
		echo "	(cd /tmp; /usr/local/sbin/RunCache &) ; echo -n ' squid'" >> ${PREFIX}/etc/rc.d/squid.sh; \
		echo "fi" >> ${PREFIX}/etc/rc.d/squid.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/squid.sh; \
	fi

.include <bsd.port.mk>
