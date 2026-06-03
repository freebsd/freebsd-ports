PORTNAME=	py-OpenFermion-PySCF
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	science python # chemistry, quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interface between OpenFermion and PySCF
WWW=		https://github.com/quantumlib/OpenFermion-PySCF

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}OpenFermion>0:science/py-OpenFermion@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscf>0:science/py-pyscf@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 2 tests are known to fail, see https://github.com/quantumlib/OpenFermion-PySCF/issues/65

USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib
GH_PROJECT=	OpenFermion-PySCF

NO_ARCH=	yes

.include <bsd.port.mk>
