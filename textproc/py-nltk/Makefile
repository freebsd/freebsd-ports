# $FreeBSD$

PORTNAME=	nltk
DISTVERSION=	3.4.1
PORTEPOCH=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Natural language toolkit written in python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.09:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

py27_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}singledispatch>0:devel/py-singledispatch@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
