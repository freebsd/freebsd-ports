# Created by: Peter Pentchev <roam@FreeBSD.org>

PORTNAME=	gecode
DISTVERSIONPREFIX=	release-
DISTVERSION=	6.3.0
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	3b86d0dabc371d5976c5dafef0fc7f6c5f92640b.patch:-p1 # https://github.com/Gecode/gecode/pull/102: Fix MOC invocation in gist folder

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic Constraint Development Environment

LICENSE=	BSL MIT
LICENSE_COMB=	multi

NOT_FOR_ARCHS=		aarch64 armv6 armv7 mips mips64
NOT_FOR_ARCHS_REASON=	needs code written to specify rounding control mechanism in Boost.Numeric.Interval

USES=		bison:alias compiler:c++11-lang gmake perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-examples

USE_GITHUB=	yes
GH_ACCOUNT=	Gecode
GH_TAGNAME=	96ca4cc # 6.3.0 branch is ready for a long time, but hasn't been tagged yet

DATADIR=	${PREFIX}/share/minizinc/gecode # it only installs the MiniZinc library into DATADIR

OPTIONS_DEFINE=		AUDIT CBS FLATZINC GIST PEAKHEAP PROFILE SEARCH
OPTIONS_DEFAULT=	CBS FLATZINC SEARCH
OPTIONS_SUB=		yes

AUDIT_DESC=			Build with auditing code
AUDIT_CONFIGURE_ENABLE=		audit

CBS_DESC=			Support for counting-based search
CBS_CONFIGURE_ENABLE=		cbs

FLATZINC_DESC=			Build FlatZinc interpreter
FLATZINC_CONFIGURE_ENABLE=	flatzinc

GIST_DESC=			Enable gist, graphical and interactive search tool
GIST_CONFIGURE_ENABLE=		gist qt
GIST_USES=			gl qt:5
GIST_USE=			gl=gl qt=core,gui,printsupport,widgets,qmake_build,buildtools_build

PEAKHEAP_DESC=			Peak heap size tracking
PEAKHEAP_CONFIGURE_ENABLE=	peakheap

PROFILE_DESC=			Build with profiling information
PROFILE_CONFIGURE_ENABLE=	profile

SEARCH_DESC=			Build search engines
SEARCH_CONFIGURE_ENABLE=	search

TEST_TARGET=	check

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/lib/lib*.so.*.*

post-install-FLATZINC-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fzn-gecode

post-install-FLATZINC-off: # https://github.com/Gecode/gecode/issues/108
	@cd ${STAGEDIR}${PREFIX} && ${RMDIR} share/minizinc/gecode share/minizinc/solvers share/minizinc

test-extended: stage # breaks, see https://github.com/Gecode/gecode/issues/109
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test && \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ./test/test -test -Float

.include <bsd.port.mk>
