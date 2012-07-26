# New ports collection makefile for:	py-otr
# Date created:				2010-26-03
# Whom:					Frank Steinborn <steinex@nognu.de>
#
# $FreeBSD$

PORTNAME=	otr
PORTVERSION=	0.2.1.1
CATEGORIES=	security python
MASTER_SITES=	http://python-otr.pentabarf.de/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-otr-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of python bindings for libotr

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	otr:${PORTSDIR}/security/libotr

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_PKGCONFIG=	build
PYDISTUTILS_PKGNAME=	python-otr

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

.include <bsd.port.mk>
