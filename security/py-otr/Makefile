# $FreeBSD$

PORTNAME=	otr
PORTVERSION=	0.2.1.1
PORTREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	http://python-otr.pentabarf.de/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-otr-${PORTVERSION}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Python bindings for libotr

DEPRECATED=	Abandoned upstream
EXPIRATION_DATE=2014-09-30
BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
# This should be updated to the newer version of libotr
LIB_DEPENDS=	libotr.so.2:${PORTSDIR}/security/libotr3

USES=		pkgconfig
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

.include <bsd.port.mk>
