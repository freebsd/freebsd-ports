# Created by: Ju Pengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	pynn
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyNN-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulator-independent language for building neuronal network models

LICENSE=	CeCILL
LICENSE_NAME=	CeCILL Free Software License Version 2.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	PyNN

.include <bsd.port.mk>
