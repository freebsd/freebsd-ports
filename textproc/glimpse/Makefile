# New ports collection makefile for:	glimpse
# Version required:	3.6
# Date created:		25 August 1996
# Whom:			chuckr@freebsd.org
#
# $Id: Makefile,v 1.5 1996/08/26 02:14:25 chuckr Exp $
#

DISTNAME=       glimpse-3.6.src
PKGNAME=	glimpse-3.6
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	chuckr@freebsd.org

NO_CDROM=	yes	# Restrictive copyright (don't sell for profit)
GNU_CONFIGURE=	yes

pre-configure:
	chmod ugo+x ${WRKSRC}/configure

post-install:
	mkdir -p ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse
.if !defined(NOMANCOMPRESS)
	for file in glimpse glimpseindex glimpseserver agrep; do \
	gzip -9nf ${PREFIX}/man/man1/$$file.1; \
	done
.endif

.include <bsd.port.mk>
