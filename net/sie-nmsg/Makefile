# $FreeBSD$

PORTNAME=	sie-nmsg
PORTVERSION=	0.16
CATEGORIES=	net dns
MASTER_SITES=	https://dl.farsightsecurity.com/dist/sie-nmsg/

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	SIE message module plugin for libnmsg

LICENSE=	APACHE20

LIB_DEPENDS=	libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c \
		libnmsg.so:${PORTSDIR}/net/nmsg \
		libwdns.so:${PORTSDIR}/dns/wdns

GNU_CONFIGURE=	yes
USES=	gmake libtool pathfix pkgconfig

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nmsg/nmsg_msg8_sie.so

.include <bsd.port.mk>
