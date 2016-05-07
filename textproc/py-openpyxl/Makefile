# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openpyxl
PORTVERSION=	2.3.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library to read/write Excel 2007 xlsx/xlsm files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jdcal>=0:devel/py-jdcal \
		${PYTHON_PKGNAMEPREFIX}et_xmlfile>=0:textproc/py-et_xmlfile

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}openpyxl1-[0-9]*

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
