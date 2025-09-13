PORTNAME=	fastapi-sso
DISTVERSION=	0.18.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	FastAPI plugin to enable SSO to most common providers
WWW=		https://tomasvotava.github.io/fastapi-sso/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastapi>=0.80:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=3.1.0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1.8.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.10.1<3:www/py-pyjwt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.2<5:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
