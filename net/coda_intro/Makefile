# New ports collection makefile for:	coda
# Version required:			4.6.5
# Date created:				19 June 1998
# Whom:					Robert V. Baron <rvb@cs.cmu.edu>
#
# $Id$
#

DISTNAME=	coda-intro-4.6.5-2
PKGNAME=	coda-intro-4.6.5.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

#NO_DEPENDS=
#NO_CONFIGURE=

do-build:
	@${ECHO} "These are simple text files.  We are copying them to share/doc/coda-doc-.../info"

do-install:
	cd ${WRKSRC}; tar cf - doc | (cd ${PREFIX}/share; tar xvf -)

.include <bsd.port.mk>
