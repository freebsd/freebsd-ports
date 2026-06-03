PORTNAME=	PuLP
DISTVERSION=	3.3.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LP modeler written in python
WWW=		https://github.com/coin-or/pulp

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	cbc:math/cbc \
		glpsol:math/glpk

USES=		cpe python
CPE_VENDOR=	${PORTNAME:tl}project
USE_PYTHON=	distutils concurrent autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

post-extract: # pyproject.toml references setup.py and setup.py is missing in the tarball
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/setup.py
	@${MV} ${WRKSRC}/pyproject.toml ${WRKSRC}/pyproject.toml.bak

post-install: # workaround for https://github.com/coin-or/pulp/issues/740: replace cbc binaries for other systems with the FreeBSD binary
	@for cbc_exe in ${STAGEDIR}${PYTHON_SITELIBDIR}/pulp/solverdir/cbc/*/*/cbc; do \
		if [ -f "$${cbc_exe}" ]; then \
			${RM} $${cbc_exe} && \
			${LN} -s ${LOCALBASE}/bin/cbc $${cbc_exe}; \
		fi; \
	done

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "from pulp.tests.run_tests import pulpTestAll; pulpTestAll()" || true

# tests as of 3.3.0: All tests pass

.include <bsd.port.mk>
