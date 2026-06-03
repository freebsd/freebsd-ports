PORTNAME=	neko
DISTVERSION=	1.0.3
CATEGORIES=	science
MASTER_SITES=	https://github.com/ExtremeFLOW/neko/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for high-order spectral element flow simulations
WWW=		https://neko.cfd/ \
		https://github.com/ExtremeFLOW/neko

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjsonfortran.so:devel/json-fortran \
		libopenblas.so:math/openblas
TEST_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}json5>=0:devel/py-json5@${PY_FLAVOR}

USES=		fortran gmake libtool mpi:mpich pkgconfig python:test shebangfix

SHEBANG_GLOB=	*.sh

GNU_CONFIGURE=	yes

BINARY_ALIAS=	python=${PYTHON_CMD}

do-test:
	@${MKDIR} ${WRKSRC}/contrib/neko_log_parser
	@${CP} ${FILESDIR}/neko_log_parser.py ${WRKSRC}/contrib/neko_log_parser/
	@${CHMOD} +x ${WRKSRC}/makeneko
	@${REINPLACE_CMD} -e 's|^prefix=.*|prefix=${WRKSRC}|' \
		-e 's|^includedir_pkg=.*|includedir_pkg=${WRKSRC}/src|' \
		-e 's|^libdir=.*|libdir=${WRKSRC}/src/.libs|' \
		${WRKSRC}/makeneko ${WRKSRC}/neko.pc
	@cd ${WRKSRC}/tests/integration && ${SETENV} ${TEST_ENV} \
		PKG_CONFIG_PATH=${WRKSRC} \
		NEKO_EXEC=${WRKSRC}/src/neko \
		MAKENEKO_EXEC=${WRKSRC}/makeneko \
		PYTHONNOUSERSITE=1 \
		${PYTHON_CMD} -m pytest -p no:xdist -p no:parallel \
		--launcher-script=${WRKSRC}/tests/integration/default_cpu_launcher.sh \
		tests

# tests as of 1..3: 14 passed in 38.37s

.include <bsd.port.mk>
