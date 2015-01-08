# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-mezzanine
PORTVERSION=	1.4.7
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mezzanine-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Content management platform built using the Django framework

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.4:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}south>=0.7.3:${PORTSDIR}/databases/py-south \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.3.1:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}bleach>0:${PORTSDIR}/www/py-bleach \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}django-mezzanine-filebrowser>=0.2.27:${PORTSDIR}/www/py-django-mezzanine-filebrowser \
		${PYTHON_PKGNAMEPREFIX}django-mezzanine-grappelli>=0.2.21:${PORTSDIR}/www/py-django-mezzanine-grappelli

USES=		gettext python:2
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
