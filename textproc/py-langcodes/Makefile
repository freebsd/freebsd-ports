PORTNAME=	langcodes
PORTVERSION=	3.5.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tools for labeling human languages with IETF language tags
WWW=		https://github.com/georgkrause/langcodes

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=60:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DATA
OPTIONS_DEFAULT=DATA
DATA_DESC=	Supplementary data about languages

DATA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}language-data>=1.2:textproc/py-language-data@${PY_FLAVOR}

.include <bsd.port.mk>
