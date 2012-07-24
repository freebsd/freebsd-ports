# New ports collection makefile for:	tcpproxy
# Date created:				2011-03-30
# Whom:					Alexander Hausner <alex@hugo.bmg.gv.at>
#
# $FreeBSD$
#

PORTNAME=	tcpproxy
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.spreadspace.org/tcpproxy/releases/ \
		http://alex.bmg.gv.at/programs/

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	A simple TCP connection proxy for IPv4 and IPv6

BUILD_DEPENDS=	ragel:${PORTSDIR}/devel/ragel

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

USERS=	_tcpproxy
GROUPS=	_tcpproxy

MAN8=	tcpproxy.8

USE_RC_SUBR=	tcpproxy

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

PLIST_FILES=	bin/tcpproxy etc/tcpproxy_sample.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpproxy ${PREFIX}/bin
	${INSTALL_DATA}  ${WRKDIR}/${PORTNAME}-${PORTVERSION}/contrib/example.conf ${PREFIX}/etc/tcpproxy_sample.conf
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc/${MAN8} ${PREFIX}/man/man8

.include <bsd.port.mk>
