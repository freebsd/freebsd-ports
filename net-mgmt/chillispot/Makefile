# Created by: Sevan Janiyan <venture37@geeklan.co.uk>
# $FreeBSD$

PORTNAME=	chillispot
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.chillispot.info/download/ \
		http://www.geeklan.co.uk/files/ \
		http://www.venture37.com/files/

MAINTAINER=	venture37@geeklan.co.uk
COMMENT=	Wireless LAN Access Point Controller

CONFLICTS=	coovachilli-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=-sysconfdir=${PREFIX}/etc
USE_RC_SUBR=	chillispot
SUB_FILES=	pkg-message installguide.txt
MAN8=		chilli.8
USE_GCC=	any

OPTIONS_DEFINE=	APACHE RADIUS
OPTIONS_SINGLE=	RADIUS
OPTIONS_SINGLE_RADIUS= FREERADIUS OPENRADIUS

FREERADIUS_DESC=depend on FreeRADIUS
OPENRADIUS_DESC=depend on OpenRADIUS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MFREERADIUS}
RUN_DEPENDS+=	radiusd:${PORTSDIR}/net/freeradius
.endif

.if ${PORT_OPTIONS:MOPENRADIUS}
RUN_DEPENDS+=	radiusd:${PORTSDIR}/net/openradius
.endif

post-install:
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/chilli.conf ${DATADIR}/chilli.conf.sample
	${INSTALL_MAN} ${WRKSRC}/doc/dictionary.chillispot ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/freeradius.users ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/hotspotlogin.cgi ${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/installguide.txt ${DATADIR}
	${INSTALL_MAN} ${FILESDIR}/pf.conf.sample ${DATADIR}
	${INSTALL_MAN} ${FILESDIR}/ipfw-config.sample ${DATADIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
