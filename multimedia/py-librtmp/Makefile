# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librtmp
PORTVERSION=	0.2.0
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python bindings for librtmp, built with cffi

LICENSE=	BSD

LIB_DEPENDS=	librtmp.so:${PORTSDIR}/multimedia/librtmp
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0:${PORTSDIR}/devel/py-cffi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}singledispatch>=0:${PORTSDIR}/devel/py-singledispatch

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
