# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	smart-open
PORTVERSION=	5.1.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	smart_open-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utils for streaming large files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathlib2>=0:devel/py-pathlib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0:devel/py-responses@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AZURE HTTP GCS S3 WEBHDFS
OPTIONS_DEFAULT=AZURE HTTP GCS S3 WEBHDFS
AZURE_DESC=	Microsoft Azure support
HTTP_DESC=	HTTP support
GCS_DESC=	Google Cloud Storage (GCS) support
S3_DESC=	Amazon Web Services S3 support
WEBHDFS_DESC=	WebHDFS support

AZURE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-common>=0:www/py-azure-common@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}azure-core>=0:devel/py-azure-core@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=0:devel/py-azure-storage-blob@${PY_FLAVOR}
HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}
GCS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=0:www/py-google-cloud-storage@${PY_FLAVOR}
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>=0:www/py-boto3@${PY_FLAVOR}
WEBHDFS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
