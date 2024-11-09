PORTNAME=	pywebview
DISTVERSION=	5.3.2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-qt

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Build GUI for your Python program with JavaScript, HTML, and CSS (qt)
WWW=		https://github.com/r0x0r/pywebview

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottle>=0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proxy_tools>=0:www/py-proxy_tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyside2>=0:devel/pyside2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=0:devel/py-QtPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		pyqt:5 python
USE_PYQT=	webengine:run
USE_PYTHON=	autoplist cryptography pep517

CONFLICTS_INSTALL=	www/py-${PORTNAME}-gtk

NO_ARCH=	yes

.include <bsd.port.mk>
