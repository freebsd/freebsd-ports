# New ports collection makefile for:    latex
# Version required:     ?
# Date created:         29 September 1994
# Whom:                 jmz
#
# $Id: Makefile,v 1.34 1998/01/26 00:59:43 jmz Exp $
#

VERSION=	98.01
DISTNAME=	latex
PKGNAME=	latex2e-${VERSION}
CATEGORIES=     print
MASTER_SITES=   ftp://ftp.cdrom.com/pub/tex/package/
DISTFILES=	latex_mf-${VERSION}.tar.gz latex_tfm-${VERSION}.tar.gz \
		latex_base-${VERSION}.tar.gz latex_tools-${VERSION}.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

MANUAL_PACKAGE_BUILD=	has to be built with tex port

do-build:
	(cd ${WRKSRC}/base; tex --ini unpack.ins)
	(cd ${WRKSRC}/base; TEXFONTS=${WRKSRC}/tfm:; export TEXFONTS; \
		tex --ini latex.ltx </dev/null)
	(cd ${WRKSRC}/packages/tools; TEXFORMATS=${WRKSRC}/base:; \
		TEXINPUTS=${WRKSRC}/base: export TEXFORMATS TEXINPUTS;\
		 ln -sf ${PREFIX}/bin/tex latex; ./latex tools.ins)

do-install: 
	@(/usr/bin/install -c -m 644 ${WRKSRC}/base/latex.fmt \
				${PREFIX}/share/texmf/web2c/)
	@(cd ${WRKSRC}/tfm; install -c -m 644 *.tfm ${PREFIX}/share/texmf/fonts/tfm)
	@(cd ${WRKSRC}/mf; install -c -m 644 *.mf ${PREFIX}/share/texmf/metafont)
	@mkdir -p ${PREFIX}/share/texmf/tex/latex
	@(cd ${WRKSRC}/base; for f in latexbug.tex testpage.tex \
	   lablst.tex idx.tex nfssfont.tex small2e.tex sample2e.tex docstrip.tex \
	   *.cls *.clo *.sty *.fd *.def *.cfg ; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/share/texmf/tex/latex; fi; done)
	@mkdir -p ${PREFIX}/share/texmf/makeindx;
	@(cd ${WRKSRC}/base; install -c -m 644 *.ist ${PREFIX}/share/texmf/makeindx)
	@(cd ${WRKSRC}/packages/tools; for f in *.sty *.tex; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/share/texmf/tex/latex; fi; done)
	@(cd ${PREFIX}/bin; rm -f latex; ln -s tex latex)
	@(mkdir -p ${PREFIX}/share/texmf/documentation)
	@(cd ${WRKSRC}/base; for f in *.dtx ltx3info.tex source2e.tex *.fdd ltnews*.tex *guide.tex; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/share/texmf/documentation; fi; done)
	@(cd ${WRKSRC}/packages/tools; for f in *.dtx; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/share/texmf/documentation; fi; done)
	@(cd ${PREFIX}/bin; rm -f latex; ln -s tex latex)

.include <bsd.port.mk>
