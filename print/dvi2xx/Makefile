# New ports collection makefile for:    dvi2xx
# Version required:     0.51alpha9
# Date created:         14 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.7 1995/04/21 00:21:02 jmz Exp $
#

DISTNAME=	dvi2xx
PKGNAME=	dvi2xx-0.51a9
DISTFILES=	dvi2xx.tar.gz
CATEGORIES+=	printing

MAINTAINER=	jmz@FreeBSD.ORG

#other equivalent sites: ftp.shsu.edu ftp.dante.de
CTAN?=		ftp.tex.ac.uk
FTPGET=		${FILESDIR}/ftpget

dvi2xx.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/dviware dvi2xx.tar.gz ${DISTDIR}/$@

pre-fetch:
	@chmod +x ${FTPGET}

pre-install:
	@mkdir -p ${PREFIX}/lib/dvi2xx
	@(cd ${WRKSRC}; install -m 755 -c MakeTeXPK ${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 644 2up.sty  graybox.sty lj3-filter \
	  printcap.sample sample2.tex testpage.tex ${PREFIX}/lib/dvi2xx/)

.include "Makefile.inc"

.include <bsd.port.mk>
