PORTNAME=	ansible-runner
DISTVERSION=	1.4.7
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Extensible embeddable ansible job runner

LICENSE=	APACHE20

BROKEN_armv6=	fails to build: Child process terminated abnormally: Segmentation fault
BROKEN_armv7=	fails to build: Child process terminated abnormally: Segmentation fault

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansible>2.0:sysutils/ansible@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemon>0:devel/py-daemon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>4.5:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>5.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		cpe python:3.6+
USE_PYTHON=	distutils autoplist concurrent

CPE_VENDOR=	redhat

NO_ARCH=	yes

.include <bsd.port.mk>
