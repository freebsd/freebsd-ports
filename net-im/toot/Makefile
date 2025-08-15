PORTNAME=	toot
DISTVERSION=	0.50.0
CATEGORIES=	net-im python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Interact with the Mastodon social network from the command line
WWW=		https://github.com/ihabunek/toot \
		https://pypi.org/project/toot

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.5.0<5.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1<9:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.1<3.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.13<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.10.0<1.0:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=0:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.1.7:devel/py-wcwidth@${PY_FLAVOR}
# missing test depends ports are: vermin, types-beautifulsoup4
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.5.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pudb>=2025.1:devel/py-pudb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyright>=0:devel/py-pyright@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twine>=0:devel/py-twine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	flavors pytest

NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

OPTIONS_DEFAULT=	IMAGES RICHTEXT
OPTIONS_GROUP=		SUPPORT
OPTIONS_GROUP_SUPPORT=	IMAGES RICHTEXT

IMAGES_DESC=	Required to display images in the TUI
RICHTEXT_DESC=	Required to display rich text in the TUI

IMAGES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=9.5.0:graphics/py-pillow@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}term-image>=0.7.2:graphics/py-term-image@${PY_FLAVOR}
RICHTEXT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urwidgets>=0.2<0.3:devel/py-urwidgets@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's,{__version__},${DISTVERSION},g' \
		${WRKSRC}/${PORTNAME}/cli/diag.py
	@${REINPLACE_CMD} -e '175s,__version__,"${DISTVERSION}",g' \
		${WRKSRC}/${PORTNAME}/cli/__init__.py

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@(cd ${WRKSRC}/${PORTNAME} && \
		${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/{} \
		\; && \
		${FIND} . -type f -not -name "*.bak" -exec ${INSTALL_DATA} \
		{} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/{} \;)

.include <bsd.port.mk>
