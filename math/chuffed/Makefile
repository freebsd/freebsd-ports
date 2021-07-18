PORTNAME=	chuffed
DISTVERSION=	0.10.4.20210104
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lazy clause generation CP solver for MiniZinc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_TAGNAME=	e04bedd # devel branch: only devel branch is compatible with the current MiniZinc

GH_TUPLE=	cp-profiler:cpp-integration:f16b313:cpi/submodules/cp-profiler-integration

DATADIR=	${PREFIX}/share/minizinc/chuffed

post-install:
	# correct version in the config file
	${REINPLACE_CMD} -i '' -e 's|"version": ".*",|"version": "${PORTVERSION}",|' \
		${STAGEDIR}${PREFIX}/share/minizinc/solvers/chuffed.msc

.include <bsd.port.mk>
