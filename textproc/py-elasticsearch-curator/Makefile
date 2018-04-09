# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=		curator
PORTVERSION=		5.5.1
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=		textproc python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}elasticsearch-

MAINTAINER=		elastic@FreeBSD.org
COMMENT=		Python index manager for Elasticsearch

LICENSE=		APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.8.3:net/py-urllib3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch5>=5.5.2:textproc/py-elasticsearch5@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.1.0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}voluptuous>=0.9.3:devel/py-voluptuous@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2017.4.17:security/py-certifi@${FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	elastic
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
