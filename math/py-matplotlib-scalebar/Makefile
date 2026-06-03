PORTNAME=	matplotlib-scalebar
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	matplotlib_scalebar-${PORTVERSION}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Artist for matplotlib to display a scale bar
WWW=		https://github.com/ppinard/matplotlib-scalebar

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.5.0:devel/py-ruff@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruff>=0.5.0:devel/py-ruff@${PY_FLAVOR}

USES=		python
USE_LOCALE=	en_US.UTF-8
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
