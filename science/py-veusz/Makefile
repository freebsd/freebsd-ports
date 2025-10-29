PORTNAME=	veusz
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	4.2
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific plotting package
WWW=		https://veusz.github.io/ \
		https://github.com/veusz/veusz

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}tomli>0:textproc/py-tomli@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang python pyqt:6 qt:6 shebangfix
USE_GITHUB=	yes
USE_PYQT=	pyqt6 sip:build
USE_PYTHON=	distutils concurrent autoplist pytest
USE_QT=		base tools:build

SHEBANG_FILES=	tests/runselftest.py examples/embedexample.py

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	# strip
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/veusz/helpers/*.so

do-test:
	@cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ./runselftest.py

# tests as of 4.2: All tests 76/76 PASSED

.include <bsd.port.mk>
