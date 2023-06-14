PORTNAME=	veusz
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	3.6.2
PORTREVISION=	3
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific plotting package
WWW=		https://veusz.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}tomli>0:textproc/py-tomli@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang python pyqt:5 qt:5 shebangfix
USE_GITHUB=	yes
USE_PYQT=	pyqt5 sip
USE_PYTHON=	distutils concurrent autoplist pytest
USE_QT=		core gui xml widgets qmake:build

SHEBANG_FILES=	tests/runselftest.py examples/embedexample.py

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	# strip
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/veusz/helpers/*.so

do-test:
	@cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} ./runselftest.py

.include <bsd.port.mk>
