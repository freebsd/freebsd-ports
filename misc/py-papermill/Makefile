PORTNAME=	papermill
DISTVERSION=	2.6.0
PORTREVISION=	2
CATEGORIES=	misc python
#MASTER_SITES=	PYPI using the latest revision
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parameterize, execute, and analyze notebooks
WWW=		https://papermill.readthedocs.io/en/latest/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansicolors>0:textproc/py-ansicolors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}entrypoints>0:devel/py-entrypoints@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbclient>=0.2.0:devel/py-nbclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=5.2.0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=5.0.2:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.32.2:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-datalake-store>=0.0.30:devel/py-azure-datalake-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=12.1.0:devel/py-azure-storage-blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}moto>0:devel/py-moto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbclient>0:devel/py-nbclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-env>0:devel/py-pytest-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	nteract

NO_ARCH=	yes

PORTSCOUT=	limit:^.*[0-9]\.[0-9].*$$ # prevent tags like push

.include <bsd.port.mk>
