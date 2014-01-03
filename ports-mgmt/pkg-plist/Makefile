# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	pkg-plist
PORTVERSION=	1.2
CATEGORIES=	ports-mgmt python
MASTER_SITES=	http://code.arp242.net/pkg-plist/downloads/

MAINTAINER=	martin@arp242.net
COMMENT=	Generate a pkg-plist for a port

LICENSE=	MIT

USE_PYTHON=	yes
MAN1=		pkg-plist.1
PLIST_FILES=	bin/pkg-plist
NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg-plist ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pkg-plist.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
