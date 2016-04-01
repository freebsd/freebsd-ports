# $FreeBSD$

PORTNAME=	puppetboard
PORTVERSION=	0.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	allanjude@FreeBSD.org
COMMENT=	Web interface to PuppetDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Flask>=0.10.1:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}Flask-WTF>=0.9.4:www/py-flask-wtf \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.19:textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}pypuppetdb>=0.1.1:databases/py-pypuppetdb \
		${PYTHON_PKGNAMEPREFIX}requests>=2.2.1:www/py-requests

USE_GITHUB=	yes
GH_ACCOUNT=	puppet-community

USES=		python:2.7
USE_PYTHON=	autoplist distutils

PLIST_FILES=	"@sample etc/puppetboard/default_settings.py.sample"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/puppetboard
	${CP} ${WRKSRC}/puppetboard/default_settings.py ${STAGEDIR}${PREFIX}/etc/puppetboard/default_settings.py.sample

.include <bsd.port.mk>
