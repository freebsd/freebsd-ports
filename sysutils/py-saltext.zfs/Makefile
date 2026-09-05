PORTNAME=	saltext.zfs
DISTVERSION=	1.0.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	saltext_zfs-${DISTVERSION}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Salt Extension for interacting with ZFS
WWW=		https://pypi.org/project/saltext.zfs/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=50.3.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}looseversion>0:devel/py-looseversion@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}salt>=3008.0:sysutils/py-salt@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

.include <bsd.port.mk>
