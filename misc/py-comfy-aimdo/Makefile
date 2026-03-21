PORTNAME=	comfy-aimdo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.12
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ComfyUI: AI Model Dynamic Offloader for PyTorch
WWW=		https://github.com/Comfy-Org/comfy-aimdo

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>=2.8.0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	Comfy-Org

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

.include <bsd.port.mk>
