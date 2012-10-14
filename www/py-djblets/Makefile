# $FreeBSD$

PORTNAME=	djblets
PORTVERSION=	0.6.23
CATEGORIES=	www python
MASTER_SITES=	http://downloads.reviewboard.org/releases/Djblets/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Djblets-${PORTVERSION}

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	A collection of useful classes and functions for Django

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.3.3<1.4:${PORTSDIR}/www/py-django13 \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Djblets

.include <bsd.port.mk>
