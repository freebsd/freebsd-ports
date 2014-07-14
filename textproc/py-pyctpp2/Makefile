# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyctpp2
PORTVERSION=	0.12.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Python interface to CTPP2 library

LICENSE=	MIT

LIB_DEPENDS=	libctpp2.so:${PORTSDIR}/textproc/ctpp2

# Python3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
