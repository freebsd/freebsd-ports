PORTNAME=	pymediainfo
DISTVERSION=	6.1.0
CATEGORIES=	multimedia devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	m.ne@gmx.net
COMMENT=	Python wrapper for the mediainfo library
WWW=		https://github.com/sbraz/pymediainfo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	mediainfo>0:multimedia/mediainfo

USES=		python
USE_PYTHON=	autoplist pep517 pytest

# Upstream archive contains files with UTF-8 names
EXTRACT_CMD=	${SETENV} LC_ALL=C.UTF-8 ${TAR}

NO_ARCH=	yes

.include <bsd.port.mk>
