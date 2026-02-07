PORTNAME=	cmyt
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	math python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of Matplotlib colormaps from the yt project
WWW=		https://yt-project.org \
		https://github.com/yt-project/cmyt

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.2.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=8.4:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorspacious>=1.1.2:devel/py-colorspacious@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	yt-project

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests have errors: pytest.PytestUnknownMarkWarning: Unknown pytest.mark.mpl_image_compare - is this a typo?

.include <bsd.port.mk>
