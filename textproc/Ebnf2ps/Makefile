# New ports collection makefile for:	Ebnf2ps
# Date created:				Nov 27, 2003
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Ebnf2ps
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://www.informatik.uni-freiburg.de/~thiemann/haskell/ebnf2ps/
DISTNAME=	ebnf2ps-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Generate EPS/FIG diagrams from EBNF/yacc/bison grammars

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes
USE_XLIB=	yes
USE_SUBMAKE=	yes

MAKE_ENV+=	X11BASE=${X11BASE}
.if defined(AFMPATH)
MAKE_ENV+=	AFMPATH=${AFMPATH}
.endif

EXAMPLES=	ebnf.BNF examples.ps gofer.BNF regular.BNF

.if !defined(NOPORTDOCS)
DOC_EPS=	Atom.eps Atom_unfold.eps Character.eps Export.eps \
		ExtAtom.eps Factor.eps File.eps Nonterminal.eps \
		Production.eps Production_unfold.eps RAtom.eps \
		RAtom_unfold.eps RExtAtom.eps RFactor.eps Regexp.eps \
		String.eps Term.eps
.endif

do-configure:
	@( cd ${WRKSRC}/src && ${MAKE} ${MAKE_ENV} afmpath.h && \
	    ${MAKE} ${MAKE_ENV} rgbpath.h )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
.for example in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${example} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/doc.ps ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/doc.tex ${DOCSDIR}
.for eps in ${DOC_EPS}
	${INSTALL_MAN} ${WRKSRC}/doc/${eps} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
