# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyring
PORTVERSION=	3.2.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store and access your passwords safely

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:${PORTSDIR}/devel/py-pytest-runner

LATEST_LINK=	py-${PORTNAME}

USES=		python zip
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=		CRYPT_FILE GNOME_KEYRING KDE_KWALLET KEYCZAR PYFS \
			SECRET_SERVICE
CRYPT_FILE_DESC=	Install pycrpto to support the Crypt(ed) File backend
GNOME_KEYRING_DESC=	Install GNOME Keyring to support the Gnome backend
KDE_KWALLET_DESC=	Install KDE KWallet to support the kwallet backend
KEYCZAR_DESC=		Install keyczar to support keyring encryption
PYFS_DESC=		Install pyfilesystem to support the pyfs backend
SECRET_SERVICE_DESC=	Install SecretStorage to support the SecretService backend
CRYPT_FILE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.5:${PORTSDIR}/security/py-pycrypto
GNOME_KEYRING_USE=	GNOME=pygobject3
KDE_KWALLET_USE=	KDE4=pykde4
KEYCZAR_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyczar>=0.71c:${PORTSDIR}/security/py-keyczar
PYFS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fs>=0.4.0:${PORTSDIR}/devel/py-fs
SECRET_SERVICE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}SecretStorage>=1.0.0:${PORTSDIR}/security/py-SecretStorage

.include <bsd.port.mk>
