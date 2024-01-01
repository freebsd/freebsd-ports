PORTNAME=	wannier90
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Maximally-localized Wannier functions (MLWFs) and Wannier90
WWW=		http://www.wannier.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		blaslapack:netlib fortran gmake python:test shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	wannier-developers
SHEBANG_FILES=	test-suite/run_tests test-suite/clean_tests	\
		test-suite/tools/fprettify-wrapper.py	\
		test-suite/testcode/bin/testcode.py	\
		test-suite/library-mode-test/compare_results.py	\
		utility/k_mapper.py utility/gw2wannier90.py
USE_LDCONFIG=	yes

MAKE_ARGS=	FCOPTS="-fPIC -O3"

TEST_TARGET=	tests # most tests using --numprocs=4 fail: https://github.com/wannier-developers/wannier90/issues/351

PLIST_FILES=	bin/postw90.x \
		bin/w90chk2chk.x \
		bin/wannier90.x \
		lib/libwannier.so \
		lib/libwannier.so.0

post-patch:
	@${REINPLACE_CMD} 's|F90 = gfortran|&${GCC_DEFAULT}|' ${WRKSRC}/config/make.inc.gfort
	@${RLN} ${WRKSRC}/config/make.inc.gfort ${WRKSRC}/make.inc
	@${REINPLACE_CMD} 's|make|${GMAKE}|' ${WRKSRC}/test-suite/run_tests

do-install:
.for p in wannier90.x postw90.x w90chk2chk.x
	${INSTALL_PROGRAM} ${WRKSRC}/${p} ${STAGEDIR}${PREFIX}/bin/${p}
.endfor
	${INSTALL_LIB} ${WRKSRC}/src/obj/libwannier.so ${STAGEDIR}${PREFIX}/lib/libwannier.so.0
	${LN} -sf libwannier.so.0 ${STAGEDIR}${PREFIX}/lib/libwannier.so

.include <bsd.port.mk>
