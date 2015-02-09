# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-mezzanine
PORTVERSION=	3.1.10
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mezzanine-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Content management platform built using the Django framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>1.6:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-contrib-comments>0:${PORTSDIR}/www/py-django-contrib-comments \
		${PYTHON_PKGNAMEPREFIX}bleach>=1.4:${PORTSDIR}/www/py-bleach \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.1.3:${PORTSDIR}/www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}chardet>0:${PORTSDIR}/textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}future>=0.9.0:${PORTSDIR}/devel/py-future \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.3.1:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}requests>=2.1.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.4:${PORTSDIR}/www/py-requests-oauthlib \
		${PYTHON_PKGNAMEPREFIX}south>=0.7.3:${PORTSDIR}/databases/py-south \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.0:${PORTSDIR}/devel/py-tzlocal \
		${PYTHON_PKGNAMEPREFIX}django-mezzanine-filebrowser>=0.3.4:${PORTSDIR}/www/py-django-mezzanine-filebrowser \
		${PYTHON_PKGNAMEPREFIX}django-mezzanine-grappelli>=0.3.12:${PORTSDIR}/www/py-django-mezzanine-grappelli

USES=		gettext python
USE_PYTHON=	autoplist distutils

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
