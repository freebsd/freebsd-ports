#
# $Id: Makefile,v 1.33 1998/12/22 04:22:12 asami Exp $
#

DISTNAME=	scotty-2.1.9
CATEGORIES=	net tk80
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	phk@freebsd.org

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

BROKEN_ELF=	'Error in startup script: couldnt load file "/usr/local/lib/tkined1.4.9.so": /usr/local/lib/tkined1.4.9.so: Undefined symbol "Tk_CanvasTagsParseProc"'

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --with-tcl-config=/usr/local/lib/tcl8.0 \
		--with-tk-config=/usr/local/lib/tk8.0


WRKSRC=${WRKDIR}/${DISTNAME}/unix
MAN1=		tkined.1 scotty.1
MAN8=		ntping.8 straps.8
MANN=		Tnm.n cmip.n dns.n gdmo.n http.n icmp.n ined.n job.n \
		mib.n msqltcl.n netdb.n ntp.n rpc.n snmp.n sunrpc.n \
		syslog.n udp.n
PLIST_SUB=	FREEBSD_VERSION=${FREEBSD_VERSION} \
		SCOTTY_VERSION=2.1.9 TKINED_VERSION=1.4.9
FREEBSD_VERSION!=	echo `uname -m`-`uname`-`uname -r`

pre-install:
	@cd ${WRKSRC};make sinstall
	@${CP} ${WRKSRC}/../tnm/ntping/ntping.8 ${WRKSRC}/../doc

.include <bsd.port.mk>
