# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyrings.alt
PORTVERSION=	3.1.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Alternate Python keyring implementations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=10.3.1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fs>=0.5:devel/py-fs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		ENCRYPTED_FILE GNOME_KEYRING KEYCZAR PYFS
ENCRYPTED_FILE_DESC=	Install pycrypto to support the Encrypted File backend
GNOME_KEYRING_DESC=	Install GNOME Keyring to support the Gnome backend
KEYCZAR_DESC=		Install keyczar to support keyring encryption
PYFS_DESC=		Install pyfilesystem to support the pyfs backend

ENCRYPTED_FILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.5:security/py-pycrypto@${PY_FLAVOR}
GNOME_KEYRING_USES=		gnome
GNOME_KEYRING_USE=		GNOME=pygobject3
KEYCZAR_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}keyczar>=0.71c:security/py-keyczar@${PY_FLAVOR}
PYFS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}fs>=0.5:devel/py-fs@${PY_FLAVOR}

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
