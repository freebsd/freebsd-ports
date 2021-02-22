# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	mathicsscript
PORTVERSION=	2.0.1
CATEGORIES=	math python

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Terminal CLI to Mathics

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Mathics>0:math/py-mathics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}columnize>0:devel/py-columnize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}term-background>0:deskutils/py-term-background@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Mathics>0:math/py-mathics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>2.5:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}columnize>0:devel/py-columnize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}term-background>0:deskutils/py-term-background@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	Mathics3

USES=		python:3.6+ readline shebangfix
USE_PYTHON=	distutils
SHEBANG_GLOB=	*.py

MAKE_ENV+=	PYTHON=${PYTHON_CMD}
NO_ARCH=	yes
PLIST_SUB+=	VER=${PORTVERSION}
TEST_TARGET=	check
TEST_ENV=	${MAKE_ENV}

post-stage:
	${RM} -r ${STAGEDIR}/${PYTHON_SITELIBDIR}/test

do-test: install
	(cd ${TEST_WRKSRC} && py.test)

.include <bsd.port.mk>
