# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	snort
DISTVERSION=	3.0.0-a4.242
PORTREVISION=	1
CATEGORIES=	security
PKGNAMESUFFIX=	3

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Lightweight network intrusion detection system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	daq>=2.2.2:net/daq \
		bash>0:shells/bash
LIB_DEPENDS=	libpcre.so:devel/pcre \
		libdnet.so:net/libdnet \
		libpcap.so:net/libpcap \
		libluajit-5.1.so:lang/luajit \
		libhwloc.so:devel/hwloc
RUN_DEPENDS=	daq>=2.2.2:net/daq

USES=		cmake compiler:c++11-lang cpe libtool pathfix pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	snortadmin
GH_PROJECT=	snort3
GH_TAGNAME=	BUILD_242

OPTIONS_DEFINE=		DEBUG DOCS LRGPCAP

OPTIONS_SUB=		yes

LRGPCAP_DESC=		Pcaps larger than 2GB
DEBUG_DESC=		Enable debugging symbols+core dumps

DEBUG_CONFIGURE_ENABLE=	debug debug-msgs
DEBUG_CONFIGURE_DISABLE=	corefiles
DEBUG_MAKE_ENV=		DONTSTRIP="yes"
LRGPCAP_CONFIGURE_ENABLE=	large-pcap

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1004000
EXTRA_PATCHES=	${PATCHDIR}/freebsd103_patch-src_memory_memory__allocator.h
.endif

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include

CONFLICTS=	snort-2*

.include <bsd.port.post.mk>
