# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlutils
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Utilities for working with Excel files that require both xlrd and xlwt

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}xlrd>=0.7.2:${PORTSDIR}/textproc/py-xlrd \
				${PYTHON_PKGNAMEPREFIX}xlwt>=0.7.4:${PORTSDIR}/textproc/py-xlwt
RUN_DEPENDS:=   ${BUILD_DEPENDS}

USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
