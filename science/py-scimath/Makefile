# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	scimath
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	science math python
MASTER_SITES=	http://www.enthought.com/repo/ets/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Scientific and Mathematical calculations

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traits>=3.6.0:${PORTSDIR}/devel/py-traits
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		yes
PYEASYINSTALL_ARCHDEP=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
