# $FreeBSD$

PORTNAME=	puppetboard
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Web interface to PuppetDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}CommonMark>=0.7.2:textproc/py-CommonMark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0.12:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0.14.2:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.19:textproc/py-MarkupSafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.16.0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypuppetdb>=0.3.3:databases/py-pypuppetdb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=puppetboard02-* puppetboard03-*

GH_ACCOUNT=	voxpupuli
PLIST_FILES=	"@sample etc/puppetboard/default_settings.py.sample"

post-patch:
	${REINPLACE_CMD} -e '/requirements_for_tests/,+2d' \
		${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppetboard
	${CP} ${WRKSRC}/puppetboard/default_settings.py ${STAGEDIR}${PREFIX}/etc/puppetboard/default_settings.py.sample

.include <bsd.port.mk>
