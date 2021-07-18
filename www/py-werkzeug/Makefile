# Created by: Moggie <moggie@elasticmind.net>

PORTNAME=	werkzeug
PORTVERSION=	2.0.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Werkzeug-${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python utilities collection for building WSGI applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}openssl>=16.0:security/py-openssl@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES WATCHDOG
WATCHDOG_DESC=	Monitor filesystem events

WATCHDOG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}watchdog>=0:devel/py-watchdog@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dataclasses>=0:devel/py-dataclasses@${PY_FLAVOR}
.endif

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
