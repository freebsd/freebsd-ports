# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	Mathics_Scanner
PORTVERSION=	1.2.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Tokeniser, char tables, & conversion routines for the Wolfram Language

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ujson>0:devel/py-ujson@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ujson>0:devel/py-ujson@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${PY_FLAVOR}
TEST_DEPENDS=	gmake:devel/gmake	\
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	Mathics3

USES=		python:3.6+ shebangfix
USE_PYTHON=	distutils noflavors

NO_ARCH=	yes
MAKE_ENV+=	PYTHON=${PYTHON_CMD}
PLIST_SUB+=	VER=${PORTVERSION}
TEST_TARGET=	check
TEST_ENV=	${MAKE_ENV}

pre-configure:
	${CP} ${FILESDIR}/named-characters.yml ${WRKSRC}/mathics_scanner/data/

do-test: install
	(cd ${TEST_WRKSRC} &&	\
	${SETENV} ${TEST_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${TEST_TARGET})

.include <bsd.port.mk>
