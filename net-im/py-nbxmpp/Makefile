PORTNAME=	nbxmpp
DISTVERSION=	5.0.2
CATEGORIES=	net-im devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Non-blocking Jabber/XMPP module
WWW=		https://dev.gajim.org/gajim/python-nbxmpp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}precis_i18n>=1.0.0:textproc/py-precis_i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=0:dns/py-idna@${PY_FLAVOR}

USES=		gnome python
USE_GNOME=	pygobject3
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

.include <bsd.port.mk>
