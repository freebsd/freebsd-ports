PORTNAME=	claude-agent-sdk
DISTVERSION=	0.2.173
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	claude_agent_sdk-${DISTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Python SDK for building agents on top of Claude Code
WWW=		https://github.com/anthropics/claude-agent-sdk-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	depends on misc/claude-code

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	claude:misc/claude-code \
		${PYTHON_PKGNAMEPREFIX}anyio>=4.0.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.20.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>=1.23.0<3.0.0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=1.0.0:devel/py-sniffio@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

post-patch:
	@${RM} ${WRKSRC}/src/claude_agent_sdk/_bundled/.gitignore

.include <bsd.port.mk>
