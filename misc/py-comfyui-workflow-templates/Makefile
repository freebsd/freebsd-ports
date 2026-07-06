PORTNAME=	comfyui-workflow-templates
DISTVERSION=	0.11.1
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-core>=0.3.266:misc/py-comfyui-workflow-templates-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-json>=0.1.1:misc/py-comfyui-workflow-templates-json@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-api>=0.3.84:misc/py-comfyui-workflow-templates-media-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-assets-01>0:misc/py-comfyui-workflow-templates-media-assets-01@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-image>=0.3.160:misc/py-comfyui-workflow-templates-media-image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-other>=0.3.229:misc/py-comfyui-workflow-templates-media-other@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}comfyui-workflow-templates-media-video>=0.3.101:misc/py-comfyui-workflow-templates-media-video@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
