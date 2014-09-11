# $FreeBSD$

PORTNAME=	sie-nmsg
PORTVERSION=	0.17.0
PORTREVISION=	1
CATEGORIES=	net dns
MASTER_SITES=	https://dl.farsightsecurity.com/dist/sie-nmsg/ \
		http://dl.farsightsecurity.com/dist/sie-nmsg/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	SIE message module plugin for libnmsg

LICENSE=	APACHE20

LIB_DEPENDS=	libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c \
		libnmsg.so:${PORTSDIR}/net/nmsg \
		libwdns.so:${PORTSDIR}/dns/wdns

GNU_CONFIGURE=	yes
USES=	gmake libtool pathfix pkgconfig

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
