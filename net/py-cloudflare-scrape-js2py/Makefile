PORTNAME=	cloudflare-scrape-js2py
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.3
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Python module to bypass Cloudflare's anti-bot page using js2py #'

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>2.4.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Js2Py>=0:devel/py-Js2Py@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	VeNoMouS

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}cloudflare-scrape-1.*

.include <bsd.port.mk>
