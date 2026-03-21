PORTNAME=	comfyui-workflow-templates
DISTVERSION=	0.9.26
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ComfyUI: Workflow templates
WWW=		https://github.com/Comfy-Org/workflow_templates

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-core>=0.3.173:misc/py-comfyui-workflow-templates-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-api>=0.3.64:misc/py-comfyui-workflow-templates-media-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-video>=0.3.62:misc/py-comfyui-workflow-templates-media-video@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-image>=0.3.107:misc/py-comfyui-workflow-templates-media-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-other>=0.3.146:misc/py-comfyui-workflow-templates-media-other@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
