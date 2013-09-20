# Created by: Benjamin Lutz
# $FreeBSD$

PORTNAME=	psearch
PORTVERSION=	2.0.2
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://www.maxlor.com/files/

MAINTAINER=	mail@maxlor.com
COMMENT=	An utility for searching the FreeBSD Ports Collection

MAN1=		psearch.1
PLIST_FILES=	bin/psearch

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/psearch ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/psearch.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
