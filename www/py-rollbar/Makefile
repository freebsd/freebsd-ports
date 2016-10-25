# $FreeBSD$

PORTNAME=	rollbar
PORTVERSION=	0.13.4
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Easy and powerful exception tracking with Rollbar

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.5.7:devel/py-six

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_PROJECT=	pyrollbar

.include <bsd.port.mk>
