# Created by: Moggie <moggie@elasticmind.net>
# $FreeBSD$

PORTNAME=	werkzeug
PORTVERSION=	0.11.15
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Werkzeug-${DISTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python utilities collection for building WSGI applications

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=16.0:security/py-openssl

OPTIONS_DEFINE=	EXAMPLES WATCHDOG
WATCHDOG_DESC=	Monitor filesystem events
WATCHDOG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}watchdog>=0.8:devel/py-watchdog

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
