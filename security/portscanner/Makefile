# New ports collection makefile for:   portscanner
# Version required:    1.0
# Date created:        11 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: $
#

DISTNAME=	PortScanner-1.0
PKGNAME=	portscanner-1.0
CATEGORIES=	net
MASTER_SITES=	http://www.ameth.org/~veilleux/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	billf@FreeBSD.org

WRKSRC=		${WRKDIR}

do-build:

	${CC} -o ${WRKSRC}/portscanner ${CFLAGS} ${WRKSRC}/portscanner.c

do-install:

	${INSTALL_PROGRAM} ${WRKSRC}/portscanner ${PREFIX}/bin

.include <bsd.port.mk>
