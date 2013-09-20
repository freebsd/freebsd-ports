# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyring
PORTVERSION=	1.6.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Store and access your passwords safely

LICENSE=	PSFL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:${PORTSDIR}/devel/py-pytest-runner

LATEST_LINK=	py-${PORTNAME}

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

OPTIONS_DEFINE=		CRYPT_FILE GNOME_KEYRING KDE_KWALLET KEYCZAR PYFS \
			SECRET_SERVICE
CRYPT_FILE_DESC=	Install pycrpto to support the Crypt(ed) File backend
GNOME_KEYRING_DESC=	Install GNOME Keyring to support the Gnome backend
KDE_KWALLET_DESC=	Install KDE KWallet to support the kwallet backend
KEYCZAR_DESC=		Install keyczar to support keyring encryption
PYFS_DESC=		Install pyfilesystem to support the pyfs backend
SECRET_SERVICE_DESC=	Install SecretStorage to support the SecretService backend

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRYPT_FILE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.5:${PORTSDIR}/security/py-pycrypto
.endif

.if ${PORT_OPTIONS:MGNOME_KEYRING}
USE_GNOME+=	pygobject3
.endif

.if ${PORT_OPTIONS:MKDE_KWALLET}
USE_KDE4+=	pykde4
.endif

.if ${PORT_OPTIONS:MKEYCZAR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}keyczar>=0.71c:${PORTSDIR}/security/py-keyczar
.endif

.if ${PORT_OPTIONS:MPYFS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fs>=0.4.0:${PORTSDIR}/devel/py-fs
.endif

.if ${PORT_OPTIONS:MSECRET_SERVICE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}SecretStorage>=1.0.0:${PORTSDIR}/security/py-SecretStorage
.endif

.include <bsd.port.mk>
