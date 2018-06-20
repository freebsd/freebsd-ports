# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Flask-APScheduler
PORTVERSION=	1.7.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	APScheduler support for Flask

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}apscheduler>=3.2.0:devel/py-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.4.2:devel/py-dateutil@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
