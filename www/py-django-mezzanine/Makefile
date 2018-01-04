# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-mezzanine
PORTVERSION=	4.2.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mezzanine-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Content management platform built using the Django framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django18>=1.8:www/py-django18@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-contrib-comments>0:www/py-django-contrib-comments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-mezzanine-filebrowser>=0.4.6:www/py-django-mezzanine-filebrowser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-mezzanine-grappelli>=0.4.5:www/py-django-mezzanine-grappelli@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.0:devel/py-tzlocal@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=1.4:www/py-bleach@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.1.3:www/py-beautifulsoup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.1.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.4:www/py-requests-oauthlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.9.0:devel/py-future@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>0:textproc/py-chardet@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pep8>=1.4.1:devel/pep8 \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0.6.1:devel/py-pyflakes@${FLAVOR}

USES=		gettext python
USE_PYTHON=	autoplist concurrent distutils

do-test:
	@cd ${WRKSRC} && ${SETENV} TZ=UTC LC_ALL=en_US.UTF-8 ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
