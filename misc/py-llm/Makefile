PORTNAME=	llm
DISTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Interact with Large Language Models by API, or locally
WWW=		https://llm.datasette.io/ \
		https://github.com/simonw/llm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click-default-group>=1.2.3:devel/py-click-default-group@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}condense-json>0:devel/py-condense-json@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=1.0.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=1.0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}puremagic>0:sysutils/py-puremagic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ulid2>=1<3:textproc/py-python-ulid2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite-migrate>0:databases/py-sqlite-migrate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>=0:devel/py-types-pyyaml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
