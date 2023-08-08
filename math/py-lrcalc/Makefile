PORTNAME=	lrcalc
PORTVERSION=	2.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python bindings for lrcal
WWW=		http://sites.math.rutgers.edu/~asbuch/lrcalc/

LICENSE=	GPLv3

LIB_DEPENDS=	liblrcalc.so:math/lrcalc

USES=		localbase python

USE_PYTHON=	cython distutils

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/lrcalc%%PYTHON_EXT_SUFFIX%%.so

.include <bsd.port.mk>
