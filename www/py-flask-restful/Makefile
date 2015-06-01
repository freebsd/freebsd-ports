# $FreeBSD$

PORTNAME=	Flask-RESTful
PORTVERSION=	0.3.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Simple framework for creating REST APIs with Flask

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aniso8601>0:${PORTSDIR}/devel/py-aniso8601 \
		${PYTHON_PKGNAMEPREFIX}Flask>0:${PORTSDIR}/www/py-flask \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
