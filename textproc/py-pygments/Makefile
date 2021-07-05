# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	pygments
DISTVERSION=	2.9.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pygments-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Syntax highlighter written in Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cpe python:3.6+
USE_PYTHON=	distutils concurrent autoplist

CONFLICTS_INSTALL=	py??-pygments-25

NO_ARCH=	yes

do-test:
	(cd ${TEST_WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=)

.include <bsd.port.mk>
