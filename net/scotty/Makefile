# New ports collection makefile for:	scotty
# Date created:		18 February 1995
# Whom:			Gennady Sorokopud <gena@netvisions.net.il>
#
# $FreeBSD$
#

PORTNAME=	scotty
PORTVERSION=	2.1.10
CATEGORIES=	net tk82
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/

MAINTAINER=	dima@Chg.RU

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--with-tcl-config=${LOCALBASE}/tcl8.2 \
		--with-tk-config=${LOCALBASE}/lib/tk8.2

WRKSRC=${WRKDIR}/${DISTNAME}/unix
MAN1=		tkined.1 scotty.1
MAN8=		ntping.8 straps.8
MANN=		Tnm.n cmip.n dns.n gdmo.n http.n icmp.n ined.n job.n \
		mib.n netdb.n ntp.n rpc.n snmp.n sunrpc.n \
		syslog.n udp.n
PLIST_SUB=	FREEBSD_VERSION=${FREEBSD_VERSION} \
		SCOTTY_VERSION=2.1.10 TKINED_VERSION=1.4.10
FREEBSD_VERSION!=	${ECHO} `uname -m`-`uname`-`uname -r`

pre-install:
	@cd ${WRKSRC};make sinstall
	@${CP} ${WRKSRC}/../tnm/ntping/ntping.8 ${WRKSRC}/../doc

.include <bsd.port.mk>
