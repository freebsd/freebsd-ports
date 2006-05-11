# New ports collection makefile for:   ncp
# Date created:        2003-03-06
# Whom:                Matthias Teege <matthias@mteege.de>
#
# $FreeBSD$

PORTNAME=	ncp
PORTVERSION=	1.2.4
CATEGORIES=	net
MASTER_SITES=	http://dl.fefe.de/ http://dl.mteege.de/fefe/

MAINTAINER=	matthias@mteege.de
COMMENT=	A fast file copy tool for LANs

BUILD_DEPENDS=	${LOCALBASE}/lib/libowfat.a:${PORTSDIR}/devel/libowfat

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
MANCOMPRESSED=	no

MAN1=		ncp.1 npush.1
PLIST_FILES=	bin/ncp bin/npush bin/npoll

CFLAGS+=	-I${LOCALBASE}/include/libowfat -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|^CC=gcc|CC=${CC}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^CFLAGS=.*|CFLAGS=${CFLAGS}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^LDFLAGS=.*|LDFLAGS=${LDFLAGS}|' \
		${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ncp ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_MAN} ncp.1 npush.1 ${PREFIX}/man/man1
	${LN} -s ${PREFIX}/bin/ncp ${PREFIX}/bin/npush
	${LN} -s ${PREFIX}/bin/ncp ${PREFIX}/bin/npoll

.include <bsd.port.mk>
