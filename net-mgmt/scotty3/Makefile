# New ports collection makefile for:	scotty-current
# Date created:			06 June 2000
# Whom:				Sergey Osokin aka oZZ <ozz@FreeBSD.ORG.ru>
#
# $FreeBSD$
#

PORTNAME=	scotty
PORTVERSION=	20000221
CATEGORIES=	net tk82
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/devel/
DISTNAME=	${PORTNAME}-00-02-21

MAINTAINER=	ozz@FreeBSD.org.ru

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.2 \
		--with-tk=${PREFIX}/lib/tk8.2

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
MAN1=		tkined.1 scotty.1
MAN8=		nmicmpd.8 nmtrapd.8
MANN=		Tnm.n TnmDialog.n TnmDisman.n TnmEther.n TnmIetf.n\
		TnmInet.n TnmMap.n TnmMib.n TnmSnmp.n TnmTerm.n\
		dns.n icmp.n ined.n job.n map.n mib.n netdb.n \
		ntp.n snmp.n sunrpc.n syslog.n udp.n
PLIST_SUB=	SCOTTY_VERSION=3.0.0 TKINED_VERSION=1.5.0

pre-install:
	@cd ${WRKSRC}; make sinstall

.include <bsd.port.mk>
