# New ports collection makefile for:	glimpse
# Version required:     3.0
# Date created:         22 Dec 1995
# Whom:                 chuckr@glue.umd.edu
#
# $Id: Makefile,v 1.1.1.1 1996/01/15 10:12:29 asami Exp $
#

DISTNAME=       glimpse-3.0.src
PKGNAME=	glimpse-3.0b
CATEGORIES+=	misc
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	chuckr@glue.umd.edu

# Restrictive copyright
NO_PACKAGE=	yes
HAS_CONFIGURE=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	for file in glimpse glimpseindex glimpseserver agrep; do \
	  gzip -9nf ${PREFIX}/man/man1/$$file.1; \
	done
.endif

.include <bsd.port.mk>
