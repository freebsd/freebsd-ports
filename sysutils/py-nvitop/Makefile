PORTNAME=      nvitop
PORTVERSION=   1.6.2
CATEGORIES=    sysutils python
MASTER_SITES=  PYPI
PKGNAMEPREFIX= ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=    tiga@FreeBSD.org
COMMENT=       Interactive NVIDIA-GPU process viewer
WWW=           https://github.com/XuehaiPan/nvitop

LICENSE=       APACHE20
LICENSE_FILE=  ${WRKSRC}/LICENSE

BUILD_DEPENDS= ${PY_SETUPTOOLS} \
               ${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=   ${PYTHON_PKGNAMEPREFIX}nvidia_ml_py>0:devel/py-nvidia-ml-py@${PY_FLAVOR} \
               ${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=          ncurses python
USE_PYTHON=    autoplist pep517

NO_ARCH=       yes

.include <bsd.port.mk>
