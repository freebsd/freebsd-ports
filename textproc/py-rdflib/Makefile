# ex:ts=8
# Ports collection makefile for:	py-rdflib
# Date created:			Aug 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rdflib
PORTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	A Python library for RDF manipulation

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isodate>=0:${PORTSDIR}/devel/py-isodate

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|distutils.core|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
