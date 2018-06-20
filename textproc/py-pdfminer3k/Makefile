# $FreeBSD$

PORTNAME=	pdfminer3k
PORTVERSION=	1.2.4
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PDF parser and analyzer

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.4:devel/py-ply@${PY_FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	jaepil
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
