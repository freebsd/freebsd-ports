# Created by: cnh@ivmg.net

PORTNAME=	tcpreplay
DISTVERSION=	4.4.1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/appneta/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to replay saved packet capture files

LICENSE=	GPLv3

BUILD_DEPENDS=	pcapnav-config:net/libpcapnav
LIB_DEPENDS=	libdnet.so:net/libdnet \
		libopts.so:devel/autogen

USES=		cpe gmake libtool pkgconfig tar:xz
CPE_VENDOR=	appneta

GNU_CONFIGURE=	yes
# libopts options are required when using autogen
CONFIGURE_ARGS=	--program-transform-name='s|.*\(tcp.*\)|\1|' \
		--with-pcapnav-config=${LOCALBASE}/bin/pcapnav-config \
		--disable-libopts-install \
		--disable-local-libopts

TEST_TARGET=	test

OPTIONS_DEFAULT=	LIBPCAP_BASE
OPTIONS_SINGLE=		LIBPCAP
OPTIONS_SINGLE_LIBPCAP=	LIBPCAP_BASE LIBPCAP_PORTS

LIBPCAP_BASE_DESC=	Build with libpcap from the base OS
LIBPCAP_PORTS_DESC=	Build with net/libpcap

LIBPCAP_BASE_CONFIGURE_ON=	--with-libpcap=/usr/lib
LIBPCAP_PORTS_LIB_DEPENDS=	libpcap.so:net/libpcap

.include <bsd.port.mk>
