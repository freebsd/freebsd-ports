# New ports collection makefile for:    cnet
# Version required:     1.4
# Date created:         Feb 8th, 1988
# Whom:                 jkh
#
# $Id$
#

DISTNAME=	cnet-1.4-3
PKGNAME=	cnet-1.4p3
CATEGORIES=	net
MASTER_SITES=	http://www.cs.uwa.edu.au/pls/cnet/

DEPENDS=	${PORTSDIR}/x11/xview-lib

WRKSRC=		${WRKDIR}/cnet-1.4
ALL_TARGET=
MAN1=		cnet.1

pre-build:
	cp ${FILESDIR}/Makefile.freebsd ${WRKSRC}/src
	mkdir -p ${WRKSRC}/src/freebsd
	cp ${FILESDIR}/compile.c ${WRKSRC}/src/freebsd

pre-install:
	mkdir -p ${PREFIX}/share/examples/cnet

.include <bsd.port.mk>
