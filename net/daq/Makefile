# New ports collection makefile for:	daq
# Date created:		13 January 2011
# Whom:			Dean Freeman (wfreeman@sourcefire.com)
#
# $FreeBSD$
#

PORTNAME=	daq
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	SF/snort/snort

MAINTAINER=	wfreeman@sourcefire.com
COMMENT=	Data Acquisition abstraction library for snort 2.9+

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet \
		pcap.1:${PORTSDIR}/net/libpcap
BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_BISON=	build

CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
