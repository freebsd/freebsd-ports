# New ports collection makefile for:    tex
# Version required:     6.1
# Date created:         29 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.20 1996/03/02 02:08:23 jmz Exp $
#

DISTNAME=	web2c-6.1
PKGNAME=	tex-3.1415
CATEGORIES+=	print
DISTFILES=	web2c-6.1.tar.gz web-6.1.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz      modes.mf 

MAINTAINER=	jmz@FreeBSD.org

EXTRACT_ONLY=	web2c-6.1.tar.gz web-6.1.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz

FTPGET=		${FILESDIR}/ftpget

#other equivalent sites: ftp.shsu.edu ftp.dante.de
CTAN?=		ftp.tex.ac.uk


BASES=		mf.base cmmf.base 
FORMATS=	tex.fmt 

CFLAGS+=	-L${X11BASE}/lib


web2c-6.1.tar.gz: 
	@${FTPGET} ${CTAN} /tex-archive/systems/web2c web2c-6.1.tar.gz ${DISTDIR}/$@
web-6.1.tar.gz: 
	@${FTPGET} ${CTAN} /tex-archive/systems/web2c web-6.1.tar.gz ${DISTDIR}/$@
cm_mf.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/fonts cm/mf.tar.gz ${DISTDIR}/$@
cm_tfm.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/fonts cm/tfm.tar.gz ${DISTDIR}/$@
mf_lib.tar.gz: 
	@${FTPGET} ${CTAN} /tex-archive/systems/knuth lib.tar.gz ${DISTDIR}/$@
modes.mf:
	@${FTPGET} ${CTAN} /tex-archive/fonts/modes modes.mf ${DISTDIR}/$@
tex_base.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/macros plain/base.tar.gz ${DISTDIR}/$@

pre-fetch:
	@chmod +x ${FTPGET}

do-build: 
	@(cd ${WRKSRC}/web2c; make triptrap)
	@(cd ${WRKSRC}/web2c; make run-triptrap)
	@(cd ${WRKSRC}/web2c; make clean-triptrap)
	@(cd ${WRKSRC}; make CFLAGS="${CFLAGS}" programs)
	@(cd ${WRKSRC}; MFINPUTS=${WRKDIR}/mf; export MFINPUTS;\
		make bases="${BASES}" bases)
	@(cd ${WRKSRC}/web2c; TEXINPUTS=${WRKDIR}/lib:${WRKSRC}; export TEXINPUTS;\
	  TEXFONTS=${WRKDIR}/cm/tfm:${WRKDIR}/latex/tfm; export TEXFONTS; \
		make fmts="${FORMATS}" fmts)

do-install: 
	@(cd ${WRKSRC}/web2c; make install-exec INSTALL_PROGRAM="/usr/bin/install -c -s")
	@(cd ${WRKSRC}/web2c; make install-manpages)
	@(cd ${WRKSRC}/web2c; make install-data bases="${BASES}" fmts="${FORMATS}")
	@mkdir -p ${PREFIX}/lib/texmf/fonts/tfm
	@(cd ${WRKDIR}/cm/tfm; install -c -m 644 *.tfm ${PREFIX}/lib/texmf/fonts/tfm)
	@mkdir -p ${PREFIX}/lib/texmf/mf
	@(cd ${WRKDIR}/mf; install -c -m 644 *.mf ${PREFIX}/lib/texmf/mf)
	@mkdir -p ${PREFIX}/lib/texmf/tex
	@(cd ${WRKDIR}/lib; install -c -m 644 *.tex ${PREFIX}/lib/texmf/tex)
	@(cd ${WRKDIR}/plain/base; install -c -m 644 *.tex ${PREFIX}/lib/texmf/tex)
	@(rm -f ${PREFIX}/bin/latex)

.include "Makefile.inc"

.include <bsd.port.mk>
