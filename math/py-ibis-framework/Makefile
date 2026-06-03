PORTNAME=	ibis-framework
PORTVERSION=	12.0.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ibis_framework-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Portable Python dataframe library
WWW=		https://ibis-project.org/ \
		https://github.com/ibis-project/ibis

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atpublic>=2.3:devel/py-atpublic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parsy>=2:devel/py-parsy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.2:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlglot>=23.4:databases/py-sqlglot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>=0.11:devel/py-toolz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2022.7:devel/py-tzdata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
