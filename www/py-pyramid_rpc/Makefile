# New ports collection makefile for:	py-pyramid_rpc
# Date created:		2011-08-25
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyramid_rpc
PORTVERSION=	0.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	RPC support for the Pyramid web framework

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyramid>=0:${PORTSDIR}/www/py-pyramid
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
