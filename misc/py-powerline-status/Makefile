# $FreeBSD$

PORTNAME=	powerline-status
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Statusline plugin for vim, zsh, bash, and more

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/source/license-and-credits.rst

USES=		python:3.6+ shebangfix

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	autoplist distutils

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>=0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

SHEBANG_FILES=	powerline/bindings/awesome/powerline-awesome.py \
		powerline/bindings/bar/powerline-bar.py \
		powerline/bindings/i3/powerline-i3.py \
		powerline/bindings/lemonbar/powerline-lemonbar.py

USE_GITHUB=	yes
GH_ACCOUNT=	powerline
GH_PROJECT=	powerline

PORTDOCS=	*

do-build-DOCS-on:
	@make -C ${WRKSRC}/docs man html

do-install-DOCS-on:
.for file in powerline.1 powerline-daemon.1 powerline-lint.1 powerline-config.1
	${INSTALL_DATA} ${WRKSRC}/docs/_build/man/${file} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	cd ${WRKSRC}/docs/_build/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} '! -name .buildinfo'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/powerline

.include <bsd.port.mk>
