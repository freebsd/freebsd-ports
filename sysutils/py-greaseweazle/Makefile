PORTNAME=	greaseweazle
DISTVERSIONPREFIX=	v
DISTVERSION=	1.23
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Tools for accessing a floppy drive at the raw flux level
WWW=		https://github.com/keirf/greaseweazle

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bitarray>=3:devel/py-bitarray@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crcmod>0:devel/py-crcmod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	keirf
USE_PYTHON=	autoplist concurrent pep517

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${PORTVERSION}

.include <bsd.port.mk>
