# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requests-kerberos
PORTVERSION=	0.6.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Kerberos authentication handler for python-requests

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>1.1.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}kerberos>1.1.1:${PORTSDIR}/security/py-kerberos

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
