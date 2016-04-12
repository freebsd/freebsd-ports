# $FreeBSD$

PORTNAME=	pywatchman
PORTVERSION=	1.3.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	linpct@gmail.com
COMMENT=	Watchman client for Python

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	watchman>=4:sysutils/watchman

USES=		python:2
USE_PYTHON=	autoplist distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
