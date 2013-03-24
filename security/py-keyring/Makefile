# Created by: Douglas Thrift <douglas@douglasthrift.net>
# $FreeBSD$

PORTNAME=	keyring
PORTVERSION=	1.2
PORTREVISION=	1
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

OPTIONS_DEFINE=		CRYPT_FILE GNOME_KEYRING KDE_KWALLET
GNOME_KEYRING_DESC=	GNOME Keyring backend
KDE_KWALLET_DESC=	KDE KWallet backend
CRYPT_FILE_DESC=	Crypt(ed) File backend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCRYPT_FILE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycrypto>=2.5:${PORTSDIR}/security/py-pycrypto
.endif

.if ${PORT_OPTIONS:MGNOME_KEYRING}
USE_GNOME+=	pygnomedesktop
.endif

.if ${PORT_OPTIONS:MKDE_KWALLET}
USE_KDE4+=	pykde4
.endif

.include <bsd.port.mk>
