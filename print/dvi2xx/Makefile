# New ports collection makefile for:    dvi2xx
# Version required:     0.51alpha9
# Date created:         14 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.5 1995/04/15 04:33:39 asami Exp $
#

DISTNAME=	dvi2xx
PKGNAME=	dvi2xx-0.51a9
DISTFILES=	dvi2xx.tar.gz
CATEGORIES+=	printing

#other equivalent sites: ftp.shsu.edu dtp.dante.de
CTAN=		ftp.tex.ac.uk
FTPGET=		${FILESDIR}/ftpget


dvi2xx.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/dviware dvi2xx.tar.gz ${DISTDIR}/$@

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/lib/dvi2xx
	@(cd ${WRKSRC}; install -m 755 -c MakeTeXPK ${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 644 2up.sty  graybox.sty lj3-filter \
	  printcap.sample sample2.tex testpage.tex ${PREFIX}/lib/dvi2xx/)

.include "Makefile.inc"

.include <bsd.port.mk>
