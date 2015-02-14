# Created by: Moggie <moggie@elasticmind.net>
# $FreeBSD$

PORTNAME=	wtforms
PORTVERSION=	2.0.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WTForms-${DISTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Flexible forms validation and rendering library for python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>0:${PORTSDIR}/devel/py-babel
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:${PORTSDIR}/devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-devel>0:${PORTSDIR}/databases/py-sqlalchemy-devel \
		${PYTHON_PKGNAMEPREFIX}pep8>0:${PORTSDIR}/devel/pep8 \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil

OPTIONS_DEFINE=		TESTS
TESTS_DESC=		Install test suite dependencies
TESTS_BUILD_DEPENDS=	${TEST_DEPENDS}

USES=		python zip
USE_PYTHON=	autoplist distutils

PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _static/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.html ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.js ${STAGEDIR}${DOCSDIR}/)

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
