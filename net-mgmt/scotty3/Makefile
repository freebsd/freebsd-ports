# New ports collection makefile for:	scotty
# Version required:	2.1.3
# Date created:		18 Februar 1995
# Whom:			Gennady Sorokopud <gena@netvision.net.il>
#
# $Id: Makefile,v 1.12 1996/10/10 14:54:36 erich Exp $
#

DISTNAME=	scotty-2.1.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

LIB_DEPENDS=	tk41\\.1\\.:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --with-tcl-config=/usr/libdata/tcl \
		--with-tk-config=/usr/local/lib

WRKSRC=${WRKDIR}/${DISTNAME}/unix
MAN1=		tkined.1 scotty.1
MAN8=		ntping.8 straps.8
MANN=		Tnm.n cmip.n dns.n gdmo.n http.n icmp.n ined.n job.n \
		mib.n msqltcl.n netdb.n ntp.n rpc.n snmp.n sunrpc.n \
		syslog.n udp.n

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

pre-clean:
	@rm -f pkg/PLIST

.include <bsd.port.mk>
