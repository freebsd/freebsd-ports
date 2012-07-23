# New ports collection makefile for:	daq
# Date created:		13 January 2011
# Whom:			Dean Freeman (wfreeman@sourcefire.com)
#
# $FreeBSD$
#

PORTNAME=	daq
PORTVERSION=	1.1.1
CATEGORIES=	net
MASTER_SITES=	SF/snort/snort \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Data Acquisition abstraction library for snort 2.9+

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	dnet:${PORTSDIR}/net/libdnet \
		pcap:${PORTSDIR}/net/libpcap
BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_BISON=	build
USE_AUTOTOOLS=	libtool

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
