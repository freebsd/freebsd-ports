# Created by: cnh@ivmg.net
# $FreeBSD$

PORTNAME=	tcpreplay
PORTVERSION=	4.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to replay saved packet capture files

LICENSE=	GPLv3

LIB_DEPENDS=	libopts.so:devel/autogen \
		libdnet.so:net/libdnet
BUILD_DEPENDS=	pcapnav-config:net/libpcapnav

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
TEST_TARGET=	test

GH_ACCOUNT=	appneta

CONFIGURE_ARGS=	--program-transform-name='s|.*\(tcp.*\)|\1|' \
		--with-pcapnav-config=${LOCALBASE}/bin/pcapnav-config

# required when using autogen
CONFIGURE_ARGS+=	--disable-local-libopts --disable-libopts-install

LIBPCAP_BASE_DESC=	Build with libpcap from the base OS
LIBPCAP_PORTS_DESC=	Build with net/libpcap

OPTIONS_SINGLE=		LIBPCAP
OPTIONS_SINGLE_LIBPCAP=	LIBPCAP_BASE LIBPCAP_PORTS

OPTIONS_DEFAULT=	LIBPCAP_BASE

LIBPCAP_BASE_CONFIGURE_ON=	--with-libpcap=/usr/lib
LIBPCAP_PORTS_LIB_DEPENDS=	libpcap.so:net/libpcap

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -O3||' ${WRKSRC}/${CONFIGURE_SCRIPT}.ac

.include <bsd.port.mk>
