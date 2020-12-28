# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aggregate6
PORTVERSION=	1.0.12
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Compress an unsorted list of IPv4 and IPv6 prefixes

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}radix>=0.10.0:net/py-radix@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipaddress>0:net/py-ipaddress@${PY_FLAVOR}
.endif

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} ${PYSETUP} nosetests --with-coverage)

.include <bsd.port.post.mk>
