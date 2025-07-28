PORTNAME=	knowit
DISTVERSION=	0.5.10
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Know better your media files
WWW=		https://github.com/ratoaq2/knowit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}babelfish>0:devel/py-babelfish@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enzyme>0:multimedia/py-enzyme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymediainfo>0:multimedia/py-pymediainfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trakit>0:multimedia/py-trakit@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pint>=0.20.1,<0.25.0:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.28.1:www/py-requests@${PY_FLAVOR} \
		mkvtoolnix>0:multimedia/mkvtoolnix

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
