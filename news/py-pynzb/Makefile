# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pynzb
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	news python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A unified API for parsing NZB files

LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	LXML
LXML_DESC=	Add support for py-lxml
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.2.1:${PORTSDIR}/devel/py-lxml

.include <bsd.port.mk>
