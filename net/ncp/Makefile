# Created by: Matthias Teege <matthias@mteege.de>
# $FreeBSD$

PORTNAME=	ncp
PORTVERSION=	1.2.4
CATEGORIES=	net
MASTER_SITES=	http://dl.fefe.de/ http://dl.mteege.de/fefe/

MAINTAINER=	matthias@mteege.de
COMMENT=	Fast file copy tool for LANs

BUILD_DEPENDS=	${LOCALBASE}/lib/libowfat.a:devel/libowfat

USES=		tar:bzip2

PLIST_FILES=	bin/ncp bin/npush bin/npoll man/man1/ncp.1.gz man/man1/npush.1.gz

CFLAGS+=	-I${LOCALBASE}/include/libowfat -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|^CC=gcc|CC=${CC}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^CFLAGS=.*|CFLAGS=${CFLAGS}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^LDFLAGS=.*|LDFLAGS=${LDFLAGS}|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ncp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ncp.1 ${WRKSRC}/npush.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${LN} -s ncp ${STAGEDIR}${PREFIX}/bin/npush
	${LN} -s ncp ${STAGEDIR}${PREFIX}/bin/npoll

.include <bsd.port.mk>
