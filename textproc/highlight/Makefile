PORTNAME=	highlight
DISTVERSION=	4.16
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	textproc
MASTER_SITES=	http://andre-simon.de/zip/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Customizable syntax highlighter
WWW=		http://andre-simon.de/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/scoped_array.hpp:devel/boost-libs

USES=		gmake lua pkgconfig tar:bzip2
MAKEFILE=	makefile
MAKE_ARGS=	CXX="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -DHAVE_DECL_GETOPT" \
		LDFLAGS="${LDFLAGS}"
ALL_TARGET=	all # cli
INSTALL_TARGET=	install

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_SUB=	yes

GUI_USES=	gl qt:6,qmake
GUI_USE=	GL=opengl QT=tools:build,base
GUI_MAKE_ENV=	QMAKE="${QMAKE}"
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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/highlight*

.include <bsd.port.mk>
