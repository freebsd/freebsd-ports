# New ports collection makefile for:   CoinMP
# Date created:        22 June 2011
# Whom:                Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	CoinMP
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/CoinMP/
EXTRACT_SUFX=	.tgz

MAINTAINER=	giffunip@tutopia.com
COMMENT=	Optimization library with support for most of COIN-OR CLP, CBC, and CGL

LICENSE=	CPL
LICENSE_NAME=	Common Public License, Version 1.0
LICENSE_FILE=	${WRKSRC}/CoinMP/LICENSE
LICENSE_PERMS=	auto-accept

CONFLICTS=	clp-[0-9]*

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.ifdef WITH_GLPK
BROKEN =	the GLPK option requires math/glpk headers that are not currently installed by that port
CONFIGURE_ARGS+=	--with-gmpl-incdir=${LOCALBASE}/include	\
		--with-gmpl-lib="-L${LOCALBASE}/lib -lglpk"
LIB_DEPENDS+=	glpk:${PORTSDIR}/math/glpk
.else
CONFIGURE_ARGS+=	--disable-glpk-libcheck
.endif

CXXFLAGS+=	-ffast-math
.ifndef WITH_DEBUG
CXXFLAGS+=	-fomit-frame-pointer
.endif

post-patch::
	@${REINPLACE_CMD} -E -e \
		's:\$$\(libdir\)/pkgconfig:${PREFIX}/libdata/pkgconfig:' \
		${WRKSRC}/Clp/Makefile.in ${WRKSRC}/Osi/Makefile.in \
		${WRKSRC}/Cbc/Makefile.in ${WRKSRC}/Cgl/Makefile.in \
		${WRKSRC}/CoinUtils/Makefile.in ${WRKSRC}/CoinMP/Makefile.in

pre-build:
.for dir in Cbc Cgl Clp CoinMP CoinUtils Osi
	${CP} ${LTMAIN} ${WRKSRC}/${dir}
.endfor

post-install:
.ifndef NOPORTDOCS
	${MV} ${PREFIX}/share/coin/doc ${DOCSDIR}
.endif
	${RM} -rf ${PREFIX}/share/coin

check regression-test test: build
	@(cd ${WRKSRC};  ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} test)

.include <bsd.port.post.mk>
