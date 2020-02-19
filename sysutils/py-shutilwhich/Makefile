# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shutilwhich
PORTVERSION=	1.1.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	shutil.which for those not using Python 3.3

LICENSE=	PSFL

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:2.7
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	mbr

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs

.include <bsd.port.mk>
