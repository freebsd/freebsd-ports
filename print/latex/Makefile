# New ports collection makefile for:    latex
# Date created:         29 September 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	latex2e
PORTVERSION=	99.12
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/tex/package/
DISTFILES=	latex_mf-${PORTVERSION}.tar.gz latex_tfm-${PORTVERSION}.tar.gz \
		latex_base-${PORTVERSION}.tar.gz latex_tools-${PORTVERSION}.tar.gz \
		latex_graphics-${PORTVERSION}.tar.gz latex_psnfss-${PORTVERSION}.tar.gz

MAINTAINER=	jmz@FreeBSD.org

BUILD_DEPENDS=	tex:${PORTSDIR}/print/tex
RUN_DEPENDS=	tex:${PORTSDIR}/print/tex

NO_WRKSUBDIR=	yes

MANUAL_PACKAGE_BUILD=	has to be built with tex port

do-build:
	@(cd ${WRKSRC}/base; tex --ini unpack.ins)
	@(cd ${WRKSRC}/base; TEXFONTS=${WRKSRC}/tfm:; export TEXFONTS; \
		tex --ini latex.ltx </dev/null)
	@(cd ${WRKSRC}/tools; TEXFORMATS=${WRKSRC}/base:; \
		TEXINPUTS=${WRKSRC}/base: export TEXFORMATS TEXINPUTS;\
		 ${LN} -sf ${PREFIX}/bin/tex latex; ./latex tools.ins)
	@(cd ${WRKSRC}/graphics; TEXFORMATS=${WRKSRC}/base:; \
		TEXINPUTS=${WRKSRC}/base: export TEXFORMATS TEXINPUTS;\
		 ${LN} -sf ${PREFIX}/bin/tex latex; ./latex graphics.ins)
	@(cd ${WRKSRC}/psnfss; TEXFORMATS=${WRKSRC}/base:; \
		TEXINPUTS=${WRKSRC}/base: export TEXFORMATS TEXINPUTS;\
		${CHMOD} u+w mh2scr.enc;\
		 ${LN} -sf ${PREFIX}/bin/tex latex; for f in adobe charter\
		 mathtime psfonts alucida lucidabr nimbus utopia; do \
		./latex $$f.ins; done)

do-install:
	@(${INSTALL_DATA} ${WRKSRC}/base/latex.fmt ${PREFIX}/share/texmf/web2c/)
	@(cd ${WRKSRC}/tfm; ${INSTALL_DATA} *.tfm ${PREFIX}/share/texmf/fonts/tfm)
	@(cd ${WRKSRC}/mf; ${INSTALL_DATA} *.mf ${PREFIX}/share/texmf/metafont)
	@${MKDIR} ${PREFIX}/share/texmf/tex/latex
	@(cd ${WRKSRC}/base; for f in latexbug.tex testpage.tex \
	   lablst.tex idx.tex nfssfont.tex small2e.tex sample2e.tex docstrip.tex \
	   *.cls *.clo *.sty *.fd *.def *.cfg ; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${PREFIX}/share/texmf/tex/latex; fi; done)
	@${MKDIR} ${PREFIX}/share/texmf/makeindx;
	@(cd ${WRKSRC}/base; ${INSTALL_DATA} *.ist ${PREFIX}/share/texmf/makeindx)
	@(cd ${WRKSRC}/tools; for f in *.sty *.tex; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${PREFIX}/share/texmf/tex/latex; fi; done)
	@(cd ${WRKSRC}/graphics; for f in *.sty *.tex *.def; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${PREFIX}/share/texmf/tex/latex; fi; done;\
	    ${ECHO} '\ExecuteOptions{dvips}' >${PREFIX}/share/texmf/tex/latex/graphics.cfg;\
	    ${ECHO} '\ExecuteOptions{dvips}' >${PREFIX}/share/texmf/tex/latex/color.cfg)
	@(cd ${WRKSRC}/psnfss; for f in *.sty *.tex; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${PREFIX}/share/texmf/tex/latex; fi; done)
	@(cd ${PREFIX}/bin; ${RM} -f latex; ${LN} -s tex latex)
	@(${MKDIR} ${PREFIX}/share/texmf/documentation)
	@(cd ${WRKSRC}/base; for f in *.dtx ltx3info.tex source2e.tex *.fdd ltnews*.tex *guide.tex; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${PREFIX}/share/texmf/documentation; fi; done)
	@(cd ${WRKSRC}/tools; for f in *.dtx; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${PREFIX}/share/texmf/documentation; fi; done)
	@(cd ${WRKSRC}/graphics; for f in *.dtx; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${PREFIX}/share/texmf/documentation; fi; done)
	@(cd ${WRKSRC}/psnfss; for f in *.dtx; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${PREFIX}/share/texmf/documentation; fi; done)
	@(cd ${PREFIX}/bin; ${RM} -f latex; ${LN} -s tex latex)

.include <bsd.port.mk>
