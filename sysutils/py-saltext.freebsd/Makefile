PORTNAME=	saltext.freebsd
DISTVERSION=	0.0.1
DISTNAME=	saltext_freebsd-${DISTVERSION}
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Salt Extension for FreeBSD-specific utilities
WWW=		https://pypi.org/project/saltext.freebsd/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	asomers
GH_PROJECT=	saltext-freebsd
GH_TAGNAME=	948b9b2959d61281515be17f151a17e294ea4dbc

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

MAKE_ENV=       SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

.include <bsd.port.mk>
