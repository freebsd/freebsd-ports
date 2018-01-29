# $FreeBSD$

PORTNAME=	lxi-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17
CATEGORIES=	misc

MAINTAINER=	dg@syrec.org
COMMENT=	Collection of tools that enables control of LXI compatible instruments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblxi.so:misc/liblxi

USES=		autoreconf libtool localbase pkgconfig readline
USE_GITHUB=	yes
GH_ACCOUNT=	lxi-tools

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
CFLAGS+=	-D_WITH_GETLINE # enable getline(3) prototype

PORTDOCS=	README

PLIST_FILES=	bin/lxi \
		man/man1/lxi.1.gz

OPTIONS_DEFINE=	BASH DOCS GUI

BASH_CONFIGURE_WITH=	bash-completion-dir=${PREFIX}/etc/bash_completion.d
BASH_PLIST_FILES=	${PREFIX}/etc/bash_completion.d/lxi

GUI_CONFIGURE_ENABLE=	lxi-gui
GUI_USE=		qt5=core,gui,charts,widgets,buildtools_build,qmake_build gl=gl
GUI_PLIST_FILES=	bin/lxi-gui

post-install-GUI-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lxi-gui

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
