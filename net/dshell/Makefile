PORTNAME=	dshell
PORTVERSION=	3.2.1.b.${SNAPDATE}
CATEGORIES=	net
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Extensible network forensic analysis framework
WWW=		https://github.com/USArmyResearchLab/Dshell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}tabulate>0:devel/py-tabulate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GeoIP2>0:net/py-GeoIP2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pcapy>0:net/py-pcapy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypacker>0:net/py-pypacker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}elasticsearch>0:textproc/py-elasticsearch@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_ACCOUNT=	USArmyResearchLab
GH_PROJECT=	Dshell
GH_TAGNAME=	db3ba5e
SNAPDATE=	20220317

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

post-patch:
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
			 -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/scripts/dshell
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/dshell/data/dshellrc

.include <bsd.port.mk>
