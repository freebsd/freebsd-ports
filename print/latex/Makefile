# New ports collection makefile for:    latex
# Version required:     ?
# Date created:         29 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.17 1995/06/27 12:56:00 jmz Exp $
#
VERSION=	95.06
DISTNAME=	latex
PKGNAME=	latex2e-${VERSION}
CATEGORIES+=	printing
DISTFILES=	latex_mf-${VERSION}.tar.gz latex_tfm-${VERSION}.tar.gz \
		latex_base-${VERSION}.tar.gz latex_tools-${VERSION}.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

FTPGET=		${FILESDIR}/ftpget

#other equivalent sites: ftp.shsu.edu ftp.dante.de
CTAN?=		ftp.tex.ac.uk


latex_base-${VERSION}.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/macros latex/base.tar.gz ${DISTDIR}/$@
latex_mf-${VERSION}.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/fonts latex/mf.tar.gz ${DISTDIR}/$@
latex_tfm-${VERSION}.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/fonts latex/tfm.tar.gz ${DISTDIR}/$@
latex_tools-${VERSION}.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/macros latex/packages/tools.tar.gz ${DISTDIR}/$@

do-build:
	@(cd ${WRKSRC}/base; yes | initex unpack.ins)
	@(cd ${WRKSRC}/base; TEXFONTS=${WRKSRC}/tfm:; export TEXFONTS; \
		yes | initex latex.ltx)
	@(cd ${WRKSRC}/packages/tools; TEXFORMATS=${WRKSRC}/base:; \
		TEXINPUTS=${WRKSRC}/base: export TEXFORMATS TEXINPUTS;\
		 ln -sf /usr/local/bin/virtex latex; yes | ./latex tools.ins)

do-install: 
	@(/usr/bin/install -c -m 644 ${WRKSRC}/base/latex.fmt \
				${PREFIX}/lib/texmf/ini/)
	@(cd ${WRKSRC}/tfm; install -c -m 644 *.tfm ${PREFIX}/lib/texmf/fonts/tfm)
	@(cd ${WRKSRC}/mf; install -c -m 644 *.mf ${PREFIX}/lib/texmf/mf)
	@(cd ${WRKSRC}/base; for f in latexbug.tex testpage.tex \
	   lablst.tex idx.tex nfssfont.tex small2e.tex sample2e.tex docstrip.tex \
	   hyphen.tex *.cls *.clo *.sty *.fd *.def *.cfg ; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/lib/texmf/tex; fi; done)
	@mkdir -p ${PREFIX}/lib/texmf/makeindx;
	@(cd ${WRKSRC}/base; install -c -m 644 *.ist ${PREFIX}/lib/texmf/makeindx)
	@(cd ${WRKSRC}/packages/tools; for f in *.sty *.tex; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/lib/texmf/tex; fi; done)
	@(cd ${PREFIX}/bin; rm -f latex; ln -s virtex latex)
	@(mkdir -p ${PREFIX}/lib/texmf/documentation)
	@(cd ${WRKSRC}/base; for f in *.dtx ltx3info.tex source2e.tex *.fdd ltnews*.tex *guide.tex; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/lib/texmf/documentation; fi; done)
	@(cd ${WRKSRC}/packages/tools; for f in *.dtx; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/lib/texmf/documentation; fi; done)

.include "Makefile.inc"

.include <bsd.port.mk>
