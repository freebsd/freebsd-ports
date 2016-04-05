# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	sparqlwrapper
PORTVERSION=	1.7.6
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SPARQLWrapper-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	SPARQL endpoint interface to Python

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} '/keepalive/d' ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
