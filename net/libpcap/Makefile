# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpcap
PORTVERSION=	1.8.1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Ubiquitous network traffic capture library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

GNU_CONFIGURE=	yes
USES=		bison gmake
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--enable-dbus=no \
		--with-pcap=bpf
CONFIGURE_ENV+=	LEX=${LOCALBASE}/bin/flex
CFLAGS_amd64=	-fPIC
CFLAGS_sparc64=	-fPIC
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DAG IPV6

DAG_DESC=	Support for Endace DAG hardware

IPV6_CONFIGURE_ENABLE=	ipv6
DAG_CONFIGURE_WITH=	dag
DAG_LDFLAGS=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
