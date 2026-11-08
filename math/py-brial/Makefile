PORTNAME=	brial
PORTVERSION=	1.2.12
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Python implementation of BRiAl
WWW=		https://github.com/BRiAl/BRiAl

LICENSE=	GPLv2

DEPRECATED=	Requires SageMath, which is not in ports
BROKEN=		requires SageMath, which is not in the ports tree

LIB_DEPENDS=	libbrial.so:math/brial

USES=		python

USE_GITHUB=	yes
GH_ACCOUNT=	BRiAl
GH_PROJECT=	${GH_ACCOUNT}

USE_PYTHON=	distutils

NO_ARCH=	yes
WRKSRC_SUBDIR=	sage-brial

.include <bsd.port.mk>
