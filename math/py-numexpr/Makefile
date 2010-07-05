# New ports collection makefile for:	numexpr
# Date created:				05 July 2010
# Whom:					Ju Pengfei <ju.pengfei@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	numexpr
PORTVERSION=	1.3.1
CATEGORIES=	math python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jupengfei@gmail.com
COMMENT=	Fast numerical array expression evaluator for Python and NumPy

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
