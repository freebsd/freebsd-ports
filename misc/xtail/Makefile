# New ports collection makefile for:   xtail
# Date created:        20 January 1999
# Whom:                gmarco@giovannelli.it
#
# $FreeBSD$
#

PORTNAME=	xtail
PORTVERSION=	0.1
CATEGORIES=	misc
MASTER_SITES=	http://www.giovannelli.it/~gmarco/files/
DISTNAME=	${PORTNAME}

MAINTAINER=	gmarco@giovannelli.it

NO_WRKSUBDIR=	yes

MAN1=	xtail.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtail ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xtail.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
