# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libturpial
PORTVERSION=	1.7.0
CATEGORIES=	net-im python
MASTER_SITES=	http://files.turpial.org.ve/sources/stable/ \
	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Twitter API

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=3.4.0:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth>=1.0.1:net/py-oauth@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.2.0:www/py-requests@${FLAVOR}

USES=		python:2
USE_PYTHON=	distutils autoplist

post-extract:
		${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
