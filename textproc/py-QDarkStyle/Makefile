# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	QDarkStyle
PORTVERSION=	3.0.2
PORTREVISION=	1
CATEGORIES=	textproc devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Dark stylesheet for Python and Qt applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}helpdev>=0.6.10:devel/py-helpdev@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=1.9:devel/py-QtPy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
