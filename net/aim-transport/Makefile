# New ports collection makefile for:	aim-transport
# Date created:				04 December 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	aim-transport
PORTVERSION=	0.9.0
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/1.4/final/

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

BUILD_DEPENDS=	${NONEXISTENT}:${JABBER_PORT}:configure
RUN_DEPENDS=	jabberd:${JABBER_PORT}

.include <bsd.port.pre.mk>

JABBER_PORT=	${PORTSDIR}/net/jabber
JABBER_WRKSRC!=	cd ${JABBER_PORT} && ${MAKE} -V WRKSRC
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jabberd=${JABBER_WRKSRC}/jabberd

do-install:
	@${MKDIR} ${PREFIX}/lib/jabber/${PORTNAME}
	@${INSTALL_PROGRAM} ${WRKSRC}/src/aimtrans.so ${PREFIX}/lib/jabber/${PORTNAME}
	@${ECHO} ""
	@${ECHO} "============================================================================="
	@${ECHO} "Please read ${WRKSRC}/README first"
	@${ECHO} "and add \"./${PORTNAME}/aimtrans.so\" into ${PREFIX}/etc/jabber.xml"
	@${ECHO} "then restart jabberd to enable ${PORTNAME}"
	@${ECHO} "============================================================================="
	@${ECHO} ""

.include <bsd.port.post.mk>
