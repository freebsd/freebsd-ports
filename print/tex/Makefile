# New ports collection makefile for:    tex
# Version required:     7.0
# Date created:         29 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.26 1997/02/10 01:57:38 jmz Exp $
#

DISTNAME=	web2c-7.0
PKGNAME=	tex-3.14159
CATEGORIES=	print
DISTFILES=	web2c-7.0.tar.gz web-7.0.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz modes.mf 

MAINTAINER=	jmz@FreeBSD.org

IGNOREFILES=	${DISTFILES}
EXTRACT_ONLY=	web2c-7.0.tar.gz web-7.0.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz
#MAN1=		bibtex.1 dvitype.1 gftodvi.1 gftopk.1 gftype.1 \
#		latex.1 mf.1 mft.1 pktogf.1 pktype.1 pltotf.1 slitex.1 \
#		tangle.1 tex.1 tftopl.1 vftovp.1 vptovf.1 weave.1 etex.1 \
#		amslatex.1 amstex.1 initex.1 lamstex.1 patgen.1 pooltype.1 \
#		virtex.1

USE_GMAKE=	yes

MAKE_FLAGS=	fmts= all_mems= -f

#other equivalent sites: ftp.shsu.edu ftp.dante.de
CTAN?=		ftp.tex.ac.uk

web2c-7.0.tar.gz: 
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/systems/web2c -f web2c-7.0.tar.gz -o ${DISTDIR}/$@
web-7.0.tar.gz: 
	@${FETCH_CMD} -h ${CTAN} -c /tex-archive/systems/web2c -f web-7.0.tar.gz -o ${DISTDIR}/$@
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

post-install:
	@for i in kpsewhich dmp bibtex dvicopy dvitomp dvitype gftodvi gftopk \
	  gftype mf mft patgen pktogf pktype pltotf pooltype tangle tex tftopl \
	  vftovp vptovf weave; do strip ${PREFIX}/bin/$$i; done
	@rm -f ${PREFIX}/bin/mpostf ${PREFIX}/bin/latex \
	  ${PREFIX}/share/texmf/web2c/mpost.mem ${PREFIX}/share/texmf/web2c/mp.pool
	@${MKDIR} ${PREFIX}/share/texmf/fonts/tfm
	@(cd ${WRKDIR}/cm/tfm; ${INSTALL_DATA} *.tfm ${PREFIX}/share/texmf/fonts/tfm)
	@${MKDIR} ${PREFIX}/share/texmf/metafont
	@(cd ${WRKDIR}/cm/mf; ${INSTALL_DATA} *.mf ${PREFIX}/share/texmf/metafont)
	@${MKDIR} ${PREFIX}/share/texmf/tex
	@(cd ${WRKDIR}/lib; ${INSTALL_DATA} *.tex ${PREFIX}/share/texmf/tex)
	@(cd ${WRKDIR}/plain/base; ${INSTALL_DATA} *.tex ${PREFIX}/share/texmf/tex)
	(rm -f ${PREFIX}/bin/latex)

.include "Makefile.inc"

.include <bsd.port.mk>
