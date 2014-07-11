# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfb
PORTVERSION=	2.0.2
CATEGORIES=	net net-mgmt
MASTER_SITES=	http://support.red-fone.com/downloads/fonulator/

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	FoneBRIDGE configuration library

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet

GNU_CONFIGURE=	yes
CPPFLAGS+=	${LIBNET_CPPFLAGS}
LDFLAGS+=	${LIBNET_LIBS:N-l*}
CONFIGURE_ARGS=	--disable-shared

LIBNET_CONFIG=	${LOCALBASE}/bin/libnet11-config

.if 0
# this does not work when LIBNET_CONFIG does not exist prior to building this port
LIBNET_CPPFLAGS!=	${LIBNET_CONFIG} --cflags --defines
LIBNET_LIBS!=		${LIBNET_CONFIG} --libs
.else
LIBNET_CPPFLAGS=	-I${LOCALBASE}/include/libnet11
LIBNET_LIBS=		-L${LOCALBASE}/lib/libnet11
.endif

.include <bsd.port.mk>
