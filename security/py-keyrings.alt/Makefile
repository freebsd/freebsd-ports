# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyrings.alt
PORTVERSION=	2.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Alternate Python keyring implementations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		ENCRYPTED_FILE GNOME_KEYRING KEYCZAR PYFS
ENCRYPTED_FILE_DESC=	Install pycrypto to support the Encrypted File backend
GNOME_KEYRING_DESC=	Install GNOME Keyring to support the Gnome backend
KEYCZAR_DESC=		Install keyczar to support keyring encryption
PYFS_DESC=		Install pyfilesystem to support the pyfs backend

ENCRYPTED_FILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.5:security/py-pycrypto
GNOME_KEYRING_USE=		GNOME=pygobject3
KEYCZAR_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}keyczar>=0.71c:security/py-keyczar
PYFS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}fs>=0.5:devel/py-fs

.include <bsd.port.mk>
