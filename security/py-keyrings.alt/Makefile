PORTNAME=	keyrings.alt
PORTVERSION=	4.2.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Alternate Python keyring implementations
WWW=		https://pypi.org/project/keyrings.alt/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.classes>0:devel/py-jaraco.classes@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=10.3.1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>0:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fs>=0.5:devel/py-fs@${PY_FLAVOR}

USES=		python pytest
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		ENCRYPTED_FILE GNOME_KEYRING PYFS
ENCRYPTED_FILE_DESC=	Install pycrypto to support the Encrypted File backend
GNOME_KEYRING_DESC=	Install GNOME Keyring to support the Gnome backend
PYFS_DESC=		Install pyfilesystem to support the pyfs backend

ENCRYPTED_FILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodomex>0:security/py-pycryptodomex@${PY_FLAVOR}
GNOME_KEYRING_USES=		gnome
GNOME_KEYRING_USE=		GNOME=pygobject3
PYFS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}fs>=0.5:devel/py-fs@${PY_FLAVOR}

.include <bsd.port.mk>
