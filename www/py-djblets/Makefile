# $FreeBSD$

PORTNAME=	djblets
PORTVERSION=	0.7.8
CATEGORIES=	www python
MASTER_SITES=	http://downloads.reviewboard.org/releases/Djblets/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Djblets-${PORTVERSION}

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	Collection of useful classes and functions for Django

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.4.2<1.5:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-pipeline>=1.2.16:${PORTSDIR}/www/py-django-pipeline
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.4.2<1.5:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-pipeline>=1.2.16:${PORTSDIR}/www/py-django-pipeline \
		${PYTHON_PKGNAMEPREFIX}feedparser>=5.1.2:${PORTSDIR}/textproc/py-feedparser \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Djblets

.include <bsd.port.mk>
