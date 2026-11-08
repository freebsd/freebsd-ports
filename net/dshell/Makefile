PORTNAME=	dshell
PORTVERSION=	3.2.3
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Extensible network forensic analysis framework
WWW=		https://github.com/USArmyResearchLab/Dshell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elasticsearch>0:textproc/py-elasticsearch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GeoIP2>0:net/py-GeoIP2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pcapy-ng>0:net/py-pcapy-ng@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypacker>0:net/py-pypacker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR} \
		bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PY_SETUPTOOLS}

USES=		python
USE_GITHUB=	yes

GH_ACCOUNT=	USArmyResearchLab
GH_PROJECT=	Dshell
USE_PYTHON=	autoplist concurrent pep517
NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
			 -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/scripts/dshell
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/dshell/data/dshellrc

.include <bsd.port.mk>
