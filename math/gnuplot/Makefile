# New ports collection makefile for:    gnuplot
# Version required:     3.5
# Date created:         6 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1995/04/28 13:35:36 jkh Exp $
#

DISTNAME=	gnuplot
PKGNAME=	gnuplot-3.5
CATEGORIES=	math graphics
MASTER_SITES=	ftp://ftp.dartmouth.edu/pub/gnuplot/ \
		${MASTER_SITE_GNU}
DISTFILES=	gnuplot3.5.tar.Z

MAINTAINER=	jmz@FreeBSD.org

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
