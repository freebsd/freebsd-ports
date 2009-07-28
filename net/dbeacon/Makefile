# New ports collection makefile for:  dbeacon
# Date created:  July 19, 2009
# Whom:		Antonio Querubin <tony@lava.net>
#
# $FreeBSD$
#

PORTNAME=	dbeacon
PORTVERSION=	0.3.9.1
CATEGORIES=	net
MASTER_SITES=	http://fivebits.net/files/dbeacon/

MAINTAINER=	tony@lava.net
COMMENT=	Distributed multicast beacon server

PLIST_FILES=	bin/dbeacon

USE_GMAKE=	yes
MAN1=		dbeacon.1

USE_RC_SUBR=	dbeacon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/dbeacon.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
