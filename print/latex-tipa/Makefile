# New ports collection makefile for:	tipa
# Date created:		18 November 2003
# Whom:			Andreas Braml
#
# $FreeBSD$
#

PORTNAME=	latex-tipa
PORTVERSION=	1.3
CATEGORIES=	print
MASTER_SITES=	http://www.braml.org/
DISTNAME=	tipa-${PORTVERSION}

MAINTAINER=	a.strich.b@web.de
COMMENT=	Package which provides T3-encoded fonts to be used with LaTeX2e

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_INSTALL_MANPAGES=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
LATEX_BIN=	${LOCALBASE}/bin/latex

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/teTeX/share/texmf|${PREFIX}/share/texmf|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/texmf/doc/latex/tipa
	@(cd ${WRKSRC}/doc; ${LATEX_BIN} tipaman; \
	 ${LOCALBASE}/bin/bibtex tipaman; ${LATEX_BIN} tipaman; ${LATEX_BIN} tipaman)
	${INSTALL_MAN} ${WRKSRC}/doc/tipaman.dvi ${PREFIX}/share/texmf/doc/latex/tipa
.endif

.include <bsd.port.mk>
