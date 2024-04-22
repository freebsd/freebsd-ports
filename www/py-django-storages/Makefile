PORTNAME=	django-storages
PORTVERSION=	1.14.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Generic storages for Django
WWW=		https://github.com/jschneier/django-storages

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=3.2:www/py-django32@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

# There is also an Azure backend (via AZURE option), but this requires a newer
# version of py-azure-storage-blob.
OPTIONS_DEFINE=	DROPBOX GOOGLE LIBCLOUD S3 SFTP

DROPBOX_DESC=	Dropbox backend
GOOGLE_DESC=	Google Cloud Storage backend
LIBCLOUD_DESC=	Apache Libcloud backend
S3_DESC=	Amazon S3 backend
SFTP_DESC=	SFTP backend

DROPBOX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dropbox>=7.2.1:www/py-dropbox@${PY_FLAVOR}
GOOGLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=1.27:www/py-google-cloud-storage@${PY_FLAVOR}
LIBCLOUD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcloud>0:net/py-libcloud@${PY_FLAVOR}
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>=1.4.4:www/py-boto3@${PY_FLAVOR}
SFTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.15:security/py-paramiko@${PY_FLAVOR}

.include <bsd.port.mk>
