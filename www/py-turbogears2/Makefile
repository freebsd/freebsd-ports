# Created by: Wen Heping	<wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	TurboGears2
PORTVERSION=	2.1.5
CATEGORIES=	www python
MASTER_SITES=	http://www.turbogears.org/2.1/downloads/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python-Based Framework for Rapid Web Development

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ToscaWidgets>=0.9.4:devel/py-ToscaWidgets \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.5.1:textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}WebFlash>=0.1a8:www/py-WebFlash \
		${PYTHON_PKGNAMEPREFIX}WebError>=0.10.1:www/py-WebError \
		${PYTHON_PKGNAMEPREFIX}repoze.tm2>=0:devel/py-repoze.tm2 \
		${PYTHON_PKGNAMEPREFIX}TurboJson>=1.3.0:devel/py-turbojson \
		${PYTHON_PKGNAMEPREFIX}repoze.who>=1.0.0:devel/py-repoze.who \
		${PYTHON_PKGNAMEPREFIX}repoze.who-testutil>=1.0.8:devel/py-repoze.who-testutil \
		${PYTHON_PKGNAMEPREFIX}repoze.what>=1.0.8:devel/py-repoze.what \
		${PYTHON_PKGNAMEPREFIX}repoze.what-pylons>=1.0:devel/py-repoze.what-pylons \
		${PYTHON_PKGNAMEPREFIX}repoze.tm2>=1.0:devel/py-repoze.tm2 \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}TurboKid>=1.0.4:devel/py-turbokid \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy07>=0.4:databases/py-sqlalchemy07 \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}Chameleon>=2.0:textproc/py-Chameleon \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}Babel>=0.9.4:devel/py-babel

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
