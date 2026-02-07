PORTNAME=	OpenFermion-Dirac
DISTVERSION=	g20220812
PORTREVISION=	3
CATEGORIES=	science python # chemistry, quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Interface between OpenFermion and Dirac
WWW=		https://github.com/bsenjean/Openfermion-Dirac

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}OpenFermion>0:science/py-OpenFermion@${PY_FLAVOR} \
		dirac-quantum-chemistry-software>0:science/dirac

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	bsenjean
GH_PROJECT=	Openfermion-Dirac
GH_TAGNAME=	2770eb1

NO_ARCH=	yes

.include <bsd.port.mk>
