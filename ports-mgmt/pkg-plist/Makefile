# Created by: Martin Tournoij <martin@arp242.net>
# $FreeBSD$

PORTNAME=	pkg-plist
PORTVERSION=	1.2
CATEGORIES=	ports-mgmt python
MASTER_SITES=	http://code.arp242.net/pkg-plist/downloads/

MAINTAINER=	martin@arp242.net
COMMENT=	Generate a pkg-plist for a port

LICENSE=	MIT

USES=		python
NO_BUILD=	yes

PLIST_FILES=	bin/pkg-plist man/man1/pkg-plist.1.gz

DEPRECATED=	Generate incorrect plists
EXPIRATION_DATE=	2014-11-30

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg-plist ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pkg-plist.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
