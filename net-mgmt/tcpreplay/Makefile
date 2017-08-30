# Created by: cnh@ivmg.net
# $FreeBSD$

PORTNAME=	tcpreplay
PORTVERSION=	4.2.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to replay saved packet capture files

LICENSE=	GPLv3

LIB_DEPENDS=	libopts.so:devel/autogen \
		libdnet.so:net/libdnet
BUILD_DEPENDS=	pcapnav-config:net/libpcapnav

USES=		autoreconf libtool pkgconfig
USE_GITHUB=	yes
GNU_CONFIGURE=	yes

GH_ACCOUNT=	appneta

CONFIGURE_ARGS=	--program-transform-name='s|.*\(tcp.*\)|\1|' \
		--with-pcapnav-config=${LOCALBASE}/bin/pcapnav-config

# required when using autogen
CONFIGURE_ARGS+=	--disable-local-libopts --disable-libopts-install

OPTIONS_DEFINE=	LIBPCAP_BASE LIBPCAP_PORTS
LIBPCAP_BASE=	Build with libpcap from the base OS
LIBPCAP_PORTS=	Build with net/libpcap

OPTIONS_SINGLE=	SG1
OPTIONS_SINGLE=	LIBPCAP_BASE LIBPCAP_PORTS

OPTIONS_DEFAULT=	LIBPCAP_BASE

LIBPCAP_PORTS_BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:net/libpcap
LIBPCAP_PORTS_LIB_DEPENDS=	libpcap.so:net/libpcap

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -O3||' ${WRKSRC}/${CONFIGURE_SCRIPT}.ac

regression-test: build
	@cd ${WRKSRC} && ${MAKE} -s test

.include <bsd.port.mk>
