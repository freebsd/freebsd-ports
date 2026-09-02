PORTNAME=	saltext.freebsd
DISTVERSION=	1.0.0
DISTNAME=	saltext_freebsd-${DISTVERSION}
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Salt Extension for FreeBSD-specific utilities
WWW=		https://pypi.org/project/saltext.freebsd/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=50.3.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}looseversion>0:devel/py-looseversion@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}salt>=3008.0:sysutils/py-salt@${PY_FLAVOR}

# XXX Should we add CPE ?
USES=		python:3.10+
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

.include <bsd.port.mk>
