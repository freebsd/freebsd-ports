PORTNAME=	mmtf-python
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MMTF (Macromolecular Transmission Format) Python API
WWW=		https://github.com/rcsb/mmtf-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	rcsb

NO_ARCH=	yes

post-build:
	@${RM} ${STAGEDIR}${PREFIX}/bin/sample

post-plist:
	@${REINPLACE_CMD} -e '|bin/sample|d' ${TMPPLIST}

.include <bsd.port.mk>
