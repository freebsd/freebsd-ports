# New ports collection makefile for:    cnet
# Version required:     1.4
# Date created:         Feb 8th, 1988
# Whom:                 jkh
#
# $Id: Makefile,v 1.5 1998/09/21 22:15:56 steve Exp $
#

DISTNAME=	cnet-1.4-3
PKGNAME=	cnet-1.4p3
CATEGORIES=	net
MASTER_SITES=	http://www.cs.uwa.edu.au/pls/cnet/

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview-lib \
		Xpm.4:${PORTSDIR}/graphics/xpm

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
