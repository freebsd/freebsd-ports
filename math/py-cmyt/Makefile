PORTNAME=	cmyt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
CATEGORIES=	math python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of Matplotlib colormaps from the yt project
WWW=		https://yt-project.org \
		https://github.com/yt-project/cmyt

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.8.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.0:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorspacious>=1.1.2:devel/py-colorspacious@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mpl>=0.13:devel/py-pytest-mpl@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	yt-project

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -p pytest_mpl -W ignore::RuntimeWarning # RuntimeWarning: divide by zero in numpy power is turned into an error by upstream pytest config

# tests as of 2.0.4: 37 passed in 0.80s

.include <bsd.port.mk>
