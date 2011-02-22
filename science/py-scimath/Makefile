# New ports collection makefile for:	py-scimath
# Date created:				Jan 26, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scimath
PORTVERSION=	3.0.7
CATEGORIES=	science math python
MASTER_SITES=	http://www.enthought.com/repo/ets/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SciMath-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Scientific and Mathematical calculations

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=3.6.0:${PORTSDIR}/devel/py-traits
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=		yes
PYEASYINSTALL_ARCHDEP=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	SciMath

.include <bsd.port.mk>
