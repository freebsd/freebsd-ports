PORTNAME=	wfuzz
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	www security python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Web application fuzzer allowing to find vulnerabilities in them
WWW=		https://wfuzz.readthedocs.io/en/latest \
		https://github.com/xmendez/wfuzz

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

USE_GITHUB=	yes
GH_ACCOUNT=	xmendez

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|3.1.0|${DISTVERSION}|' \
		${WRKSRC}/src/wfuzz/__init__.py

.include <bsd.port.mk>
