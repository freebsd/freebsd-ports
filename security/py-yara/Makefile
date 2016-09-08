# $FreeBSD$

PORTNAME=	yara
PORTVERSION=	3.5.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Python bindings for yara

LICENSE=	APACHE20

LIB_DEPENDS=	libyara.so:security/yara

USES=		python
USE_PYTHON=	distutils autoplist
PYDISTUTILS_BUILDARGS=	--dynamic-linking

.include <bsd.port.mk>
