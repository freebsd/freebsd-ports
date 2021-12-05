# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>

PORTNAME=	textile
PORTVERSION=	4.0.2
CATEGORIES=	www textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Textile markup generator written in Python

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=2.8:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	python-${PORTNAME}

.include <bsd.port.mk>
