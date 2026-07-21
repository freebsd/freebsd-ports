PORTNAME=	litellm
DISTVERSION=	1.92.0
PORTREVISION=	2
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Call all LLM APIs using the OpenAI format
WWW=		https://github.com/BerriAI/litellm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.9.4:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastuuid>=0.14.0<1.0:devel/py-fastuuid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.0<1.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=2.20.0<3.0.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.0.0<2.0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.8.0<1.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=8.0.0<9.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>=0.21.0<1.0:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.0.0<9.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6<4.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.10<4.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10.0<3.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.0.0<5.0:devel/py-jsonschema@${PY_FLAVOR}

USES=		cargo python shebangfix
USE_PYTHON=	autoplist concurrent pep517

SHEBANG_FILES=	litellm/proxy/start.sh
bash_CMD=	${SH}

CARGO_CARGOTOML=${WRKSRC}/litellm-rust/Cargo.toml
CARGO_CARGOLOCK=${WRKSRC}/litellm-rust/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no

MAKE_ENV=	${CARGO_ENV}

BINARY_ALIAS=	python3=${PYTHON_CMD}
REINPLACE_ARGS=	-i ''

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS PROXY
OPTIONS_DEFAULT=PROXY

PROXY_DESC=	Enable LiteLLM proxy server support

PROXY_RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}gunicorn>=23.0.0<27.0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.33.0<1.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}granian>=2.7.4<3.0:www/py-granian@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0.21.0<1.0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.136.3<1.0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=1.0.1<2.0:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backoff>=2.2.1<3.0:devel/py-backoff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.3<7.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=2.7.0<3.0:devel/py-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.11.6<4.0:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}APScheduler>=3.11.2<4.0:devel/py-apscheduler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi-sso>=0.19.0<1.0:www/py-fastapi-sso@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.13.0<3.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.27<1.0:www/py-python-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyNaCl>=1.6.2<2.0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=15.0.1<17.0:devel/py-websockets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto3>=1.43.1<2.0:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-identity>=1.25.2<2.0:devel/py-azure-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-storage-blob>=12.28.0<13.0:devel/py-azure-storage-blob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>=1.26.0<2.0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}litellm-proxy-extras>=0.4.75:misc/py-litellm-proxy-extras@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.9.4<16.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polars>=1.38.1<2.0:misc/py-polars@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soundfile>=0.12.1<1.0:audio/py-SoundFile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.14.1<3.0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}expression>=5.6.0<6.0:devel/py-expression@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.0<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prisma>=0.11.0<1.0:databases/py-prisma@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-identity>=1.25.2<2.0:devel/py-azure-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-keyvault-secrets>=4.10.0<5.0:security/py-azure-keyvault-secrets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-kms>=2.24.2<4.0:security/py-google-cloud-kms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-cloud-iam>=2.19.1<3.0:devel/py-google-cloud-iam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}resend>=2.23.0<3.0:mail/py-resend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redisvl>=0.4.1<1.0:databases/py-redisvl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}email-validator>0:mail/py-email-validator@${PY_FLAVOR}
PROXY_USE=	python=cryptography

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' \
		${WRKSRC}/litellm/proxy/start.sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
