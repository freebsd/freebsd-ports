# $FreeBSD$

PORTNAME=	awesome-slugify
PORTVERSION=	1.6.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Flexible slugify function

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}regex>=0:textproc/py-regex@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0.04.14:converters/py-unidecode@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
TEST_TARGET=	do-test
NOSETESTS=	nosetests

do-test:
	${NOSETESTS} ${STAGEDIR}${PYTHON_SITELIBDIR}/slugify

.include <bsd.port.mk>
