# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	html2text
PORTVERSION=	2020.1.16
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Convert HTML into clean plain ASCII text

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

CONFLICTS_INSTALL=	html2text py*-html2text2018 # bin/html2text

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest --cov=html2text

.include <bsd.port.mk>
