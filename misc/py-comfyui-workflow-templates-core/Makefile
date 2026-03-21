PORTNAME=	comfyui-workflow-templates-core
DISTVERSION=	0.3.173
CATEGORIES=	misc python
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

.include <bsd.port.mk>
