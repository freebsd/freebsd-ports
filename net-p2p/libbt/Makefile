# Created by: Florent Thoumie <flz@xbsd.org>

PORTNAME=	libbt
DISTVERSION=	1.06
CATEGORIES=	net-p2p devel
MASTER_SITES=	SF

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	C library implementing the core BitTorrent protocol

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		gmake localbase ssl
GNU_CONFIGURE=	yes

CONFLICTS_INSTALL=	btcheck # bin/btcheck

DOCS=		docs/protocol.txt docs/protocol-ext.txt \
		CHANGELOG CREDITS README

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|depend||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-lssl|-lcrypto|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\(CFLAGS:=\)|\1\@CFLAGS\@ \@CPPFLAGS\@ |' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libbt.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/libbt
	cd ${WRKSRC}/src && ${INSTALL_PROGRAM} btcheck btget btlist ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/include && ${INSTALL_DATA} *.h ${STAGEDIR}${PREFIX}/include/libbt

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
