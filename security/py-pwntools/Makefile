PORTNAME=	pwntools
DISTVERSION=	4.14.1
PORTREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	CTF framework and exploit development library
WWW=		https://github.com/Gallopsled/pwntools

LICENSE=	BSD2CLAUSE GPLv2 MIT
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capstone>=3.0.5rc2:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colored-traceback>0:devel/py-colored-traceback@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=3.0:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=1.0.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=1.15.2:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=6.0.8:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=3.3.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyelftools>=0.2.4:devel/py-pyelftools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.9:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=2.7:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>0:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ropgadget>0:security/py-ropgadget@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rpyc>0:devel/py-RPyC@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>0:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unicorn>=1.0.2rc1:emulators/py-unicorn@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	pwntools_project
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--only-use-pwn-command

.include <bsd.port.post.mk>
