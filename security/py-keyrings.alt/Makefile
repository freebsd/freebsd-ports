# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyrings.alt
PORTVERSION=	1.1.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Alternate Python keyring implementations

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.9:devel/py-setuptools_scm

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		ENCRYPTED_FILE GNOME_KEYRING KDE_KWALLET KEYCZAR PYFS
ENCRYPTED_FILE_DESC=	Install pycrypto to support the Encrypted File backend
GNOME_KEYRING_DESC=	Install GNOME Keyring to support the Gnome backend
KDE_KWALLET_DESC=	Install KDE KWallet to support the kwallet backend
KEYCZAR_DESC=		Install keyczar to support keyring encryption
PYFS_DESC=		Install pyfilesystem to support the pyfs backend

ENCRYPTED_FILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.5:security/py-pycrypto
GNOME_KEYRING_USE=		GNOME=pygobject3
KDE_KWALLET_USE=		KDE4=pykde4
KEYCZAR_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}keyczar>=0.71c:security/py-keyczar
PYFS_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}fs>=0.5:devel/py-fs

.include <bsd.port.mk>
