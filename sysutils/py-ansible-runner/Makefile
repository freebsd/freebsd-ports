PORTNAME=	ansible-runner
DISTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Extensible embeddable ansible job runner
WWW=		https://ansible-runner.readthedocs.io/

LICENSE=	APACHE20

BROKEN_armv6=	fails to build: Child process terminated abnormally: Segmentation fault
BROKEN_armv7=	fails to build: Child process terminated abnormally: Segmentation fault

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible>2.0:sysutils/ansible@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemon>0:devel/py-daemon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>4.5:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>5.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent distutils

CPE_VENDOR=	redhat

NO_ARCH=	yes

.include <bsd.port.mk>
