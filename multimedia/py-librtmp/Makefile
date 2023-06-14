PORTNAME=	librtmp
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python bindings for librtmp, built with cffi
WWW=		https://github.com/chrippa/python-librtmp

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	librtmp.so:multimedia/librtmp
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0:devel/py-cffi@${PY_FLAVOR}

USES=		python localbase:ldflags
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/librtmp/_librtmp*.so

.include <bsd.port.mk>
