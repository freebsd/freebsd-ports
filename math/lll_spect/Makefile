# New ports collection makefile for:	lll_spect
# Date created:		6 Feb. 2010
# Whom:			bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lll_spect
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://random.mat.sbg.ac.at/results/karl/spectraltest/LLLSpectralTest/
DISTFILES=	lll_spect.C lll_search.C examples.txt
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	bf@FreeBSD.org
COMMENT=	LLL-spectral test of linear congruential random number generators

BUILD_DEPENDS=	${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl
RUN_DEPENDS=	${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl

PLIST_FILES=	bin/lll_spect bin/lll_search
PORTEXAMPLES=	examples.txt
NO_WRKSUBDIR=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
.for _file in lll_spect lll_search
	@${CP} ${_DISTDIR}/${_file}.C ${WRKDIR}
.endfor

do-build:
.for _file in lll_spect lll_search
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -c -o ${WRKDIR}/${_file}.o ${WRKDIR}/${_file}.C
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o ${WRKDIR}/${_file} ${WRKDIR}/${_file}.o -lntl -lgmp -lm
.endfor

do-install:
.for _file in lll_spect lll_search
	${INSTALL_PROGRAM} ${WRKDIR}/${_file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${_DISTDIR}/examples.txt ${EXAMPLESDIR}
.endif

test: build
	@${WRKSRC}/lll_spect "${WRKSRC}/output_spect" 17 16907 2147483647
	@${WRKSRC}/lll_search "${WRKSRC}/output_search" 2147483647 2 3 7 11 31 151 331
	@${SED} -n -e '/Modul/,/Time/p' ${_DISTDIR}/examples.txt > ${WRKSRC}/output_spect_example
	@${SED} -n -e '/may yield/,/Therefore/p' \
		${_DISTDIR}/examples.txt > ${WRKSRC}/output_search_example

.include <bsd.port.mk>
