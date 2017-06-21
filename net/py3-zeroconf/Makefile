# Created by: John Hixson <jhixson@gmail.com>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../py-zeroconf

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py3-six \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.5:net/py3-netifaces
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py3-six \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.5:net/py3-netifaces

USES=		python:3.3+

.include "${MASTERDIR}/Makefile"
