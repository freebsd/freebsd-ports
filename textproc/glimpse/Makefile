# New ports collection makefile for:	glimpse
# Version required:     3.5
# Date created:         22 Dec 1995
# Whom:                 chuckr@glue.umd.edu
#
# $Id: Makefile,v 1.3 1996/05/20 06:55:44 asami Exp $
#

DISTNAME=       glimpse-3.5.src
PKGNAME=	glimpse-3.5
CATEGORIES+=	misc
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	chuckr@glue.umd.edu

NO_CDROM=	yes	# Restrictive copyright (don't sell for profit)
GNU_CONFIGURE=	yes

pre-configure:
	chmod ugo+x ${WRKSRC}/configure
	chmod ugo+x ${WRKSRC}/mkinstalldirs

post-install:
	mkdir -p ${PREFIX}/share/doc/glimpse
	cp ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	cp ${WRKSRC}/README ${PREFIX}/share/doc/glimpse
.if !defined(NOMANCOMPRESS)
	for file in glimpse glimpseindex glimpseserver agrep; do \
	  gzip -9nf ${PREFIX}/man/man1/$$file.1; \
	done
.endif

.include <bsd.port.mk>
