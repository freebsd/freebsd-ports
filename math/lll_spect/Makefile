# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lll_spect
DISTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	LOCAL/bf/lll_spect/
DISTFILES=	lll_spect.C lll_search.C examples.txt
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	bf@FreeBSD.org
COMMENT=	LLL-spectral test of linear congruential random number generators

BUILD_DEPENDS=	${LOCALBASE}/lib/libntl.a:math/ntl
RUN_DEPENDS=	${LOCALBASE}/lib/libntl.a:math/ntl

PLIST_FILES=	bin/lll_spect bin/lll_search
PORTEXAMPLES=	examples.txt
NO_WRKSUBDIR=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	EXAMPLES

post-extract:
.for _file in lll_spect lll_search
	@${CP} ${_DISTDIR}/${_file}.C ${WRKSRC}
.endfor

do-build:
.for _file in lll_spect lll_search
	${CXX} ${CXXFLAGS} ${CPPFLAGS} -c -o ${WRKSRC}/${_file}.o ${WRKSRC}/${_file}.C
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o ${WRKSRC}/${_file} ${WRKSRC}/${_file}.o -lntl -lgmp -lm
.endfor

do-install:
.for _file in lll_spect lll_search
	${INSTALL_PROGRAM} ${WRKSRC}/${_file} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${_DISTDIR}/examples.txt ${STAGEDIR}${EXAMPLESDIR}

test: build
	@${WRKSRC}/lll_spect "${WRKSRC}/output_spect" 17 16907 2147483647
	@${WRKSRC}/lll_search "${WRKSRC}/output_search" 2147483647 2 3 7 11 31 151 331
	@${SED} -n -e '/Modul/,/Time/p' ${_DISTDIR}/examples.txt > ${WRKSRC}/output_spect_example
	@${SED} -n -e '/may yield/,/Therefore/p' \
		${_DISTDIR}/examples.txt > ${WRKSRC}/output_search_example

.include <bsd.port.mk>
