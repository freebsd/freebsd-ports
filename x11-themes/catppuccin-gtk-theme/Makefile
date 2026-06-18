PORTNAME=	catppuccin-gtk-theme
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	x11-themes

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GTK theme with Catppuccin colour scheme
WWW=		https://github.com/Fausto-Korpsvart/Catppuccin-GTK-Theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed \
		sassc:textproc/sassc \
		gnome-shell:x11/gnome-shell
RUN_DEPENDS=	gnome-themes-extra>0:x11-themes/gnome-themes-extra \
		gtk-murrine-engine>0:x11-themes/gtk-murrine-engine

USES=		shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	Fausto-Korpsvart
GH_PROJECT=	Catppuccin-GTK-Theme

SHEBANG_FILES=	themes/build.sh \
		themes/install.sh

MAKE_ENV=	BATCH_MODE=true

BINARY_ALIAS=	sed=gsed
NO_ARCH=	yes

BUILD_WRKSRC=	${WRKSRC}/themes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

INSTALL_FLAGS=	--dest ${STAGEDIR}${PREFIX}/share/themes \
		--theme all \
		--color light dark \
		--size standard compact \
		--verbose

do-build:
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ./build.sh

do-install:
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ./install.sh ${INSTALL_FLAGS}
.for colorscheme in frappe macchiato black
	cd ${BUILD_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ./install.sh ${INSTALL_FLAGS} --tweaks ${colorscheme}
.endfor
	@cd ${STAGEDIR}${PREFIX} && \
	${FIND} share/themes -type f -o -type l >> ${TMPPLIST}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
