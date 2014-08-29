# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpyxl
PORTVERSION=	2.0.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library to read/write Excel 2007 xlsx/xlsm files

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jdcal>=0:${PORTSDIR}/devel/py-jdcal

CONFLICTS_INSTALL=	py*-openpyxl1-[0-9]*

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
