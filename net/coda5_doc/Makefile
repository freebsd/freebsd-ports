# New ports collection makefile for:	coda
# Version required:			4.6.5
# Date created:				19 June 1998
# Whom:					Robert V. Baron <rvb@cs.cmu.edu>
#
# $Id$
#

DISTNAME=	coda-doc-4.6.5-3
PKGNAME=	coda-doc-4.6.5.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

#NO_DEPENDS=
#NO_CONFIGURE=

do-build:
	@${ECHO} "At present, Coda documentation is distributed in html, man, ps, and ppt forms"
	@${ECHO} "but documentation source is not available.  It should appear in a release"
	@${ECHO} "or two."

do-install:
	cd ${WRKSRC}; tar cf - man | (cd ${PREFIX}; tar xvf -)
	cd ${WRKSRC}; tar cf - doc | (cd ${PREFIX}/share; tar xvf -)

.include <bsd.port.mk>
