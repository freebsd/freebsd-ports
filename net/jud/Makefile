# New ports collection makefile for:	jud
# Date created:				04 December 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	jud
PORTVERSION=	0.4
CATEGORIES=	net
MASTER_SITES=	http://download.jabber.org/dists/1.4/final/

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

BUILD_DEPENDS=	${NONEXISTENT}:${JABBER_PORT}:configure
RUN_DEPENDS=	jabberd:${JABBER_PORT}

.include <bsd.port.pre.mk>

JABBER_PORT=	${PORTSDIR}/net/jabber
JABBER_WRKSRC!=	cd ${JABBER_PORT} && ${MAKE} -V WRKSRC
MAKE_ENV=	JABBER_WRKSRC=${JABBER_WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/lib/jabber/${PORTNAME}
	@${INSTALL_PROGRAM} ${WRKSRC}/jud.so ${PREFIX}/lib/jabber/${PORTNAME}
	@${ECHO} ""
	@${ECHO} "============================================================================="
	@${ECHO} "Please read ${WRKSRC}/README first"
	@${ECHO} "and add \"./${PORTNAME}/jud.so\" into ${PREFIX}/etc/jabber.xml"
	@${ECHO} "then restart jabberd to enable ${PORTNAME}"
	@${ECHO} "============================================================================="
	@${ECHO} ""

.include <bsd.port.post.mk>
