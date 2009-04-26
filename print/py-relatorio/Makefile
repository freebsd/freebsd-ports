# New ports collection makefile for:	py-relatorio
# Date created:		23 April,2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	relatorio
PORTVERSION=	0.5.1
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A templating library able to output odt and pdf files

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.5:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.2:${PORTSDIR}/devel/py-lxml

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
