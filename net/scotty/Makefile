# New ports collection makefile for:	scotty
# Version required:	2.1.3
# Date created:		18 Februar 1995
# Whom:			Gennady Sorokopud <gena@netvision.net.il>
#
# $Id: Makefile,v 1.11 1996/09/17 12:50:34 erich Exp $
#

DISTNAME=	scotty-2.1.3
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --with-tcl-config=/usr/libdata/tcl \
		--with-tk-config=/usr/local/lib

WRKSRC=${WRKDIR}/${DISTNAME}/unix

pre-install:
	@cd ${WRKSRC};make sinstall
	@cp ${WRKSRC}/../tnm/ntping/ntping.8 ${WRKSRC}/../doc
	@sed "s,@FREEBSD_VERSION@,$$(uname -m)-$$(uname)-$$(uname -r)," pkg/PLIST.in >/tmp/PLIST
.if defined(NOMANCOMPRESS)
	@sed "s,@GZIP@,," /tmp/PLIST >pkg/PLIST
.else
	@sed "s,@GZIP@,.gz," /tmp/PLIST >pkg/PLIST
.endif
	@rm /tmp/PLIST

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/tkined.1
	gzip -9nf ${PREFIX}/man/man1/scotty.1
	gzip -9nf ${PREFIX}/man/man8/ntping.8
	gzip -9nf ${PREFIX}/man/man8/straps.8
	gzip -9nf ${PREFIX}/man/mann/Tnm.n
	gzip -9nf ${PREFIX}/man/mann/cmip.n
	gzip -9nf ${PREFIX}/man/mann/dns.n
	gzip -9nf ${PREFIX}/man/mann/gdmo.n
	gzip -9nf ${PREFIX}/man/mann/http.n
	gzip -9nf ${PREFIX}/man/mann/icmp.n
	gzip -9nf ${PREFIX}/man/mann/ined.n
	gzip -9nf ${PREFIX}/man/mann/job.n
	gzip -9nf ${PREFIX}/man/mann/mib.n
	gzip -9nf ${PREFIX}/man/mann/msqltcl.n
	gzip -9nf ${PREFIX}/man/mann/netdb.n
	gzip -9nf ${PREFIX}/man/mann/ntp.n
	gzip -9nf ${PREFIX}/man/mann/rpc.n
	gzip -9nf ${PREFIX}/man/mann/snmp.n
	gzip -9nf ${PREFIX}/man/mann/sunrpc.n
	gzip -9nf ${PREFIX}/man/mann/syslog.n
	gzip -9nf ${PREFIX}/man/mann/udp.n
.endif

pre-clean:
	@rm -f pkg/PLIST

.include <bsd.port.mk>
