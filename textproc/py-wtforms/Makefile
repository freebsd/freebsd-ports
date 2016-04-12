# Created by: Moggie <moggie@elasticmind.net>
# $FreeBSD$

PORTNAME=	wtforms
PORTVERSION=	2.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WTForms-${DISTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Flexible forms validation and rendering library for python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy08>0:databases/py-sqlalchemy-devel \
		${PYTHON_PKGNAMEPREFIX}pep8>0:devel/pep8 \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil

OPTIONS_DEFINE=		DOCS

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

PORTDOCS=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _static/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.html ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.js ${STAGEDIR}${DOCSDIR}/)

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
