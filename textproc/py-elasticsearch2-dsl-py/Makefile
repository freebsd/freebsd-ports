# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	py-elasticsearch2-dsl-py
PORTVERSION=	2.1.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	elasticsearch-dsl-py-${PORTVERSION}
# fetch https://codeload.github.com/elastic/elasticsearch-dsl-py/tar.gz/2.1.0?dummy=/elasticsearch-dsl-py-2.1.0_GH0.tar.gz

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	High level Python client for Elasticsearch

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elasticsearch-py>=1.3.0:textproc/py-elasticsearch-py

USE_GITHUB=	yes
GH_ACCOUNT=	elastic
GH_PROJECT=	elasticsearch-dsl-py

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
