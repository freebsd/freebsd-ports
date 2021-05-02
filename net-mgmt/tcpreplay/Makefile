# Created by: cnh@ivmg.net

PORTNAME=	tcpreplay
PORTVERSION=	4.3.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to replay saved packet capture files

LICENSE=	GPLv3

BUILD_DEPENDS=	pcapnav-config:net/libpcapnav
LIB_DEPENDS=	libdnet.so:net/libdnet \
		libopts.so:devel/autogen

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	appneta
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name='s|.*\(tcp.*\)|\1|' \
		--with-pcapnav-config=${LOCALBASE}/bin/pcapnav-config

TEST_TARGET=	test

OPTIONS_DEFAULT=	LIBPCAP_BASE
OPTIONS_SINGLE=		LIBPCAP
OPTIONS_SINGLE_LIBPCAP=	LIBPCAP_BASE LIBPCAP_PORTS

# required when using autogen
CONFIGURE_ARGS+=	--disable-libopts-install \
			--disable-local-libopts

LIBPCAP_BASE_DESC=	Build with libpcap from the base OS
LIBPCAP_PORTS_DESC=	Build with net/libpcap

LIBPCAP_BASE_CONFIGURE_ON=	--with-libpcap=/usr/lib
LIBPCAP_PORTS_LIB_DEPENDS=	libpcap.so:net/libpcap

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -O3||' ${WRKSRC}/${CONFIGURE_SCRIPT}.ac

.include <bsd.port.mk>
