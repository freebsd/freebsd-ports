# $FreeBSD$

PORTNAME=	pyvex
PORTVERSION=	8.20.1.7
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Python interface to libVEX and VEX IR

LICENSE=	BSD2CLAUSE GPLv2+ GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2+ =	${WRKSRC}/vex/LICENSE.GPL
LICENSE_FILE_GPLv3=	${WRKSRC}/pyvex_c/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv7 i386
ONLY_FOR_ARCHS_REASON=	pyvex_c/pyvex.c does not support this architecture (see line 170)

BUILD_DEPENDS=	${_MY_DEPENDS}
RUN_DEPENDS=	${_MY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}archinfo>0:devel/py-archinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycparser>0:devel/py-pycparser@${PY_FLAVOR}

USES=		gmake localbase python:3.5+
USE_CSTD=	c99
USE_PYTHON=	autoplist distutils

MAKE_ENV=	EXTRA_CFLAGS="${CFLAGS}"

_MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.3:devel/py-cffi@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}|g' \
		-e 's|%%LDFLAGS%%|${LDFLAGS}|g' \
		${WRKSRC}/pyvex_c/Makefile
	@${REINPLACE_CMD} -e 's|%%MAKE_JOBS_NUMBER%%|${MAKE_JOBS_NUMBER}|g' \
		${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
