PORTNAME=	rtorrent
DISTVERSION=	0.15.4
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/rakshasa/rtorrent/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	BitTorrent Client written in C++
WWW=		https://github.com/rakshasa/rtorrent

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libtorrent.so:net-p2p/libtorrent

USES=		compiler:c++17-lang ncurses pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
LDFLAGS+=	-lexecinfo -pthread

SUB_FILES=	pkg-message

PLIST_FILES=	bin/rtorrent
PORTDOCS=	README
PORTEXAMPLES=	rtorrent.rc

OPTIONS_DEFINE=		DOCS EXAMPLES IPV6
OPTIONS_DEFAULT=	TINYXML
OPTIONS_RADIO=		XML
OPTIONS_RADIO_XML=	TINYXML XMLRPC
XMLRPC_DESC=		Compile with xmlrpc-c support

IPV6_CONFIGURE_ENABLE=	ipv6
TINYXML_CONFIGURE_ON=	--with-xmlrpc-tinyxml2
XMLRPC_LIB_DEPENDS=	libxmlrpc.so:net/xmlrpc-c
XMLRPC_CONFIGURE_ON=	--with-xmlrpc-c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
