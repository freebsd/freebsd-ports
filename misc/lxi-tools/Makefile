PORTNAME=	lxi-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8
CATEGORIES=	misc

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Collection of tools that enables control of LXI compatible instruments
WWW=		https://lxi-tools.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblxi.so:misc/liblxi

USES=		meson lua:53 pkgconfig readline
USE_GITHUB=	yes

MESON_ARGS=	-Dbashcompletiondir=${PREFIX}/etc/bash_completion.d

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_SUB=	yes

GUI_LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
GUI_USES=	gettext-tools gnome python:build
GUI_USE=	gnome=cairo,gdkpixbuf,glib20,gtk40,gtksourceview5,libadwaita
GUI_MESON_OFF=	-Dgui=false
GUI_BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
