# New ports collection makefile for:    cnet
# Version required:     1.4
# Date created:         Feb 8th, 1988
# Whom:                 jkh
#
# $Id: Makefile,v 1.2 1998/02/16 10:54:05 asami Exp $
#

DISTNAME=	cnet-1.4-3
PKGNAME=	cnet-1.4p3
CATEGORIES=	net
MASTER_SITES=	http://www.cs.uwa.edu.au/pls/cnet/

LIB_DEPENDS=	xview\\.3\\.2:${PORTSDIR}/x11/xview-lib

WRKSRC=		${WRKDIR}/cnet-1.4
ALL_TARGET=
MAN1=		cnet.1

pre-build:
	${CP} ${FILESDIR}/Makefile.freebsd ${WRKSRC}/src
	${MKDIR} ${WRKSRC}/src/freebsd
	${CP} ${FILESDIR}/compile.c ${WRKSRC}/src/freebsd

pre-install:
	${MKDIR} ${PREFIX}/share/examples/cnet

.include <bsd.port.mk>
