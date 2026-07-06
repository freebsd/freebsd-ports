PORTNAME=	tritonclient
DISTVERSION=	2.70.0
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI}
MASTER_SITE_SUBDIR=	a2/2f/079ce9218627c66b2a704ff37c25c72504cabbd3e2dad65b2235dae636d1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${DISTVERSION}-py3-none-any
EXTRACT_SUFX=	.whl # this package doesn't distribute source tarballs, only wheels, and the upstream repo is not tagged with releases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python client library and utilities for Triton Inference Server
WWW=		https://github.com/triton-inference-server/client

LICENSE=	BSD3CLAUSE

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.1:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}geventhttpclient>=2.3.3:devel/py-geventhttpclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ml-dtypes>0:math/py-ml-dtypes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.19.1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-rapidjson>=0.9.1:devel/py-python-rapidjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.0.7:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist flavors

NO_ARCH=	yes

EXTRACT_CMD=		${UNZIP_CMD}
EXTRACT_BEFORE_ARGS=	-qo
EXTRACT_AFTER_ARGS=	-d ${WRKDIR}
WRKSRC=			${WRKDIR}

PEP517_BUILD_DEPEND=	# wheel-only, no build from source
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-build:
	@${DO_NADA}

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/LICENSE.txt

POST_PLIST=	fix-plist

fix-plist:
	@${REINPLACE_CMD} -e '/site-\.\.LICENSE\.txt/d' ${TMPPLIST}

.include <bsd.port.mk>
