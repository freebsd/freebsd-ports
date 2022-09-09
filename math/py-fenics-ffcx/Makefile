PORTNAME=	fenics-ffcx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0.post0
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FEniCS Form Compiler for finite element forms
WWW=		https://github.com/FEniCS/ffcx

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	FEniCS
GH_PROJECT=	ffcx

NO_ARCH=	yes

.include <bsd.port.mk>
