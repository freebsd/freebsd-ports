# New ports collection makefile for:    xfed
# Version required:     something old
# Date created:         7 December 1994
# Whom:                 asami
#
# $Id: Makefile,v 1.7 1995/04/01 14:54:57 asami Exp $
#

DISTNAME=	xfed
PKGNAME=	xfed-1.0
CATEGORIES+=	x11

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes

MAKE_FLAGS=	MANDIR=${PREFIX}/man/man1 BINDIR=${PREFIX}/bin -f
TARFILE=	xfed.tar.gz
.if !defined(MASTER_SITE_OVERRIDE)
SOURCEFILES=	Epistle,README,Imakefile,xfed.man \
		icon.bit,next.bit,prev.bit,quit.bit,save.bit \
		defs.h,main.c,output.c,parse.y,scan.l
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
	  tar -C ${.CURDIR}/src -cf - xfed | \
	    gzip --best > ${DISTDIR}/${TARFILE}; \
	  rm -rf ${.CURDIR}/src; \
	fi
.endif

.include <bsd.port.mk>
