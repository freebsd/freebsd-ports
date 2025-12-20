PORTNAME=	rendercv
DISTVERSION=	2.5
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Typst-based CV/resume generator
WWW=		https://github.com/rendercv/rendercv \
		https://pypi.org/project/rendercv

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonenumbers>=0:devel/py-phonenumbers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-extra-types>=0:devel/py-pydantic-extra-types@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}email-validator>=0:mail/py-email-validator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=		CLI MARKDOWN WATCHDOG TYPST FONT
OPTIONS_DEFAULT=	CLI MARKDOWN WATCHDOG TYPST FONT

CLI_DESC=		Enable Command-line interface support
MARKDOWN_DESC=		Convert Markdown to HTML
WATCHDOG_DESC=		Monitor files for updates
TYPST_DESC=		Render PDF from Typst source files
FONT_DESC=		Font files for RenderCV

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typer>=0:devel/py-typer@${PY_FLAVOR}
MARKDOWN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=0:textproc/py-markdown@${PY_FLAVOR}
WATCHDOG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}watchdog>=0:devel/py-watchdog@${PY_FLAVOR}
TYPST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typst>=0:textproc/py-typst@${PY_FLAVOR}
FONT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rendercv-fonts>=0:x11-fonts/py-rendercv-fonts@${PY_FLAVOR}

.include <bsd.port.mk>
