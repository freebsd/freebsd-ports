PORTNAME=	nicotine-plus
DISTVERSION=	3.2.0
CATEGORIES=	net-p2p python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	menelkir@itroll.org
COMMENT=	Graphical client for the Soulseek file sharing network

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mutagen>=1.42:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gobject3>=3.16:devel/py-gobject3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gdbm>=3.6:databases/py-gdbm@${PY_FLAVOR}

USES=		python:3.6+ gnome gettext-tools
USE_GNOME=	gtk30
USE_PYTHON=	distutils concurrent autoplist

do-test:
		@cd ${WRKSRC} && ${PYTHON_CMD} -v -m unittest

.include <bsd.port.mk>
