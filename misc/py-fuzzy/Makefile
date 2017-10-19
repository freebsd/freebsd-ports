# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	Fuzzy
DISTVERSION=	1.2.2
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@rawbw.com
COMMENT=	Fast Python phonetic algorithms

LICENSE=	MIT ART20
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm \
		cython:lang/cython
RUN_DEPENDS=	cython:lang/cython
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest

USES=		python
USE_PYTHON=	autoplist distutils

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
