# New ports collection makefile for:	Par
# Version required:     1.50
# Date created:         6 Aug 1997
# Whom:                 mark@grondar.za
#
# $Id: Makefile,v 1.1.1.1 1997/08/06 14:36:48 markm Exp $
#

DISTNAME=       Par150
PKGNAME=        par-1.50
CATEGORIES=	textproc
MASTER_SITES=   http://www.cs.berkeley.edu/~amc/Par/

MAINTAINER=	mark@grondar.za

ALL_TARGET=
MAN1=		par.1

do-configure:
	(cd ${WRKSRC}; ${CP} protoMakefile Makefile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/par ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/par.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
