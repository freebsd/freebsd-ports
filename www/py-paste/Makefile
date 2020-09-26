# Created by: Dryice Liu	<dryice@dryice.name>
# $FreeBSD$

PORTNAME=	Paste
PORTVERSION=	3.4.6
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tools for using a Web Server Gateway Interface stack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/tox -e ${PY_FLAVOR}

.include <bsd.port.mk>
