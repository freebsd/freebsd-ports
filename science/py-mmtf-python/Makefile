PORTNAME=	mmtf-python
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MMTF (Macromolecular Transmission Format) Python API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	rcsb
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

post-build:
	@${RM} ${STAGEDIR}${PREFIX}/bin/sample

post-plist:
	@${REINPLACE_CMD} -e '|bin/sample|d' ${TMPPLIST}

.include <bsd.port.mk>
