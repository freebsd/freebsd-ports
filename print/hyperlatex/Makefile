PORTNAME=	Hyperlatex
DISTVERSION=	2.9a
PORTREVISION=	27
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/2.9a

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Produce HTML and printed documents from LaTeX source
WWW=		https://hyperlatex.sourceforge.net/

RUN_DEPENDS=	ppmtogif:graphics/netpbm

USES=		emacs tex
USE_TEX=	latex

CONFLICTS_INSTALL=	Hyperlatex-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

CONFLICTS_INSTALL=	 Hyperlatex-emacs_*

LATEX_DIR=	${PREFIX}/share/texmf/tex/latex/hyperlatex
HYPERLATEX_DIR=	${PREFIX}/share/hyperlatex

do-configure:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's|http://www.cs.uu.nl/\\~{}otfried/img/||' hlx/siteinit.hlx && \
	${REINPLACE_CMD} -e 's|$$HOME/Hyperlatex/Hlx|${HYPERLATEX_DIR}|' bin/hyperlatex && \
	${REINPLACE_CMD} -e '1s|^#$$|#\!/usr/bin/awk|' bin/normalize-eps.awk)

do-install:
	@${MKDIR} ${STAGEDIR}${HYPERLATEX_DIR}
	@${MKDIR} ${STAGEDIR}${LATEX_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hyperlatex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ps2image ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/normalize-eps.awk \
		${STAGEDIR}${PREFIX}/bin/normalize-eps
	${INSTALL_DATA} ${WRKSRC}/etc/hyperlatex.sty ${STAGEDIR}${LATEX_DIR}
	cd ${WRKSRC}/hlx; for f in *.el *.hlx *.xbm *.awk ; do \
	    if [ -f $$f ]; then ${INSTALL_DATA} $$f \
	    ${STAGEDIR}${HYPERLATEX_DIR}; fi; done

.include <bsd.port.mk>
