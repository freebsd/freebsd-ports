# $FreeBSD$

PORTNAME=	pywatchman
PORTVERSION=	4.9.0
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	linpct@gmail.com
COMMENT=	Watchman client for Python

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

RUN_DEPENDS=	watchman>=4:sysutils/watchman

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_PROJECT=	watchman

BROKEN_mips=	Depends on watchman, which needs c++11-libs
BROKEN_mips64=	Depends on watchman, which needs c++11-libs

WRKSRC_SUBDIR=	python

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" \
		-exec ${STRIP_CMD} {} +

do-test:
	cd ${WRKSRC} ; ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
