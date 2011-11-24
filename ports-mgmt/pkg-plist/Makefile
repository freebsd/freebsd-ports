# New ports collection makefile for:	ports-mgmt/pkg-plist
# Date created:				2011-11-14
# Whom:					Martin Tournoij <martin@arp242.net>
#
# $FreeBSD$
#

PORTNAME=	pkg-plist
PORTVERSION=	1.1
CATEGORIES=	ports-mgmt python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	martin@arp242.net
COMMENT=	Generate a pkg-plist for a port

LICENSE=	MIT

USE_PYTHON=	yes
MAN1=		pkg-plist.1
PLIST_FILES=	bin/pkg-plist
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg-plist ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/pkg-plist.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
