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

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/libnet10-config:${PORTSDIR}/net/libnet10

post-patch:
	@${REINPLACE_CMD} -e 's|libnet-config|libnet10-config|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
