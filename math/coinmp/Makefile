# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	CoinMP
PORTVERSION=	1.7.2
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/CoinMP/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimization library with support for COIN-OR CLP, CBC, and CGL

LICENSE=	CPL
LICENSE_NAME=	Common Public License, Version 1.0
LICENSE_FILE=	${WRKSRC}/CoinMP/LICENSE
LICENSE_PERMS=	auto-accept

CONFLICTS=	clp-[0-9]*

USES=	pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GCC=	any
CONFIGURE_ARGS+=	PKG_CONFIG_PATH=${STAGEDIR}${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=	DEBUG DOCS

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGLPK}
BROKEN =	the GLPK option requires math/glpk headers that are not currently installed by that port
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
	@${REINPLACE_CMD} -e \
		's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Clp/Makefile.in ${WRKSRC}/Osi/Makefile.in \
		${WRKSRC}/Cbc/Makefile.in ${WRKSRC}/Cgl/Makefile.in \
		${WRKSRC}/CoinUtils/Makefile.in ${WRKSRC}/CoinMP/Makefile.in \
		${WRKSRC}/Data/Sample/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(addlibsdir)|$$(addlibsdir)|g' \
		${WRKSRC}/CoinMP/Makefile.in

pre-build:
.for dir in Cbc Cgl Clp CoinMP CoinUtils Osi
	${CP} ${LTMAIN} ${WRKSRC}/${dir}
.endfor

post-install:
	${MV} ${STAGEDIR}${PREFIX}/share/coin/doc ${STAGEDIR}${DOCSDIR}
	${RM} -rf ${STAGEDIR}${PREFIX}/share/coin

check regression-test test: build
	@(cd ${WRKSRC};  ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} test)

.include <bsd.port.mk>
