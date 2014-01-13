# $FreeBSD$

PORTNAME=	nltk
PORTVERSION=	2.0.4
PORTEPOCH=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Natural language toolkit written in python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.09:${PORTSDIR}/devel/py-yaml

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
