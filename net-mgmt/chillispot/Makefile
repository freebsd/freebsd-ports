# New ports collection makefile for:   Chillispot
# Date created:                19 October 2005
# Whom:                        Sevan Janiyan <venture37@geeklan.co.uk>
#
# $FreeBSD$
#

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

OPTIONS=	RAW "Latest Release Of Apache & mySQL" Off \
		MATURE "Stable Releases of Apache with mod_ssl &  MySQL" Off \
		FREE "freeRADIUS" Off \
		OPENR "openradius" Off

.include <bsd.port.pre.mk>

.if defined(WITH_RAW)
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache20 \
	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql50-server
.endif

.if defined(WITH_MATURE)
RUN_DEPENDS+=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13-modssl \
	${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql41-server
.endif

.if defined(WITH_FREE)
RUN_DEPENDS+=	radiusd:${PORTSDIR}/net/freeradius
.endif

.if defined(WITH_OPENR)
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

.include <bsd.port.post.mk>
