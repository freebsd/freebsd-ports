# Created by: jeff@cetlink.net
# $FreeBSD$

PORTNAME=	tcptraceroute
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://michael.toren.net/code/tcptraceroute/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Traceroute implementation using TCP packets

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

MAN8=	tcptraceroute.8

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

post-patch:
	@${REINPLACE_CMD} -e 's|libnet-config|${LIBNET_CONFIG}|' \
		${WRKSRC}/${MAKEFILE}

post-install:
	@${CHMOD} u+s ${PREFIX}/sbin/tcptraceroute

.include <bsd.port.mk>
