# $FreeBSD$

PORTNAME=	nltk
PORTVERSION=	3.2.1
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Natural language toolkit written in python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:x11-toolkits/py-tkinter@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.09:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
