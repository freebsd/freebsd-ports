# New ports collection makefile for:   portscanner
# Date created:        11 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	portscanner
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.ameth.org/~veilleux/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	billf
DISTNAME=	PortScanner-1.0

MAINTAINER=	billf@FreeBSD.org

NO_WRKSUBDIR=	yes

do-build:

	@ ${CC} -o ${WRKSRC}/portscanner ${CFLAGS} ${WRKSRC}/portscanner.c

do-install:

	@ ${INSTALL_PROGRAM} ${WRKSRC}/portscanner ${PREFIX}/bin

.include <bsd.port.mk>
