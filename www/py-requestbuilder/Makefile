# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requestbuilder
PORTVERSION=	0.2.1
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Command line-driven HTTP request builder

LICENSE=	ISCL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
