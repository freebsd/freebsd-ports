# New ports collection makefile for:	rdist
# Version required:	rdist-6.1.3
# Date created:		19 August 1995
# Whom:			peter
#
# $Id: Makefile,v 1.7 1996/09/21 05:12:01 peter Exp $
#

DISTNAME=	rdist-6.1.3
CATEGORIES+=	net
MASTER_SITES=	ftp://usc.edu/pub/rdist/

MAINTAINER=	peter@FreeBSD.org

# To avoid confusion with /usr/bin/rdist, you may prefer otherwise.
# Do not forget to deal with pkg/PLIST if you change this.
RDIST_NAME=	rdist6

INSTALL_TARGET=	install install.man
MAKE_ENV+=	BUILD_OPT="${CFLAGS}" BUILD_CLIENT=${RDIST_NAME}

post-install:
	strip ${PREFIX}/bin/${RDIST_NAME}
	strip ${PREFIX}/bin/rdistd
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/${RDIST_NAME}.1
	gzip -9nf ${PREFIX}/man/man8/rdistd.8
.endif

.include <bsd.port.mk>
