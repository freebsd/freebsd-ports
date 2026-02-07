PORTNAME=	cirq-web
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cirq module to visualize quantum circuits in 3D in a web browser
WWW=		https://github.com/quantumlib/cirq

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib
GH_PROJECT=	Cirq

WRKSRC_SUBDIR=	cirq-web

NO_ARCH=	yes

.include <bsd.port.mk>
