PORTNAME=	openpaperwork-gtk
DISTVERSION=	2.2.5
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenPaperwork GTK plugins
WWW=		https://openpaper.work/en/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openpaperwork-core>0:misc/py-openpaperwork-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycairo>0:graphics/py-pycairo@${PY_FLAVOR} \
		${PY_PILLOW} \
		pygobject-common>=0:devel/pygobject-common
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ARGS=	--disable-plugin-autoload
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 2.2.5: 23 passed, 2 skipped in 8.71s

.include <bsd.port.mk>
