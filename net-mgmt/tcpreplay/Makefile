PORTNAME=	tcpreplay
DISTVERSION=	4.5.2
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/appneta/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Tool to replay saved packet capture files
WWW=		https://github.com/appneta/tcpreplay

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

LIB_DEPENDS=	libdnet.so:net/libdnet \
		libopts.so:devel/autogen

USES=		cpe gmake libtool pkgconfig tar:xz
CPE_VENDOR=	broadcom

GNU_CONFIGURE=	yes
# libopts options are required when using autogen
CONFIGURE_ARGS=	--disable-libopts-install \
		--disable-local-libopts

TEST_TARGET=	test

OPTIONS_DEFINE=		LIBPCAP_PORTS
LIBPCAP_PORTS_DESC=	Build with net/libpcap instead of from the base OS

# needs .so version (libpcap.so:net/libpcap uses libpcap from the base system)
LIBPCAP_PORTS_LIB_DEPENDS=	libpcap.so.1:net/libpcap
LIBPCAP_PORTS_CONFIGURE_OFF=	--with-libpcap=/usr/lib

post-patch:
	@${REINPLACE_CMD} -e '/make test/s|make|${MAKE_CMD}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
