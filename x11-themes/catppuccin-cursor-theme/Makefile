PORTNAME=	catppuccin-cursor-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	x11-themes

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Soothing pastel cursors for GTK/Plasma/Hyprland
WWW=		https://github.com/catppuccin/cursors

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	zip:archivers/zip \
		just:deskutils/just \
		whiskers:devel/catppuccin-whiskers \
		${PYTHON_PKGNAMEPREFIX}pyside6>0:devel/pyside6@${PY_FLAVOR} \
		inkscape:graphics/inkscape \
		bash:shells/bash \
		xcursorgen:x11/xcursorgen

USES=		python:build shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	catppuccin
GH_PROJECT=	cursors

SHEBANG_FILES=	build \
		scripts/build-cursors \
		scripts/generate-metadata

MAKE_ENV=	FONTCONFIG_FILE=${WRKDIR}/fonts.conf

NO_ARCH=	yes

PORTDOCS=	AUTHORS CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS

_FLAVORS=	Latte Frappe Macchiato Mocha
_ACCENTS=	Blue Dark Flamingo Green Lavender Light Maroon Mauve Peach Pink \
		Red Rosewater Sapphire Sky Teal Yellow

post-extract:
	@${CP} ${FILESDIR}/fonts.conf ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKDIR}/fonts.conf

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} just all

do-install:
	cd ${WRKSRC}/dist && \
	${COPYTREE_SHARE} "*" ${STAGEDIR}${PREFIX}/share/icons
.for flavor in ${_FLAVORS}
.   for accent in ${_ACCENTS}
	@cd ${STAGEDIR}${PREFIX}/share/icons && \
	${MV} catppuccin-${flavor:tl}-${accent:tl}-cursors \
		Catppuccin-${flavor}-${accent}
.   endfor
.endfor
	@${FIND} ${STAGEDIR}${PREFIX}/share/icons \
		-type f \( -name AUTHORS -o -name LICENSE \) -delete

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
