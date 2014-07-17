# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	CoinMP
PORTVERSION=	1.7.6
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/CoinMP/

MAINTAINER=	cpm@fbsd.es
COMMENT=	Optimization library with support for COIN-OR CLP, CBC, and CGL

LICENSE=	CPL
LICENSE_NAME=	Common Public License, Version 1.0
LICENSE_FILE=	${WRKSRC}/CoinMP/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	clp-[0-9]*

GNU_CONFIGURE=	yes
USES=	libtool pkgconfig tar:tgz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS+=	PKG_CONFIG_PATH=${STAGEDIR}${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=	DEBUG DOCS GLPK

GLPK_DESC=	GNU Linear Programming Kit support

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLPK}
CONFIGURE_ARGS+=	--with-gmpl-incdir=${LOCALBASE}/include	\
		--with-gmpl-lib="-L${LOCALBASE}/lib -lglpk"
LIB_DEPENDS+=	libglpk.so:${PORTSDIR}/math/glpk
.else
CONFIGURE_ARGS+=	--disable-glpk-libcheck
.endif

CXXFLAGS+=	-ffast-math
.if ${PORT_OPTIONS:MDEBUG}
CXXFLAGS+=	-fomit-frame-pointer
.endif

post-patch::
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		-e 's|$$(DESTDIR)$$(addlibsdir)|$$(addlibsdir)|g' \
		-e 's|addlibs_DATA = examples/Makefile examples/example.c||g'

post-install:
	${MV} ${STAGEDIR}${PREFIX}/share/coin/doc ${STAGEDIR}${DOCSDIR}
	${RM} -rf ${STAGEDIR}${PREFIX}/share/coin

check regression-test test: build
	@(cd ${WRKSRC};  ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} test)

.include <bsd.port.mk>
