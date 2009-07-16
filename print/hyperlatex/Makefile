# New ports collection makefile for:	Hyperlatex
# Date created:				2 August 1994
# Whom:					Robert Withrow <witr@rwwa.com>
#
# $FreeBSD$
#

PORTNAME=	Hyperlatex
DISTVERSION=	2.9a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=hyperlatex

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce HTML and printed documents from LaTeX source

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX \
		ppmtogif:${PORTSDIR}/graphics/netpbm

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

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
	${MKDIR} ${HYPERLATEX_DIR}
	${MKDIR} ${LATEX_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hyperlatex ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ps2image ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/normalize-eps.awk ${PREFIX}/bin/normalize-eps
	${INSTALL_DATA} ${WRKSRC}/etc/hyperlatex.sty ${LATEX_DIR}
	cd ${WRKSRC}/hlx; for f in *.el *.elc *.hlx *.xbm *.awk ; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f ${HYPERLATEX_DIR}; fi; done

.include <bsd.port.mk>
