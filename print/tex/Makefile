# New ports collection makefile for:    tex
# Version required:     6.1
# Date created:         29 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.21 1996/03/19 00:20:44 jmz Exp $
#

DISTNAME=	web2c-6.1
PKGNAME=	tex-3.1415
CATEGORIES+=	print
DISTFILES=	web2c-6.1.tar.gz web-6.1.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz      modes.mf 

MAINTAINER=	jmz@FreeBSD.org

EXTRACT_ONLY=	web2c-6.1.tar.gz web-6.1.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz

#other equivalent sites: ftp.shsu.edu ftp.dante.de
CTAN?=		ftp.tex.ac.uk


BASES=		mf.base cmmf.base 
FORMATS=	tex.fmt 

CFLAGS+=	-L${X11BASE}/lib


web2c-6.1.tar.gz: 
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/systems/web2c -f web2c-6.1.tar.gz -o ${DISTDIR}/$@
web-6.1.tar.gz: 
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/systems/web2c -f web-6.1.tar.gz -o ${DISTDIR}/$@
cm_mf.tar.gz:
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/fonts -f cm/mf.tar.gz -o ${DISTDIR}/$@
cm_tfm.tar.gz:
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/fonts -f cm/tfm.tar.gz -o ${DISTDIR}/$@
mf_lib.tar.gz: 
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/systems/knuth -f lib.tar.gz -o ${DISTDIR}/$@
modes.mf:
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/fonts/modes -f modes.mf -o ${DISTDIR}/$@
tex_base.tar.gz:
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/macros -f plain/base.tar.gz -o ${DISTDIR}/$@

pre-configure:
	(cd ${WRKDIR}/lib; gunzip *.gz)

do-build: 
	(cd ${WRKSRC}; make CFLAGS="${CFLAGS}" programs)
	(cd ${WRKSRC}; MFINPUTS=${WRKDIR}/mf; export MFINPUTS;\
		make bases="${BASES}" bases)
	(cd ${WRKSRC}/web2c; TEXINPUTS=${WRKDIR}/lib:${WRKSRC}; export TEXINPUTS;\
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
