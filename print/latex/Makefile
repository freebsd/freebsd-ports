DISTFILES=	latex_mf.tar.gz latex_tfm.tar.gz latex_base.tar.gz \
		latex_tools.tar.gz
DISTNAME=	latex

FTPGET=		${FILESDIR}/ftpget
BUILD_COOKIE=	${WRKDIR}/.build_done

#other equivalent sites: ftp.shsu.edu ftp.dante.de
CTAN=		ftp.tex.ac.uk


latex_base.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/macros latex/base.tar.gz ${DISTDIR}/$@
latex_mf.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/fonts latex/mf.tar.gz ${DISTDIR}/$@
latex_tfm.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/fonts latex/tfm.tar.gz ${DISTDIR}/$@
latex_tools.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/macros latex/packages/tools.tar.gz ${DISTDIR}/$@


build: ${BUILD_COOKIE}

${BUILD_COOKIE}:
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}/base; initex unpack.ins)
	@(cd ${WRKSRC}/base; TEXFONTS=${WRKSRC}/tfm:; export TEXFONTS; \
		initex latex.ltx)
	@(cd ${WRKSRC}/packages/tools; TEXFORMATS=${WRKSRC}/base:; \
		TEXINPUTS=${WRKSRC}/base: export TEXFORMATS TEXINPUTS;\
		 ln -s /usr/local/bin/virtex latex; ./latex tools.ins)
	@touch -f ${BUILD_COOKIE}

install:
	@echo "===>  Installing for ${DISTNAME}"
	@(/usr/bin/install -c -m 644 ${WRKSRC}/base/latex.fmt \
				${PREFIX}/lib/texmf/ini/)
	@(cd ${WRKSRC}/tfm; install -c -m 644 *.tfm ${PREFIX}/lib/texmf/fonts/tfm)
	@(cd ${WRKSRC}/mf; install -c -m 644 *.mf ${PREFIX}/lib/texmf/mf)
	@(cd ${WRKSRC}/base; for f in latexbug.tex testpage.tex \
	   lablst.tex idx.tex nfssfont.tex small2e.tex sample2e.tex docstrip.tex \
	   *.cls *.clo *.sty *.fd *.def *.cfg ; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/lib/texmf/tex; fi; done)
	@mkdir -p ${PREFIX}/lib/texmf/makeindx;
	@(cd ${WRKSRC}/base; install -c -m 644 *.ist ${PREFIX}/lib/texmf/makeindx)
	@(cd ${WRKSRC}/packages/tools; for f in *.sty *.tex; do \
	    if [ -f $$f ]; then install -c -m 644  $$f ${PREFIX}/lib/texmf/tex; fi; done)
	@(cd ${PREFIX}/bin; rm -f latex; ln -s virtex latex)

.include "Makefile.inc"

.include <bsd.port.mk>
