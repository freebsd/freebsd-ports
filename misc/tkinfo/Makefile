# New ports collection makefile for:	tkinfo
# Version required:     2.4
# Date created:         16 Jan 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.18 1998/03/20 14:35:17 tg Exp $
#

DISTNAME=	tkinfo-2.4
CATEGORIES=	misc tk80
MASTER_SITES=	http://math-www.uni-paderborn.de/~axel/tkinfo/

MAINTAINER=	tg@FreeBSD.ORG

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

NO_BUILD=	yes
MAN1=		tkinfo.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkinfo ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tkinfo.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
