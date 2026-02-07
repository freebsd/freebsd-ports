PORTNAME=	django-storages
DISTVERSION=	1.14.6
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj52-
DISTNAME=	django_storages-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Generic storages for Django
WWW=		https://django-storages.readthedocs.io/en/latest/ \
		https://github.com/jschneier/django-storages

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=3.2:www/py-django52@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

# AZURE option requires newer devel/py-azure-storage-blob (not yet in the ports tree).
OPTIONS_DEFINE=	DROPBOX GOOGLE LIBCLOUD S3 SFTP #AZURE
#AZURE_DESC=	Azure backend
DROPBOX_DESC=	Dropbox backend
GOOGLE_DESC=	Google Cloud Storage backend
LIBCLOUD_DESC=	Apache Libcloud backend
S3_DESC=	Amazon S3 backend
SFTP_DESC=	SFTP backend

#AZURE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-core>=1.13:devel/py-azure-core@${PY_FLAVOR} \
#			${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=12:devel/py-azure-storage-blob@${PY_FLAVOR}
DROPBOX_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dropbox>=7.2.1:www/py-dropbox@${PY_FLAVOR}
GOOGLE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-cloud-storage>=1.27:www/py-google-cloud-storage@${PY_FLAVOR}
LIBCLOUD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcloud>=0:net/py-libcloud@${PY_FLAVOR}
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>=1.4.4:www/py-boto3@${PY_FLAVOR}
SFTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=1.15:security/py-paramiko@${PY_FLAVOR}

.include <bsd.port.mk>
