# New ports collection makefile for:    dvi2xx
# Version required:     0.51alpha9
# Date created:         14 October 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	dvi2xx
PKGNAME=	dvi2xx-0.51a9
DISTFILES=	dvi2xx.tar.gz
CATEGORIES+=	printing

.if !defined(MASTER_SITE_OVERRIDE)
#other equivalent sites: ftp.shsu.edu dtp.dante.de
CTAN=		ftp.tex.ac.uk
FTP_DIR=	/tex-archive/dviware
FTPGET=		${WRKDIR}/ftpget

pre-fetch:
	@if [ ! -d ${DISTDIR} ]; then mkdir -p ${DISTDIR}; fi
	@mkdir -p ${WRKDIR}
	@${SCRIPTDIR}/ftpget magic ${WRKDIR}

fetch: pre-fetch ${DISTFILES}
.endif

dvi2xx.tar.gz:
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  echo ">> $@ doesn't seem to exist on this system."; \
	  echo ">> Attempting to fetch it from a master site."; \
	  ${FTPGET} ${CTAN} ${FTP_DIR} $@ $@ ;\
	  if [ ! -f $@ ]; then \
			echo ">> Couldn't fetch it - please try to retrieve this";\
		echo ">> port manually into ${DISTDIR} and try again."; \
		exit 1; \
	  else \
		echo ">> $@ Fetched!" ; \
	  fi; fi)

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/lib/dvi2xx
	@(cd ${WRKSRC}; install -m 755 -c MakeTeXPK ${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 644 2up.sty  graybox.sty lj3-filter \
	  printcap.sample sample2.tex testpage.tex ${PREFIX}/lib/dvi2xx/)

.include <bsd.port.mk>
