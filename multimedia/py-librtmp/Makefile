# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librtmp
PORTVERSION=	0.1.2
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
DISTNAME=	python-${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python bindings for librtmp, built with cffi

LICENSE=	BSD

LIB_DEPENDS=	librtmp.so:${PORTSDIR}/multimedia/librtmp
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=0:${PORTSDIR}/devel/py-cffi

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	python-${PORTNAME}
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
