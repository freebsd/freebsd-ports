# New ports collection makefile for:	Hyperlatex
# Date created:				2 August 1994
# Whom:					Robert Withrow <witr@rwwa.com>
#
# $FreeBSD$
#

PORTNAME=	Hyperlatex
PORTVERSION=	2.3.1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.uni-magdeburg.de/pub/ipe/

MAINTAINER=	witr@rwwa.com

BUILD_DEPENDS=	emacs:${PORTSDIR}/editors/emacs20
RUN_DEPENDS=	emacs:${PORTSDIR}/editors/emacs20 \
		latex:${PORTSDIR}/print/latex

LATEX_DIR=	${PREFIX}/share/texmf/tex/latex
HYPERLATEX_DIR=	${PREFIX}/share/texmf/tex/latex/hyperlatex

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
