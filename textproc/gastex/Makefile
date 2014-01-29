# Created by: Volker Stolz <vs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gastex
PORTVERSION=	2.7
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.lsv.ens-cachan.fr/~gastin/gastex/
DISTFILES=	gastex.sty gastex.pro ex-gastex.tex
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphs and Automata Simplified in TeX

USE_TEX=	latex
NO_BUILD=	yes

TEXMFDIR?=	share/texmf
GASTEXDIR=	${PREFIX}/${TEXMFDIR}/tex/latex/gastex
GASDVIDIR=	${PREFIX}/${TEXMFDIR}/dvips/gastex

do-install:
	@${MKDIR} ${STAGEDIR}${GASTEXDIR}
	@${MKDIR} ${STAGEDIR}${GASDVIDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${_DISTDIR}/gastex.sty ${STAGEDIR}${GASTEXDIR}
	${INSTALL_DATA} ${_DISTDIR}/gastex.pro ${STAGEDIR}${GASDVIDIR}
	${INSTALL_DATA} ${_DISTDIR}/ex-gastex.tex ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
