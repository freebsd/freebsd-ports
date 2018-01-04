# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	snort
DISTVERSION=	3.0.0-a4
CATEGORIES=	security
MASTER_SITES=	https://snort.org/downloads/snortplus/
PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}-3.0.0-239-auto

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11=	Segmentation Fault
BROKEN_FreeBSD_12=	Segmentation Fault

BUILD_DEPENDS=	daq>=2.2.2:net/daq
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libdnet.so:net/libdnet \
		libpcap.so:net/libpcap \
		libluajit-5.1.so:lang/luajit \
		libhwloc.so:devel/hwloc
RUN_DEPENDS=	daq>=2.2.2:net/daq

OPTIONS_DEFINE=		DEBUG LRGPCAP

OPTIONS_SUB=		yes

LRGPCAP_DESC=		Pcaps larger than 2GB
DEBUG_DESC=		Enable debugging symbols+core dumps

DEBUG_CONFIGURE_ENABLE=	debug debug-msgs
DEBUG_CONFIGURE_DISABLE=	corefiles
DEBUG_MAKE_ENV=		DONTSTRIP="yes"
LRGPCAP_CONFIGURE_ENABLE=	large-pcap

.include <bsd.port.options.mk>

USES=		cpe libtool pathfix pkgconfig ssl

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include

CONFLICTS=	snort-2*

WRKSRC=	${WRKDIR}/snort-3.0.0-a4

.include <bsd.port.mk>
