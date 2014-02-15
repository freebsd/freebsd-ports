# Created by: ijliao
# $FreeBSD$

PORTNAME=	rdflib
PORTVERSION=	4.1.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for RDF manipulation

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0:${PORTSDIR}/devel/py-isodate \
	${PYTHON_PKGNAMEPREFIX}parsing>=2.0.1:${PORTSDIR}/devel/py-parsing \
	${PYTHON_PKGNAMEPREFIX}sparqlwrapper>=1.5.2:${PORTSDIR}/textproc/py-sparqlwrapper

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
