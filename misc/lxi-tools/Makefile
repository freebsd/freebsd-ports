# $FreeBSD$

PORTNAME=	lxi-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18
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
CONFIGURE_ARGS=	--disable-static \
		--with-bash-completion-dir=${PREFIX}/etc/bash_completion.d
CFLAGS+=	-D_WITH_GETLINE # enable getline(3) prototype

PORTDOCS=	README

PLIST_FILES=	bin/lxi \
		etc/bash_completion.d/lxi \
		man/man1/lxi.1.gz

OPTIONS_DEFINE=	DOCS GUI

GUI_USE=		qt5=core,gui,charts,widgets,buildtools_build,qmake_build gl=gl
GUI_CONFIGURE_ENABLE=	lxi-gui
GUI_CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${QT_LIBDIR}"
GUI_VARS=		QT_NONSTANDARD=yes
GUI_PLIST_FILES=	bin/lxi-gui

post-patch:
	${REINPLACE_CMD} -e '/\$$(QTCHOOSER)/s/-qt=5//' \
		${WRKSRC}/src/gui/lxi-gui/Makefile.am

post-install-GUI-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lxi-gui

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
