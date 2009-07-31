# New ports collection makefile for:	gastex
# Date created:			Sep 18. 2005
# Whom:				Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gastex
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.lsv.ens-cachan.fr/~gastin/gastex/
DISTFILES=	gastex.sty gastex.pro ex-gastex.tex
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	#

MAINTAINER=	vs@FreeBSD.org
COMMENT=	Graphs and Automata Simplified in TeX

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

NO_BUILD=	yes

TEXMFDIR?=	share/texmf
GASTEXDIR=	${PREFIX}/${TEXMFDIR}/tex/latex/gastex
GASDVIDIR=	${PREFIX}/${TEXMFDIR}/dvips/gastex

do-install:
	@${MKDIR} ${GASTEXDIR}
	@${MKDIR} ${GASDVIDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${_DISTDIR}/gastex.sty ${GASTEXDIR}
	${INSTALL_DATA} ${_DISTDIR}/gastex.pro ${GASDVIDIR}
	${INSTALL_DATA} ${_DISTDIR}/ex-gastex.tex ${EXAMPLESDIR}
	mktexlsr

.include <bsd.port.mk>
