PORTNAME=	miss3d
PORTVERSION=	6.7
DISTVERSIONSUFFIX=	_aster7
CATEGORIES=	science

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Numerical tool for wave propagation problems
WWW=		https://code-aster.org/spip.php?article275

LICENSE=	CeCILL-C
LICENSE_NAME=	CeCILL-C
LICENSE_TEXT=	MISS3D is released under the open-source license CeCILL-C
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	ctest:devel/cmake-core

USES=		blaslapack:openblas fortran gmake localbase:ldflags python shebangfix
SHEBANG_FILES=	./src/run_miss3d ./scripts/run_miss3d_test ./scripts/run_miss3d

DVSFX=		${DISTVERSIONSUFFIX}
_TARNAME=	${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}
TAGNAME=	2de18b0dae166831c3ebed48b23931cc8ab70526

WRKSRC=		${WRKDIR}/${_TARNAME}-${TAGNAME}
FFLAGS+=	-fallow-argument-mismatch
MAKE_ENV+=	prefix=${STAGEDIR}${PREFIX} testdir=${STAGEDIR}${DATADIR}	\
		versdir=${STAGEDIR}${PREFIX}/lib
TESTING_UNSAFE=	yes	# Some files are missing
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

LIB2STRIP=	gtaster miss3d ptaster

pre-build:
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|'	\
		${WRKSRC}/scripts/run_miss3d_test
	${ECHO_CMD} "F90 = ${F90}" > ${WRKSRC}/src/Makefile.inc
	${ECHO_CMD} "F90FLAGS = ${FFLAGS} -fbacktrace -mcmodel=medium -fopenmp -pthread \\"	\
		>> ${WRKSRC}/src/Makefile.inc
	${ECHO_CMD} "		-fdefault-double-8 -fdefault-integer-8 -fdefault-real-8"	\
		>> ${WRKSRC}/src/Makefile.inc
	${ECHO_CMD} "LD = ${FC}" >> ${WRKSRC}/src/Makefile.inc
	${ECHO_CMD} "LDFLAGS = ${LDFLAGS} -lopenblas -fopenmp -pthread"	\
		>> ${WRKSRC}/src/Makefile.inc

post-stage-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install:
.for l in ${LIB2STRIP}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${l}.x
.endfor

do-test:	install
	(cd ${WRKSRC}/test && MISS_ROOT=${PREFIX}/lib ctest)

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
