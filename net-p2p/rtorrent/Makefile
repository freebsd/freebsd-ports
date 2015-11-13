# $FreeBSD$

PORTNAME=	rtorrent
PORTVERSION=	0.9.6
CATEGORIES=	net-p2p
MASTER_SITES=	http://rtorrent.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent Client written in C++

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libtorrent.so:${PORTSDIR}/net-p2p/libtorrent

BROKEN_arm=	does not configure on arm

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang pkgconfig
LDFLAGS+=	-pthread
CONFIGURE_ARGS=	--disable-debug

SUB_FILES=	pkg-message

PORTDOCS=	README

OPTIONS_DEFINE=	XMLRPC IPV6 DOCS EXAMPLES
OPTIONS_DEFAULT=XMLRPC
XMLRPC_DESC=	Compile with xmlrpc-c support
IPV6_CONFIGURE_ON=	--enable-ipv6
XMLRPC_LIB_DEPENDS=	libxmlrpc.so:${PORTSDIR}/net/xmlrpc-c-devel
XMLRPC_CONFIGURE_ON=	--with-xmlrpc-c
XMLRPC_CONFIGURE_OFF=	--with-xmlrpc-c=no

.include <bsd.port.options.mk>

# Workaround to build on >= 10.x
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
CXXFLAGS+=	-std=c++11
EXTRA_PATCHES+=	${FILESDIR}/extra-clang
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
	@${FIND} ${WRKSRC} \( -name '*.h' -o -name '*.cc' \) -type f \
		-exec ${REINPLACE_CMD} -e 's/tr1::/std::/g' {} \; \
		-exec ${REINPLACE_CMD} -e 's/std::std::/std::/g' {} \; \
		-exec ${REINPLACE_CMD} -e '/namespace tr1/d' {} \; \
		-exec ${REINPLACE_CMD} -e '/include/s,tr1/,,' {} \;
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
