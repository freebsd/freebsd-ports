PORTNAME=	PuLP
DISTVERSION=	2.8.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LP modeler written in python
WWW=		https://github.com/coin-or/pulp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amply>=0.1.2:math/py-amply@${PY_FLAVOR} \
		cbc:math/cbc \
		glpsol:math/glpk

USES=		cpe python
CPE_VENDOR=	${PORTNAME:tl}project
USE_PYTHON=	distutils concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

post-patch:
	@${CP} ${WRKSRC}/pulp/pulp.cfg.linux ${WRKSRC}/pulp/pulp.cfg.freebsd
	@${REINPLACE_CMD} -E 's/^(CplexPath|PulpCbcPath) = .*/#&/' ${WRKSRC}/pulp/pulp.cfg.freebsd

post-install: # workaround for https://github.com/coin-or/pulp/issues/740: replace cbc binaries for other systems with the FreeBSD binary
	for cbc_exe in ${STAGEDIR}${PYTHON_SITELIBDIR}/pulp/solverdir/cbc/*/*/cbc ${WRKSRC}/pulp/solverdir/cbc/*/*/cbc; do \
		${RM} $${cbc_exe} && \
		${LN} -s ${LOCALBASE}/bin/cbc $${cbc_exe}; \
	done

do-test: # one test is known to fail: https://github.com/coin-or/pulp/issues/494
	#@cd ${TEST_WRKSRC} && py.test
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "import pulp; pulp.pulpTestAll()"

.include <bsd.port.mk>
