# New ports collection makefile for:	scotty-current
# Date created:			06 June 2000
# Whom:				Sergey Osokin aka oZZ <ozz@FreeBSD.ORG.ru>
#
# $FreeBSD$
#

PORTNAME=	scotty
PORTVERSION=	20000221
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/tkined/devel/
DISTNAME=	${PORTNAME}-00-02-21

MAINTAINER=	ozz@FreeBSD.org.ru

.ifdef (NO_X)
PKGNAMESUFFIX=	-nox11
LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83
.else
LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${PREFIX}/lib/tcl8.3 \
		--enable-multicast

.ifdef (NO_X)
CONFIGURE_ARGS+=--with-tk=no
.else
CONFIGURE_ARGS+=--with-tk=${PREFIX}/lib/tk8.3
CONFIGURE_ENV+=	wish=${PREFIX}/bin/wish8.3
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
MAN1=		scotty.1
MAN8=		nmicmpd.8 nmtrapd.8
MANN=		Tnm.n TnmDialog.n TnmDisman.n TnmEther.n TnmIetf.n\
		TnmInet.n TnmMap.n TnmMib.n TnmSnmp.n TnmTerm.n\
		dns.n icmp.n job.n map.n mib.n netdb.n \
		ntp.n snmp.n sunrpc.n syslog.n udp.n
PLIST_SUB=	SCOTTY_VERSION=3.0.0 TKINED_VERSION=1.5.0

MAKE_ARGS+=	-j2	# better than -j1 on all machines...
INSTALL_TARGET=	tnm-install sinstall

.if !defined(NO_X)
MAN1+=		tkined.1
MANN+=		ined.n
PLIST_SUB+=	X11=''
INSTALL_TARGET+=tki-install
.else
PLIST_SUB+=	X11='@comment '
.endif

post-patch:
	${MV} ${WRKSRC}/scotty.c ${WRKSRC}/scotty.c.orig
	${CP} -p ${FILESDIR}/scotty.c ${WRKSRC}/scotty.c

post-install:
	${RM} -f ${PREFIX}/bin/scotty ${PREFIX}/bin/tkined
	${LN} -s scotty3.0.0 ${PREFIX}/bin/scotty
.ifndef NO_X
	${LN} -s tkined1.5.0 ${PREFIX}/bin/tkined
.endif

.include <bsd.port.mk>
