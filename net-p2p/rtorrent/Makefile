PORTNAME=	rtorrent
DISTVERSION=	0.15.6
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
USE_RC_SUBR=	rtorrent
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
LDFLAGS+=	-lexecinfo -pthread

SUB_FILES=	pkg-message

USERS=		rtorrent
GROUPS=		rtorrent

PLIST_FILES=	bin/rtorrent \
		"@sample ${ETCDIR}/rtorrent.conf.sample"
PORTDOCS=	README

OPTIONS_DEFINE=		DOCS IPV6
OPTIONS_DEFAULT=	TINYXML
OPTIONS_RADIO=		XML
OPTIONS_RADIO_XML=	TINYXML XMLRPC
XMLRPC_DESC=		Compile with xmlrpc-c support

IPV6_CONFIGURE_ENABLE=	ipv6
TINYXML_CONFIGURE_ON=	--with-xmlrpc-tinyxml2
XMLRPC_LIB_DEPENDS=	libxmlrpc.so:net/xmlrpc-c
XMLRPC_CONFIGURE_ON=	--with-xmlrpc-c

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc \
		${STAGEDIR}${ETCDIR}/rtorrent.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
