# $FreeBSD$

PORTNAME=	wannier90
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Maximally-localized Wannier functions (MLWFs) and Wannier90

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		fortran gmake
USE_GITHUB=	yes
GH_ACCOUNT=	wannier-developers
USE_LDCONFIG=	yes

MAKE_ARGS=	FCOPTS="-fPIC -O3"

PLIST_FILES=	bin/postw90.x \
		bin/w90chk2chk.x \
		bin/wannier90.x \
		lib/libwannier.so

post-patch:
	@${REINPLACE_CMD} 's|F90 = gfortran|&${GCC_DEFAULT}|' ${WRKSRC}/config/make.inc.gfort
	@${RLN} ${WRKSRC}/config/make.inc.gfort ${WRKSRC}/make.inc

do-install:
.for p in wannier90.x postw90.x w90chk2chk.x
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${STAGEDIR}${PREFIX}/bin/${p}
.endfor
	${INSTALL_LIB} ${WRKSRC}/src/obj/libwannier.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
