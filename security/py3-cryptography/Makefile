# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-cryptography

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.4.1:devel/py3-cffi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4.1:devel/py3-six \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.8:devel/py3-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.1.0:devel/py3-cffi \
		${PYTHON_PKGNAMEPREFIX}idna>=2.0:dns/py3-idna

USES=		python:3.3+ ssl

.include "${MASTERDIR}/Makefile"
