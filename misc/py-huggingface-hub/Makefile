PORTNAME=	huggingface-hub
DISTVERSION=	0.33.1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Official Python client for the Huggingface Hub
WWW=		https://github.com/huggingface/huggingface_hub

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fsspec>=2023.5.0:filesystems/py-fsspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.42.1:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4.3:devel/py-typing-extensions@${PY_FLAVOR} \
		${RUN_DEPENDS_${ARCH}}
RUN_DEPENDS_amd64=	${PYTHON_PKGNAMEPREFIX}hf-xet>=1.1.2<2.0.0:misc/py-hf-xet@${PY_FLAVOR}
RUN_DEPENDS_aarch4=	${PYTHON_PKGNAMEPREFIX}hf-xet>=1.1.2<2.0.0:misc/py-hf-xet@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
