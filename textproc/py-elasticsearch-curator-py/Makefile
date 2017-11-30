# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=		curator
PORTVERSION=		3.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=		textproc python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}elasticsearch-
PKGNAMESUFFIX=		-py

MAINTAINER=		dvl@FreeBSD.org
COMMENT=		Python index manager for Elasticsearch

LICENSE=		APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.8.3:net/py-urllib3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch-py>=1.8.0:textproc/py-elasticsearch-py@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=3.3:devel/py-click@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	elastic
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
