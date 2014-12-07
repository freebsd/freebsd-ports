# $FreeBSD$

PORTNAME=	nltk
PORTVERSION=	2.0.4
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Natural language toolkit written in python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>=0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.09:${PORTSDIR}/devel/py-yaml

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
