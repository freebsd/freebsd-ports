# New ports collection makefile for:    xfed
# Version required:     something old
# Date created:         7 December 1994
# Whom:                 asami
#
# $Id:$
#

DISTNAME=	xfed
TARFILE=	xfed.tar.gz
SOURCEFILES=	Epistle,README,Imakefile,xfed.man \
		icon.bit,next.bit,prev.bit,quit.bit,save.bit \
		defs.h,main.c,output.c,parse.y,scan.l
USE_IMAKE=	yes
INSTALL_MANPAGES=	yes
#MASTER_SITES=	ftp://me10.lbl.gov/pub/hp_X11R3_tape/source/app/
SOURCESITE=	ftp://ftp.cs.orst.edu/pub/src/X11R4/contrib/clients/xfed/
#EXTRACT_SUFX=	.tar.Z

fetch:	pre-fetch
	@if [ ! -d ${DISTDIR} ]; then mkdir -p ${DISTDIR}; fi
	@noglob= ; \
	if [ ! -f ${DISTDIR}/${TARFILE} ]; then \
	  rm -rf ${.CURDIR}/src; \
	  mkdir -p ${.CURDIR}/src/xfed; \
	  echo ">> Fetching files from remote site...";  \
	  for file in ${SOURCEFILES}; do \
	    (cd ${.CURDIR}/src/xfed; \
	      ${NCFTP} ${NCFTPFLAGS} ${SOURCESITE}\{$$file\}); \
	  done; \
	  echo ">> Now creating a tarball ${DISTDIR}/${TARFILE}..."; \
	  tar -C ${.CURDIR}/src -czf ${DISTDIR}/${TARFILE} xfed; \
	  rm -rf ${.CURDIR}/src; \
	fi

.include <bsd.port.mk>
