PORTNAME=	lxi-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	misc

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Collection of tools that enables control of LXI compatible instruments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblxi.so:misc/liblxi

USES=		meson lua:53 pkgconfig readline
USE_GITHUB=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	BASH DOCS GUI
OPTIONS_SUB=	yes

BASH_MESON_ON=	-Dbashcompletiondir=${PREFIX}/etc/bash_completion.d
BASH_MESON_OFF=	-Dbashcompletiondir=no

GUI_USES=	gettext-tools gnome python:3.6+,build
GUI_USE=	gnome=cairo,gdkpixbuf2,glib20,gtk40,gtksourceview5,libadwaita
GUI_MESON_ON=	-Dgui=true
GUI_BINARY_ALIAS=	python3=${PYTHON_CMD}
GUI_PLIST_FILES=	bin/lxi-gui

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
