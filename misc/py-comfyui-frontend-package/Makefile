PORTNAME=	comfyui-frontend-package
DISTVERSION=	1.45.20
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ComfyUI: Frontend package
WWW=		https://github.com/Comfy-Org/ComfyUI_frontend

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

MAKE_ENV+=	COMFYUI_FRONTEND_VERSION=${DISTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
