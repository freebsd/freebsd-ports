# Created by: Dean Freeman (wfreeman@sourcefire.com)
# $FreeBSD$

PORTNAME=	daq
PORTVERSION=	2.0.1
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
USES=		bison
USE_AUTOTOOLS=	libtool
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
