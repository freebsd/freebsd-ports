# Created by: ijliao
# $FreeBSD$

PORTNAME=	rdflib
PORTVERSION=	4.2.1
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python library for RDF manipulation

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0:${PORTSDIR}/devel/py-isodate \
	${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:${PORTSDIR}/devel/py-pyparsing \
	${PYTHON_PKGNAMEPREFIX}sparqlwrapper>=1.5.2:${PORTSDIR}/textproc/py-sparqlwrapper \
	${PYTHON_PKGNAMEPREFIX}html5lib>0:${PORTSDIR}/www/py-html5lib

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
