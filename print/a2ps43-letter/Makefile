# New ports collection makefile for:    a2ps
# Version required:     4.3
# Date created:         6 November 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	a2ps
PKGNAME=	a2ps-4.3
CATEGORIES+=	printing
MASTER_SITES=	ftp://ftp.imag.fr/archive/postscript/
DISTFILES=	a2ps.V4.3.tar.gz

MAINTAINER=	jmz@FreeBSD.org

NO_WRKSUBDIR=	yes

pre-install:
	@mkdir -p  ${PREFIX}/bin
	@mkdir -p  ${PREFIX}/man/man1
	@(cd ${WRKSRC}; make install.man)

.include <bsd.port.mk>
