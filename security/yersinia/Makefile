PORTNAME=	yersinia
PORTVERSION=	0.8.2
PORTREVISION=	2
CATEGORIES=	security
# MASTER_SITES=	http://www.yersinia.net/download/
PKGNAMESUFFIX=	-gtk

MAINTAINER=	ayu@commun.jp
COMMENT=	Layer 2 vulnerability scanner (switches, spanning tree, 802.1q ...)

LICENSE=	GPLv2

LIB_DEPENDS=	libnet.so:net/libnet \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf gnome ncurses pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_GITHUB=	yes
GH_TUPLE=	tomac:yersinia:8c0d7c5
GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/yersinia \
		man/man8/yersinia.8.gz

OPTIONS_DEFINE=	PORTS_PCAP

PORTS_PCAP_DESC=Use ports PCAP instead of system PCAP

PORTS_PCAP_CONFIGURE_ON=	--with-pcap-includes=${LOCALBASE}/include
PORTS_PCAP_CONFIGURE_OFF=	--with-pcap-includes=/usr/include
PORTS_PCAP_BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:net/libpcap

post-patch:
	@${REINPLACE_CMD} -e 's,-O3 -Wall -g,${CFLAGS} -fcommon,' \
		${WRKSRC}/configure.ac

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/yersinia ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/yersinia.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
