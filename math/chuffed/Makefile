PORTNAME=	chuffed
DISTVERSION=	0.10.4
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lazy clause generation CP solver for MiniZinc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison cmake compiler:c++11-lang
USE_GITHUB=	yes

GH_TUPLE=	cp-profiler:cpp-integration:d695d93:cpi/submodules/cp-profiler-integration

CXXFLAGS+=	-I${BUILD_WRKSRC}/chuffed/flatzinc # workaround for: fatal error: 'parser.tab.h' file not found, see https://github.com/chuffed/chuffed/issues/75

post-patch: # workaround for: unknown symbol YYEMPTY: wrong parser.tab.h is used by the build, see https://github.com/chuffed/chuffed/issues/75
	@${RM} ${WRKSRC}/chuffed/flatzinc/parser.tab.h

post-install:
	# move the msc file where MiniZinc looks for it, see https://github.com/chuffed/chuffed/issues/74
	cd ${STAGEDIR}${PREFIX} && \
		${MKDIR} share/minizinc/solvers && \
		${MV} chuffed.msc share/minizinc/solvers
	# adjust mzn executable and lib paths for MiniZinc to find them
	${REINPLACE_CMD} -i '' -e 's|bin/|${PREFIX}/&| ; s|share/chuffed/|${PREFIX}/&|' \
		${STAGEDIR}${PREFIX}/share/minizinc/solvers/chuffed.msc

.include <bsd.port.mk>
