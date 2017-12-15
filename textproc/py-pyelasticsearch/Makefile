# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyelasticsearch
PORTVERSION=	1.4
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Flexible, high-scale API to elasticsearch

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch-py>=1.3.0:textproc/py-elasticsearch-py@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=3.0:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.8:net/py-urllib3@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
