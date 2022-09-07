PORTNAME=	werkzeug
PORTVERSION=	2.1.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	21
DISTNAME=	Werkzeug-${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python utilities collection for building WSGI applications
WWW=		https://palletsprojects.com/p/werkzeug/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	palletsprojects

OPTIONS_DEFINE=	EXAMPLES WATCHDOG
WATCHDOG_DESC=	Monitor filesystem events

WATCHDOG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}watchdog>=0:devel/py-watchdog@${PY_FLAVOR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
