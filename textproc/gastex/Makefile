# Created by: Volker Stolz <vs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gastex
PORTVERSION=	3.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.lsv.ens-cachan.fr/~gastin/gastex/
DISTFILES=	gastex.sty gastex.pro
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphs and Automata Simplified in TeX

NO_ARCH=	yes
USE_TEX=	latex:run
NO_BUILD=	yes

EXAMPLES_DISTFILES=	ex-gastex.tex

TEXMFDIR?=	share/texmf
GASTEXDIR=	${PREFIX}/${TEXMFDIR}/tex/latex/gastex
GASDVIDIR=	${PREFIX}/${TEXMFDIR}/dvips/gastex

OPTIONS_DEFINE=	EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${GASTEXDIR}
	@${MKDIR} ${STAGEDIR}${GASDVIDIR}
	${INSTALL_DATA} ${_DISTDIR}/gastex.sty ${STAGEDIR}${GASTEXDIR}
	${INSTALL_DATA} ${_DISTDIR}/gastex.pro ${STAGEDIR}${GASDVIDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${_DISTDIR}/ex-gastex.tex ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
