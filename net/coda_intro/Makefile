# New ports collection makefile for:	coda
# Version required:			4.6.5
# Date created:				19 June 1998
# Whom:					Robert V. Baron <rvb@cs.cmu.edu>
#
# $Id: Makefile,v 1.2 1998/10/06 15:51:02 rvb Exp $
#

DISTNAME=	coda-intro-4.6.6
PKGNAME=	coda-intro-4.6.6.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

do-build:
	@${ECHO} "These are simple text files.

do-install:
	@${ECHO} "We will copy the files to ${PREFIX}/share/doc/coda-intro"
	cd ${WRKSRC}; tar cf - doc | (cd ${PREFIX}/share; tar xvf -)

.include <bsd.port.mk>
