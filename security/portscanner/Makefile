# New ports collection makefile for:   portscanner
# Version required:    1.0
# Date created:        11 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.4 1998/12/03 19:12:28 obrien Exp $
#

DISTNAME=	PortScanner-1.0
PKGNAME=	portscanner-1.0
CATEGORIES=	security net
MASTER_SITES=	http://www.ameth.org/~veilleux/ \
		http://www.FreeBSD.org/~billf/

MAINTAINER=	billf@FreeBSD.org

NO_WRKSUBDIR=	yes

do-build:

	@ ${CC} -o ${WRKSRC}/portscanner ${CFLAGS} ${WRKSRC}/portscanner.c

do-install:

	@ ${INSTALL_PROGRAM} ${WRKSRC}/portscanner ${PREFIX}/bin

.include <bsd.port.mk>
