# New ports collection makefile for:   ncp
# Date created:        2003-03-06
# Whom:                Matthias Teege <matthias@mteege.de>
#
# $FreeBSD$

PORTNAME=	ncp
PORTVERSION=	1.2.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/network/ncp/

MAINTAINER=	matthias@mteege.de
COMMENT=	"A fast file copy tool for LANs."

MAN1=		ncp.1 npush.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gcc -O2|${CC} ${CFLAGS}|' \
		${WRKSRC}/conf-cc
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${LDFLAGS}|' \
		${WRKSRC}/conf-ld

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ncp ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_MAN} ncp.1 npush.1 ${PREFIX}/man/man1
	${LN} -s ${PREFIX}/bin/ncp ${PREFIX}/bin/npush
	${LN} -s ${PREFIX}/bin/ncp ${PREFIX}/bin/npoll

.include <bsd.port.mk>
