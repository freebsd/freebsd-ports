# Created by: Wen Heping
# $FreeBSD$

PORTNAME=	WebTest
PORTVERSION=	2.0.4
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://www.c-s.li/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Helper to test WSGI applications

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webob>=1.2:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}waitress>0:${PORTSDIR}/www/py-waitress
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webob>=1.2:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}waitress>0:${PORTSDIR}/www/py-waitress

USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
