# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-requests

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=3.0.2:textproc/py3-chardet \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5:dns/py3-idna \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.21.1:net/py3-urllib3 \
		${PYTHON_PKGNAMEPREFIX}certifi>=2017.4.17:security/py3-certifi
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.1:devel/py3-pytest \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py3-pytest-xdist \
		${PYTHON_PKGNAMEPREFIX}execnet>=1.1:sysutils/py3-execnet \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py3-mock

USES=	python:3.3+

.include "${MASTERDIR}/Makefile"
