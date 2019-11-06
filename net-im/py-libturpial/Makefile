# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libturpial
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	http://files.turpial.org.ve/sources/stable/ \
	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Twitter API

BROKEN=		unfetchable

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=3.4.0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth>=1.0.1:net/py-oauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.2.0:www/py-requests@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

post-extract:
		${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
