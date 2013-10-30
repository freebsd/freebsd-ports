# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	pydap
PORTVERSION=	3.1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pydap-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Implementation of the Opendap/DODS protocol

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distribute>=0:${PORTSDIR}/devel/py-distribute \
		paver:${PORTSDIR}/devel/py-paver

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	Pydap

.include <bsd.port.mk>
