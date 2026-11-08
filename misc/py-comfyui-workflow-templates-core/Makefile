PORTNAME=	comfyui-workflow-templates-core
DISTVERSION=	0.3.394
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ComfyUI: Core helpers for ComfyUI workflow templates
WWW=		https://github.com/Comfy-Org/workflow_templates

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

# tests as of 0.3.394: not run - the tests require scripts from the upstream repository that are missing from the sdist

.include <bsd.port.mk>
