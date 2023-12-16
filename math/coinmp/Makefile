PORTNAME=	CoinMP
DISTVERSIONPREFIX=	releases/
DISTVERSION=	1.8.4
PORTREVISION=	10
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimization library with support for COIN-OR CLP, CBC, and CGL
WWW=		https://projects.coin-or.org/CoinMP

LICENSE=	CPL
LICENSE_NAME=	Common Public License, Version 1.0
LICENSE_FILE=	${WRKSRC}/CoinMP/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libblas.so:math/blas \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/coin-or-mumps \
		libCoinUtils.so:math/coinutils \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi

USES=		compiler:c++11-lang libtool pathfix pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
GH_PROJECT=	CoinMP

GNU_CONFIGURE=	yes

CXXFLAGS+=	-ffast-math

PLIST_FILES=	include/coin/CoinMP.h \
		include/coin/CoinMPConfig.h \
		lib/libCoinMP.so \
		lib/libCoinMP.so.1 \
		lib/libCoinMP.so.1.8.4 \
		libdata/pkgconfig/coinmp.pc

OPTIONS_DEFINE=	DOCS FORTRAN GLPK

FORTRAN_DESC=	Use BLAS/LAPACK with the Fortran interface
GLPK_DESC=	GNU Linear Programming Kit support

PORTDOCS=	*

FORTRAN_USES=		fortran blaslapack
FORTRAN_CONFIGURE_ON=	--with-lapack-lib="${LAPACKLIB} -L${LOCALBASE}/lib" \
			--with-blas-lib="${BLASLIB} -L${LOCALBASE}/lib"

GLPK_LIB_DEPENDS=	libglpk.so:math/glpk
GLPK_CONFIGURE_ON=	--with-gmpl-incdir=${LOCALBASE}/include	\
			--with-gmpl-lib="-L${LOCALBASE}/lib -lglpk"
GLPK_CONFIGURE_OFF=	--disable-glpk-libcheck

INSTALL_TARGET=	install-strip

TEST_TARGET=	unitTest

post-patch::
	@${REINPLACE_CMD} \
		-e 's|$$(DESTDIR)$$(addlibsdir)|$$(addlibsdir)|g' \
		-e 's|addlibs_DATA = examples/Makefile examples/example.c||g' \
		-e 's|DocInstallDir = $$(datadir)/coin/doc/$$(PACKAGE_NAME)|DocInstallDir = $$(datadir)/doc/CoinMP/$$(PACKAGE_NAME)|' \
		-e 's|	$$(MAKE) $$(AM_MAKEFLAGS) install-data-hook||' \
		${WRKSRC}/Makefile.in ${WRKSRC}/CoinMP/Makefile.in
	@${REINPLACE_CMD} -e 's|addlibsdir = $$(DESTDIR)$$(datadir)/coin/doc/CoinMP|addlibsdir = |' ${WRKSRC}/CoinMP/Makefile.in

.include <bsd.port.mk>
