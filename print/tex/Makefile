# New ports collection makefile for:    tex
# Version required:     7.0
# Date created:         29 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.29 1997/02/25 09:00:31 asami Exp $
#

DISTNAME=	web2c-7.0
PKGNAME=	tex-3.14159
CATEGORIES=	print
DISTFILES=	web2c-7.0.tar.gz web-7.0.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz modes.mf 

MAINTAINER=	jmz@FreeBSD.org

MANUAL_PACKAGE_BUILD=	has to be built with latex port
IGNOREFILES=	tex_base.tar.gz cm_tfm.tar.gz mf_lib.tar.gz cm_mf.tar.gz
EXTRACT_ONLY=	web2c-7.0.tar.gz web-7.0.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz

USE_GMAKE=	yes

MAKE_FLAGS=	fmts= all_mems= -f

CTAN?=		ftp.tex.ac.uk

web2c-7.0.tar.gz: 
	@${FETCH_CMD} -o ${DISTDIR}/$@ ftp://${CTAN}/tex-archive/systems/web2c/web2c-7.0.tar.gz 
web-7.0.tar.gz: 
	@${FETCH_CMD} -o ${DISTDIR}/$@ ftp://${CTAN}/tex-archive/systems/web2c/web-7.0.tar.gz 
cm_mf.tar.gz:
	@${FETCH_CMD} -o ${DISTDIR}/$@ ftp://${CTAN}/tex-archive/fonts/cm/mf.tar.gz 
cm_tfm.tar.gz:
	@${FETCH_CMD} -o ${DISTDIR}/$@ ftp://${CTAN}/tex-archive/fonts/cm/tfm.tar.gz 
mf_lib.tar.gz: 
	@${FETCH_CMD} -o ${DISTDIR}/$@ ftp://${CTAN}/tex-archive/systems/knuth/lib.tar.gz 
modes.mf:
	@${FETCH_CMD} -o ${DISTDIR}/$@ ftp://${CTAN}/tex-archive/fonts/modes/modes.mf 
tex_base.tar.gz:
	@${FETCH_CMD} -o ${DISTDIR}/$@ ftp://${CTAN}/tex-archive/macros/plain/base.tar.gz 

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
