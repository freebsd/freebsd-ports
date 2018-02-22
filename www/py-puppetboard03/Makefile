# $FreeBSD$

PORTNAME=	puppetboard
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	03

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Web interface to PuppetDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}CommonMark>=0.7.2:textproc/py-CommonMark@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.12:www/py-flask@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0.14.2:www/py-flask-wtf@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.19:textproc/py-MarkupSafe@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypuppetdb03>=0.3.3:databases/py-pypuppetdb03@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13.0:www/py-requests@${FLAVOR}

CONFLICTS_INSTALL=puppetboard-* puppetboard02-*
USE_GITHUB=	yes
GH_ACCOUNT=	voxpupuli

USES=		python:2.7
USE_PYTHON=	autoplist distutils

PLIST_FILES=	"@sample etc/puppetboard/default_settings.py.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppetboard
	${CP} ${WRKSRC}/puppetboard/default_settings.py ${STAGEDIR}${PREFIX}/etc/puppetboard/default_settings.py.sample

.include <bsd.port.mk>
