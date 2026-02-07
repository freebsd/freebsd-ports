PORTNAME=	chatblade
DISTVERSION=	0.7.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI Swiss Army Knife for ChatGPT
WWW=		https://github.com/npiv/chatblade

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openai>=1.35.15:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=4.2.2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pylatexenc>=2.10:textproc/py-pylatexenc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.8.0:textproc/py-tiktoken@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
