# New ports collection makefile for:    dvi2xx
# Version required:     0.51alpha9
# Date created:         14 October 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.9 1995/11/22 13:17:59 asami Exp $
#

DISTNAME=	dvi2xx
PKGNAME=	dvi2xx-0.51a9
DISTFILES=	dvi2xx.tar.gz
CATEGORIES+=	print

MAINTAINER=	jmz@FreeBSD.ORG

#other equivalent sites: ftp.shsu.edu ftp.dante.de
CTAN?=		ftp.tex.ac.uk

do-fetch:
	@if [ ! -d ${DISTDIR} ]; then ${MKDIR} -p ${DISTDIR}; fi
	@(cd ${DISTDIR}; \
	 if [ ! -f ${DISTFILES} -a ! -f `${BASENAME} ${DISTFILES}` ]; then \
	   if [ -h ${DISTFILES} -o -h `${BASENAME} ${DISTFILES}` ]; then \
	     ${ECHO_MSG} ">> ${DISTDIR}/${DISTFILES} is a broken symlink."; \
	     ${ECHO_MSG} ">> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
	     ${ECHO_MSG} ">> Please correct this problem and try again."; \
	     exit 1; \
	   fi ; \
	   ${ECHO_MSG} ">> ${DISTFILES} doesn't seem to exist on this system."; \
	   ${ECHO_MSG} ">> Attempting to fetch from ${CTAN}."; \
	   if ${FETCH_CMD} -h ${CTAN} -c /tex-archive/dviware -f ${DISTFILES}; then \
	     exit 0; \
	   fi; \
	   ${ECHO_MSG} ">> Couldn't fetch it - please try to retreive this";\
	   ${ECHO_MSG} ">> port manually into ${DISTDIR} and try again."; \
	   exit 1; \
	 fi)


pre-install:
	@mkdir -p ${PREFIX}/lib/dvi2xx
	@(cd ${WRKSRC}; install -m 755 -c MakeTeXPK ${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 644 2up.sty  graybox.sty lj3-filter \
	  printcap.sample sample2.tex testpage.tex ${PREFIX}/lib/dvi2xx/)

.include <bsd.port.mk>
