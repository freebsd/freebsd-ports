# Created by: Wen Heping
# $FreeBSD$

PORTNAME=	WebTest
PORTVERSION=	2.0.10
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Helper to test WSGI applications

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}waitress>0:${PORTSDIR}/www/py-waitress \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:${PORTSDIR}/www/py-webob
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}waitress>0:${PORTSDIR}/www/py-waitress \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:${PORTSDIR}/www/py-webob

USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
