# New ports collection makefile for:   snarf
# Date created:        2 January 1999
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snarf
PORTVERSION=	7.0
CATEGORIES=	www
MASTER_SITES=	http://www.xach.com/snarf/

MAINTAINER=	kris@FreeBSD.org

GNU_CONFIGURE=	yes

MAN1=	snarf.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snarf ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/snarf.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
