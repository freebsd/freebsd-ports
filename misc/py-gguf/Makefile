PORTNAME=	gguf
DISTVERSION=	0.17.1.${GH_TAGNAME:S/b//} # the base version is in pyproject.toml, updated by post-patch
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # the PYPI version is way behind of llama-cpp
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Read and write ML models in GGUF for GGML
WWW=		https://ggml.ai \
		https://github.com/ggml-org/llama.cpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentencepiece>=0.1.98:textproc/py-sentencepiece@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.27:misc/py-tqdm@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	ggml-org
GH_PROJECT=	llama.cpp
GH_TAGNAME=	b6040

WRKSRC=		${WRKDIR}/${GH_PROJECT}-${GH_TAGNAME}/gguf-py

SHEBANG_GLOB=	*.py

NO_ARCH=	yes

post-patch: # update version to reflect llama-cpp revision, have to use '.' since '-' is interpreted as "post"
	@${REINPLACE_CMD} \
		-e 's/version = "${DISTVERSION:R}"/version = "${DISTVERSION:R}.${GH_TAGNAME:S/b//}"/' \
		${WRKSRC}/pyproject.toml

# tests as of 0.17.1.5895: 5 passed in 2.08s

.include <bsd.port.mk>
