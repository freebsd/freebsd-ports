# Created by: Peter Pentchev <roam@FreeBSD.org>

PORTNAME=	gecode
DISTVERSIONPREFIX=	release-
DISTVERSION=	6.3.0
PORTREVISION=	6
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic Constraint Development Environment

LICENSE=	BSL MIT
LICENSE_COMB=	multi

NOT_FOR_ARCHS=		armv6 armv7 mips mips64
NOT_FOR_ARCHS_REASON=	needs code written to specify rounding control mechanism in Boost.Numeric.Interval

USES=		bison:build compiler:c++11-lang gmake perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-examples

USE_GITHUB=	yes
GH_ACCOUNT=	Gecode
GH_TAGNAME=	6b09bea # 6.3.0 branch is ready for a long time, but hasn't been tagged yet

DATADIR=	${PREFIX}/share/minizinc/gecode # it only installs the MiniZinc library into DATADIR

OPTIONS_DEFINE=		AUDIT CBS FLATZINC GIST PEAKHEAP PROFILE SEARCH
OPTIONS_RADIO=		LIBTYPE
OPTIONS_RADIO_LIBTYPE=	SHARED STATIC
OPTIONS_DEFAULT=	CBS FLATZINC SEARCH SHARED
OPTIONS_SUB=		yes
LIBTYPE_DESC=		Library type

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
GIST_IMPLIES=			SHARED # because Qt must be built in a special way: error: "You must build your code with position independent code if Qt was built with -reduce-relocations"
GIST_MAKE_ARGS=			FREEBSD_LDFLAGS=-L${LOCALBASE}/lib

PEAKHEAP_DESC=			Peak heap size tracking
PEAKHEAP_CONFIGURE_ENABLE=	peakheap

PROFILE_DESC=			Build with profiling information
PROFILE_CONFIGURE_ENABLE=	profile

SEARCH_DESC=			Build search engines
SEARCH_CONFIGURE_ENABLE=	search

SHARED_DESC=			Build shared executables and/or libraries
SHARED_CONFIGURE_ENABLE=	shared

STATIC_CONFIGURE_ENABLE=	static

TEST_TARGET=	check

post-patch-STATIC-on: # workaround for https://github.com/Gecode/gecode/issues/117
	@${REINPLACE_CMD} -e 's| -fPIC | |; s|"-fPIC|"|' ${WRKSRC}/configure

post-install-SHARED-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so.*.*

post-install-FLATZINC-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fzn-gecode

post-install-FLATZINC-off: # https://github.com/Gecode/gecode/issues/108
	@cd ${STAGEDIR}${PREFIX} && ${RMDIR} share/minizinc/gecode share/minizinc/solvers share/minizinc

test-extended: stage # breaks, see https://github.com/Gecode/gecode/issues/109
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test && \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ./test/test -test -Float

.include <bsd.port.mk>
