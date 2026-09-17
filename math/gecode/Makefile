PORTNAME=	gecode
DISTVERSIONPREFIX=	release-
DISTVERSION=	6.4.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic Constraint Development Environment
WWW=		https://www.gecode.dev/ \
		https://github.com/gecode/gecode

LICENSE=	BSL MIT
LICENSE_COMB=	multi

NOT_FOR_ARCHS=		armv6 armv7
NOT_FOR_ARCHS_REASON=	needs code written to specify rounding control mechanism in Boost.Numeric.Interval

USES=		bison:build cmake compiler:c++11-lang perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Gecode

DATADIR=	${PREFIX}/share/minizinc/gecode # it only installs the MiniZinc library into DATADIR

CMAKE_ON=	GECODE_ENABLE_QT
CMAKE_OFF=	BUILD_EXAMPLES

OPTIONS_DEFINE=		AUDIT CBS FLATZINC GIST PROFILE SEARCH
OPTIONS_MULTI=		LIBTYPE
OPTIONS_MULTI_LIBTYPE=	SHARED STATIC
OPTIONS_DEFAULT=	CBS FLATZINC SEARCH SHARED STATIC
OPTIONS_SUB=		yes
LIBTYPE_DESC=		Library type

AUDIT_DESC=			Build with auditing code
AUDIT_CMAKE_BOOL=		GECODE_ENABLE_AUDIT

CBS_DESC=			Support for counting-based search
CBS_CMAKE_BOOL=			GECODE_ENABLE_CBS

FLATZINC_DESC=			Build FlatZinc module
FLATZINC_CMAKE_BOOL=		GECODE_ENABLE_FLATZINC
FLATZINC_USES=			qt:6
FLATZINC_USE=			qt=base,tools:build

GIST_DESC=			Enable gist, graphical and interactive search tool
GIST_CMAKE_BOOL=		GECODE_ENABLE_GIST
GIST_IMPLIES=			SHARED # because Qt must be built in a special way: error: "You must build your code with position independent code if Qt was built with -reduce-relocations"

PROFILE_DESC=			Build with profiling information
PROFILE_CMAKE_BOOL=		GECODE_ENABLE_CPPROFILER

SEARCH_DESC=			Build search engines
SEARCH_CMAKE_BOOL=		GECODE_ENABLE_SEARCH

SHARED_DESC=			Build shared executables and/or libraries
SHARED_CMAKE_BOOL=		GECODE_BUILD_SHARED
SHARED_LIB_DEPENDS=		libgmp.so:math/gmp \
				libmpfr.so:math/mpfr

STATIC_CMAKE_BOOL=		GECODE_BUILD_STATIC

TEST_TARGET=	check

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHARED} && ${PORT_OPTIONS:MGIST}
USES+=		gl qt:6
USE_QT=		base tools:build
USE_GL=		gl
.endif

post-patch-STATIC-on: # workaround for https://github.com/Gecode/gecode/issues/117
	@${REINPLACE_CMD} -e 's| -fPIC | |; s|"-fPIC|"|' ${WRKSRC}/configure

.include <bsd.port.mk>
