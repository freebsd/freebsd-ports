# New ports collection makefile for:	numexpr
# Date created:				05 July 2010
# Whom:					Ju Pengfei <ju.pengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	numexpr
PORTVERSION=	1.4.1
CATEGORIES=	math python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fast numerical array expression evaluator for Python and NumPy

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
