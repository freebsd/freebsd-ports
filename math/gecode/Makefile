# Created by: Peter Pentchev <roam@FreeBSD.org>

PORTNAME=	gecode
DISTVERSIONPREFIX=	release-
DISTVERSION=	6.3.0
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	3b86d0dabc371d5976c5dafef0fc7f6c5f92640b.patch:-p1 # https://github.com/Gecode/gecode/pull/102: Fix MOC invocation in gist folder
PATCHFILES+=	b8954e4e5a4c0faf65eb72d62f7e7b377bea14bb.patch:-p1 # https://github.com/Gecode/gecode/pull/104: Ready fzn-gecode as MiniZinc solver on make install

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic Constraint Development Environment

LICENSE=	BSL MIT
LICENSE_COMB=	multi

NOT_FOR_ARCHS=		aarch64 armv6 armv7 mips mips64
NOT_FOR_ARCHS_REASON=	needs code written to specify rounding control mechanism in Boost.Numeric.Interval

USES=		bison:alias cmake compiler:c++11-lang

USE_GITHUB=	yes
GH_ACCOUNT=	Gecode
GH_TAGNAME=	9428cd8 # 6.3.0 branch is ready for a long time, but hasn't been tagged yet

CMAKE_ON=	BUILD_SHARED_LIBS

DATADIR=	${PREFIX}/share/minizinc/gecode # it only installs the MiniZinc library into DATADIR

OPTIONS_DEFINE=		GIST
OPTIONS_SUB=		yes

GIST_DESC=		Enable gist, graphical and interactive search tool
GIST_CMAKE_BOOL=	ENABLE_GIST
GIST_USES=		qt:5
GIST_USE=		qt=core,gui,printsupport,widgets,qmake_build,buildtools_build

.include <bsd.port.mk>
