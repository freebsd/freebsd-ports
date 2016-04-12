# Created by: Robert Withrow <witr@rwwa.com>
# $FreeBSD$

PORTNAME=	Hyperlatex
DISTVERSION=	2.9a
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/2.9a

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce HTML and printed documents from LaTeX source

RUN_DEPENDS=	ppmtogif:graphics/netpbm

USE_TEX=	latex
USE_EMACS=	yes

LATEX_DIR=	${PREFIX}/share/texmf/tex/latex/hyperlatex
HYPERLATEX_DIR=	${PREFIX}/share/hyperlatex

do-configure:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's|http://www.cs.uu.nl/\\~{}otfried/img/||' hlx/siteinit.hlx && \
	${REINPLACE_CMD} -e 's|$$HOME/Hyperlatex/Hlx|${HYPERLATEX_DIR}|' bin/hyperlatex && \
	${REINPLACE_CMD} -e '1s|^#$$|#\!/usr/bin/awk|' bin/normalize-eps.awk)

do-build:
	cd ${WRKSRC}/hlx; emacs -batch -q -no-site-file -l hyperlatex.el -f hyperlatex-compile

do-install:
	@${MKDIR} ${STAGEDIR}${HYPERLATEX_DIR}
	@${MKDIR} ${STAGEDIR}${LATEX_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hyperlatex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ps2image ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/normalize-eps.awk \
		${STAGEDIR}${PREFIX}/bin/normalize-eps
	${INSTALL_DATA} ${WRKSRC}/etc/hyperlatex.sty ${STAGEDIR}${LATEX_DIR}
	cd ${WRKSRC}/hlx; for f in *.el *.elc *.hlx *.xbm *.awk ; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f \
	    ${STAGEDIR}${HYPERLATEX_DIR}; fi; done

.include <bsd.port.mk>
