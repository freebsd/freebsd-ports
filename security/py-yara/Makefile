# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	3.11.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python bindings for yara

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libyara.so:security/yara

USE_GITHUB=	yes
GH_ACCOUNT=	VirusTotal
GH_PROJECT=	yara-python

USES=		localbase python
USE_PYTHON=	distutils autoplist
PYDISTUTILS_BUILDARGS=	--dynamic-linking

DO_MAKE_TEST=	${SETENV} ${TEST_ENV} ${PYTHON_CMD} tests.py
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_TARGET=	# empty

.include <bsd.port.mk>
