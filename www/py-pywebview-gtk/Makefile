PORTNAME=	pywebview
DISTVERSION=	5.3.2
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-gtk

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Build GUI for your Python program with JavaScript, HTML, and CSS (gtk)
WWW=		https://github.com/r0x0r/pywebview

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk@40
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bottle>=0:www/py-bottle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}proxy_tools>=0:www/py-proxy_tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		gnome python
USE_GNOME+=	gtk30:run pygobject3:run
USE_PYTHON=	autoplist cryptography pep517

CONFLICTS_INSTALL=	www/py-${PORTNAME}-qt

NO_ARCH=	yes

.include <bsd.port.mk>
