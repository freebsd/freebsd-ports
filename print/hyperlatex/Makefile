# New ports collection makefile for:	Hyperlatex
# Date created:				2 August 1994
# Whom:					Robert Withrow <witr@rwwa.com>
#
# $FreeBSD$
#

PORTNAME=	Hyperlatex
PORTVERSION=	2.6
CATEGORIES=	print
MASTER_SITES=	http://www.cs.uu.nl/~otfried/Hyperlatex/

MAINTAINER=	witr@rwwa.com
COMMENT=	Produce HTML and printed documents from LaTeX source

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs21
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs21 \
		latex:${PORTSDIR}/print/teTeX \
		ppmtogif:${PORTSDIR}/graphics/netpbm

USE_REINPLACE=	yes
LATEX_DIR=	${PREFIX}/share/texmf/tex/latex
HYPERLATEX_DIR=	${PREFIX}/share/texmf/tex/latex/hyperlatex

do-configure:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's|http://www.cs.uu.nl/\\~{}otfried/img/||' siteinit.hlx && \
	${REINPLACE_CMD} -e 's|$$HOME/Hyperlatex/Hlx|${PREFIX}/share/texmf/tex/latex/hyperlatex|' hyperlatex)

do-build:
	cd ${WRKSRC}; emacs -batch -q -no-site-file -l hyperlatex.el -f hyperlatex-compile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hyperlatex ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ps2gif ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/hyperlatex.sty ${LATEX_DIR}
	${MKDIR} ${HYPERLATEX_DIR}
	cd ${WRKSRC}; for f in *.el *.elc *.hlx *.xbm *.awk ; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${HYPERLATEX_DIR}; fi; done

.include <bsd.port.mk>
