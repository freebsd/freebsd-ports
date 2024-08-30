PORTNAME=	powerline-status
DISTVERSION=	2.8.4
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Statusline plugin for vim, zsh, bash, and more
WWW=		https://github.com/powerline/powerline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/source/license-and-credits.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=3.2.0:sysutils/py-psutil@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	powerline
GH_PROJECT=	powerline
USE_PYTHON=	autoplist distutils

SHEBANG_FILES=	powerline/bindings/awesome/powerline-awesome.py \
		powerline/bindings/bar/powerline-bar.py \
		powerline/bindings/i3/powerline-i3.py \
		powerline/bindings/lemonbar/powerline-lemonbar.py

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

SPHINX_BUILD_CMD=	sphinx-build-${PYTHON_VER}

post-patch:
	@${REINPLACE_CMD} -e 's/%%SPHINXBUILD%%/${SPHINX_BUILD_CMD}/g' ${WRKSRC}/docs/Makefile

do-build-DOCS-on:
	@make -C ${WRKSRC}/docs man html

do-install-DOCS-on:
.for file in powerline.1 powerline-daemon.1 powerline-lint.1 powerline-config.1
	${INSTALL_DATA} ${WRKSRC}/docs/_build/man/${file} ${STAGEDIR}${PREFIX}/share/man/man1
.endfor
	cd ${WRKSRC}/docs/_build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '! -name .buildinfo'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/powerline

.include <bsd.port.mk>
