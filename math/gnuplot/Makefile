
# New ports collection makefile for:    gnuplot
# Version required:     3.5
# Date created:         6 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.2 1995/04/11 01:18:55 asami Exp $
#

DISTNAME=	gnuplot
PKGNAME=	gnuplot-3.5
MASTER_SITES=	ftp://ftp.dartmouth.edu/pub/gnuplot/
MAINTAINER=	jmz@FreeBSD.org
DISTFILES=	gnuplot3.5.tar.Z

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
