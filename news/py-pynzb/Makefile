# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pynzb
PORTVERSION=	0.1.0
PORTREVISION=	2
CATEGORIES=	news python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unified API for parsing NZB files

LICENSE=	BSD3CLAUSE

USES=		python
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	LXML
LXML_DESC=	Add support for py-lxml
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.2.1:devel/py-lxml

.include <bsd.port.mk>
