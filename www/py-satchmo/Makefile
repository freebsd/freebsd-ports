# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	satchmo
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://www.caomhin.org/ports/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@freebsd.org
COMMENT=	Shopping cart application for Django

DEPRECATED=	Project development unmaintained
EXPIRATION_DATE=	2016-04-01

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_hg>=0.4:${PORTSDIR}/devel/py-setuptools_hg
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.2.3:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}reportlab1>=0:${PORTSDIR}/print/py-reportlab1 \
		${PYTHON_PKGNAMEPREFIX}trml2pdf>=0:${PORTSDIR}/print/py-trml2pdf \
		${PYTHON_PKGNAMEPREFIX}django-registration>=0.8:${PORTSDIR}/www/py-django-registration \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}sorl-thumbnail<4:${PORTSDIR}/graphics/py-sorl-thumbnail \
		${PYTHON_PKGNAMEPREFIX}django-caching-app-plugins>=0:${PORTSDIR}/www/py-django-caching-app-plugins \
		${PYTHON_PKGNAMEPREFIX}django-keyedcache>=0:${PORTSDIR}/www/py-django-keyedcache \
		${PYTHON_PKGNAMEPREFIX}django-livesettings>=0:${PORTSDIR}/www/py-django-livesettings \
		${PYTHON_PKGNAMEPREFIX}django-signals-ahoy>=0:${PORTSDIR}/www/py-django-signals-ahoy \
		${PYTHON_PKGNAMEPREFIX}django-threaded-multihost>=0:${PORTSDIR}/www/py-django-threaded-multihost

USES=		gettext python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	SOUTH FEDEX AKISMET
OPTIONS_DEFAULT=FEDEX

SOUTH_DESC=	Use South database migration tool for upgrades
FEDEX_DESC=	Use Fedex web services for shipping
AKISMET_DESC=	Use Akismet for spam filtering on product reviews

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUTH}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}south>=0.7.5:${PORTSDIR}/databases/py-south
.endif

.if ${PORT_OPTIONS:MFEDEX}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fedex>=1.0.13:${PORTSDIR}/www/py-fedex
.endif

.if ${PORT_OPTIONS:MAKISMET}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}akismet>=0.2.0:${PORTSDIR}/devel/py-akismet
.endif

.include <bsd.port.mk>
