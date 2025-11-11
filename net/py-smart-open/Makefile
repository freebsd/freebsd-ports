PORTNAME=	smart-open
PORTVERSION=	7.1.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	smart_open-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utils for streaming large files
WWW=		https://github.com/piskvorky/smart_open

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wrapt>=0:devel/py-wrapt@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awscli>=0:devel/py-awscli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-common>=0:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-core>=0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=0:devel/py-azure-storage-blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>=0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=2.6.0:www/py-google-cloud-storage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=0,1:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>=0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0:archivers/py-zstandard@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	AZURE HTTP GCS S3 SSH WEBHDFS ZST
OPTIONS_DEFAULT=AZURE HTTP GCS S3 SSH WEBHDFS ZST
AZURE_DESC=	Microsoft Azure support
HTTP_DESC=	HTTP support
GCS_DESC=	Google Cloud Storage (GCS) support
S3_DESC=	Amazon Web Services S3 support
WEBHDFS_DESC=	WebHDFS support
ZST_DESC=	Zstandard support

AZURE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-common>=0:www/py-azure-common@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}azure-core>=0:devel/py-azure-core@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=0:devel/py-azure-storage-blob@${PY_FLAVOR}
HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
GCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=2.6.0:www/py-google-cloud-storage@${PY_FLAVOR}
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>=0:www/py-boto3@${PY_FLAVOR}
SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR}
WEBHDFS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
ZST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zstandard>=0:archivers/py-zstandard@${PY_FLAVOR}

.include <bsd.port.mk>
