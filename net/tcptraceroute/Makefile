# New ports collection makefile for:   tcptraceroute
# Date created:        21 March 2002
# Whom:                jeff@cetlink.net
#
# $FreeBSD$
#

PORTNAME=	tcptraceroute
PORTVERSION=	1.4
CATEGORIES=	net
MASTER_SITES=	http://michael.toren.net/code/tcptraceroute/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A traceroute implementation using TCP packets

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

MAN8=	tcptraceroute.8

post-install:
	@${CHMOD} u+s ${PREFIX}/sbin/tcptraceroute

.include <bsd.port.mk>
