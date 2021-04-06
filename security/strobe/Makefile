# Created by: proff

PORTNAME=	strobe
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://ftp.ussg.iu.edu/security/tools/unix/scanners/strobe/ \
		http://ftp.cerias.purdue.edu/pub/tools/unix/scanners/strobe/ \
		http://ftp.surfnet.nl/security/coast/scanners/strobe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast scatter/gather TCP port scanner

WRKSRC=		${WRKDIR}/strobe
ALL_TARGET=	strobe

PLIST_FILES=	bin/strobe lib/strobe.services man/man1/strobe.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/strobe ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/strobe.services ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/strobe.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
