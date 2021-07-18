# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	highlight
PORTVERSION=	4.1
PORTEPOCH=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Customizable syntax highlighter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/scoped_array.hpp:devel/boost-libs

USES=		compiler:c++11-lib gmake lua pkgconfig tar:bzip2
USE_CXXSTD=	c++11
MAKEFILE=	makefile
MAKE_ARGS=	CXX="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -DHAVE_DECL_GETOPT" \
		LDFLAGS="${LDFLAGS}"
ALL_TARGET=	all # cli
INSTALL_TARGET=	install

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_SUB=	yes

GUI_USES=	qt:5
GUI_USE=	QT=buildtools_build,qmake_build,core,gui,widgets
GUI_ALL_TARGET=	gui
GUI_INSTALL_TARGET=	install-gui

post-patch:
	@${REINPLACE_CMD} -e '/PKGCONFIG/s,lua,&-${LUA_VER}, ; \
		/LIBS/s,-llua,&-${LUA_VER},' \
			${WRKSRC}/src/gui-qt/highlight.pro

post-install:
.for cfg in filetypes lsp
	@cd ${STAGEDIR}${ETCDIR} && ${MV} ${cfg}.conf ${cfg}.conf.sample
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/highlight

.include <bsd.port.mk>
