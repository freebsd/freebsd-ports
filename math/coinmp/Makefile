# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	CoinMP
PORTVERSION=	1.8.4
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/CoinMP/

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Optimization library with support for COIN-OR CLP, CBC, and CGL

LICENSE=	CPL
LICENSE_NAME=	Common Public License, Version 1.0
LICENSE_FILE=	${WRKSRC}/CoinMP/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# note: with ogdf only if build with COIN option
CONFLICTS=	clp-[0-9]* ogdf-[0-9]*

GNU_CONFIGURE=	yes
USES=	libtool pathfix pkgconfig tar:tgz
USE_LDCONFIG=	yes
CXXFLAGS+=	-ffast-math

OPTIONS_DEFINE=	DEBUG DOCS FORTRAN GLPK PARALLEL

FORTRAN_DESC=	Use BLAS/LAPACK with the Fortran interface
GLPK_DESC=	GNU Linear Programming Kit support
PARALLEL_DESC=	Enable CBC threads support

PORTDOCS=	*

DEBUG_CXXFLAGS=		-fomit-frame-pointer

FORTRAN_USES=		fortran blaslapack
FORTRAN_CONFIGURE_ON=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib" \
			--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib"

GLPK_LIB_DEPENDS=	libglpk.so:math/glpk
GLPK_CONFIGURE_ON=	--with-gmpl-incdir=${LOCALBASE}/include	\
			--with-gmpl-lib="-L${LOCALBASE}/lib -lglpk"
GLPK_CONFIGURE_OFF=	--disable-glpk-libcheck

PARALLEL_CONFIGURE_ON=	--enable-cbc-parallel

INSTALL_TARGET=	install-strip
TEST_TARGET=	unitTest
TEST_WRKSRC=	${WRKSRC}/${PORTNAME}

post-patch::
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e 's|$$(DESTDIR)$$(addlibsdir)|$$(addlibsdir)|g' \
		-e 's|addlibs_DATA = examples/Makefile examples/example.c||g' \
		-e 's|DocInstallDir = $$(datadir)/coin/doc/$$(PACKAGE_NAME)|DocInstallDir = $$(datadir)/doc/CoinMP/$$(PACKAGE_NAME)|' \
		-e 's|	$$(MAKE) $$(AM_MAKEFLAGS) install-data-hook||'
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} \
		-e 's|void exit (int)|void reserved (int)|g'
	${REINPLACE_CMD} -e 's|datacoin_DATA = $$(EXAMPLE_FILES)|datacoin_DATA = |' \
		-e 's|datacoindir = $$(datadir)/coin/Data/Sample|datacoindir = |' ${WRKSRC}/Data/Sample/Makefile.in
	${REINPLACE_CMD} -e 's|addlibsdir = $$(DESTDIR)$$(datadir)/coin/doc/CoinMP|addlibsdir = |' ${WRKSRC}/CoinMP/Makefile.in

.include <bsd.port.mk>
