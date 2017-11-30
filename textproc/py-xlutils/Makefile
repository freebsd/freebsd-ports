# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlutils
PORTVERSION=	1.7.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Utilities for working with Excel files that require both xlrd and xlwt

LICENSE=	MIT

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}xlrd>=0.7.2:textproc/py-xlrd@${FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}xlwt>=0.7.4:textproc/py-xlwt@${FLAVOR}
RUN_DEPENDS:=   ${BUILD_DEPENDS}

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
