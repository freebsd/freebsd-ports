PORTNAME=	distro2sbom
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	tuukka.pasanen@ilmi.fi
COMMENT=	Generates SBOM files from system packaging information
WWW=		https://github.com/anthonyharrison/distro2sbom

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lib4sbom>=0.8.4:security/py-lib4sbom@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	anthonyharrison
GH_PROJECT=	distro2SBOM
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
