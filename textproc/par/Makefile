# New ports collection makefile for:	Par
# Version required:     1.50
# Date created:         6 Aug 1997
# Whom:                 mark@grondar.za
#
# $Id$
#

DISTNAME=       par-1.50
DISTFILES=	Par150.tar.gz
CATEGORIES=	textproc
MASTER_SITES=   http://www.cs.berkeley.edu/~amc/Par/
WRKSRC=		${WRKDIR}/Par150

ALL_TARGET=

MAINTAINER=	mark@grondar.za

MAN1=		par.1

do-configure:
	(cd ${WRKSRC}; cp protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
