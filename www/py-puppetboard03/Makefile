# $FreeBSD$

PORTNAME=	puppetboard
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	03

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Web interface to PuppetDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Use www/py-puppetboard instead
EXPIRATION_DATE=2020-04-01

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}CommonMark>=0.7.2:textproc/py-CommonMark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.12:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0.14.2:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.19:textproc/py-MarkupSafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypuppetdb03>=0.3.3:databases/py-pypuppetdb03@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13.0:www/py-requests@${PY_FLAVOR}

USES=		python:2.7
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=puppetboard-* puppetboard02-*

GH_ACCOUNT=	voxpupuli
PLIST_FILES=	"@sample etc/puppetboard/default_settings.py.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppetboard
	${CP} ${WRKSRC}/puppetboard/default_settings.py ${STAGEDIR}${PREFIX}/etc/puppetboard/default_settings.py.sample

.include <bsd.port.mk>
